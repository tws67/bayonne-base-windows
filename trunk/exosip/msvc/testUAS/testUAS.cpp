// testUAS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <eXosip2/eXosip.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	eXosip_event_t *je = NULL;
	osip_message_t *ack = NULL;
	osip_message_t *invite = NULL;
	osip_message_t *answer = NULL;
	sdp_message_t *remote_sdp = NULL;
	int call_id, dialog_id;
	int i,j;
	int id;

	char *sour_call = "sip:136@133.37.55.136";
	char *dest_call = "sip:136@133.37.55.136:5061"; //client ip/port

	char command;
	char tmp[4096];
	char localip[128];
	int pos = 0;
	char *result;
	size_t length;
	// 初始化 sip
	i = eXosip_init ();
	if (i != 0)
	{
		cerr << "\n\t--> Can't initialize eXosip!\n";
		return -1;
	}
	else
	{
		cout << "\n\t--> eXosip_init successfully!\n";
	}

	i = eXosip_listen_addr (IPPROTO_UDP, NULL, 5060, AF_INET, 0);
	if (i != 0)
	{
		eXosip_quit ();
		cerr << "\n\t--> eXosip_listen_addr error! Couldn't initialize transport layer!\n";
	}
	for(;;)
	{
		// 侦听是否有消息到来
		je = eXosip_event_wait (0, 50);

		// 协议栈带有此语句,具体作用未知
		eXosip_lock ();
		eXosip_default_action (je);
		eXosip_automatic_refresh ();
		eXosip_unlock ();

		if (je == NULL) // 没有接收到消息，继续
		{
			continue;
		}

		switch (je->type)
		{
		case EXOSIP_MESSAGE_NEW: // 新的消息到来
			cout << "\n\t*** EXOSIP_MESSAGE_NEW!\n" << endl;

			if (MSG_IS_MESSAGE (je->request)) // 如果接收到的消息类型是 MESSAGE
			{
				{
					osip_body_t *body;
					osip_message_get_body (je->request, 0, &body);
					cout << "I get the msg is: " << body->body << endl;
				}

				// 按照规则，需要回复 OK 信息
				eXosip_message_build_answer (je->tid, 200, &answer);
				eXosip_message_send_answer (je->tid, 200, answer);
			}
			break;

		case EXOSIP_CALL_INVITE: // INVITE 请求消息
			// 得到接收到消息的具体信息
			cout << "=========================INVITE==================="<<endl;
			osip_message_to_str(je->request,&result,&length);

			cout << result << endl;

			osip_free(result);
			// 得到消息体,认为该消息就是 SDP 格式.
			remote_sdp = eXosip_get_remote_sdp (je->did);
			call_id = je->cid;
			dialog_id = je->did;

			eXosip_lock ();
			cout << "\n\tcall_id is " << je->cid
				<< ", dialog_id is " << je->did << endl;

			eXosip_call_send_answer (je->tid, 180, NULL);
			i = eXosip_call_build_answer (je->tid, 200, &answer);
			if (i != 0)
			{
				cout << "\n\t--> This request msg is invalid! Cann't response!\n" << endl;
				eXosip_call_send_answer (je->tid, 400, NULL);
			}
			else
			{
				snprintf (tmp, 4096,
					"v=0\r\n"
					"o=anonymous 0 0 IN IP4 0.0.0.0\r\n"
					"t=1 10\r\n"
					"a=username:rainfish\r\n"
					"a=password:123\r\n");

				// 设置回复的SDP消息体,下一步计划分析消息体
				// 没有分析消息体，直接回复原来的消息，这一块做的不好。
				osip_message_set_body (answer, tmp, strlen(tmp));
				osip_message_set_content_type (answer, "application/sdp");

				eXosip_call_send_answer (je->tid, 200, answer);
				cout << "\n\t--> send 200 over!" << endl;
			}

			eXosip_unlock ();

			// 显示出在 sdp 消息体中的 attribute 的内容,里面计划存放我们的信息
			cout << "\n\t--> The INFO is :\n" ;
			while (!osip_list_eol ( &(remote_sdp->a_attributes), pos))
			{
				sdp_attribute_t *at;

				//这里解释了为什么在SDP消息体中属性a里面存放必须是两列
				at = (sdp_attribute_t *) osip_list_get ( &remote_sdp->a_attributes, pos);
				cout << "\n\t" << at->a_att_field
					<< " : " << at->a_att_value << endl;

				pos ++;
			}
			break;

		case EXOSIP_CALL_ACK:
			cout << "\n\t--> ACK recieved!\n" << endl;
			// printf ("the cid is %s, did is %s\n", je->did, je->cid); 
			break;

		case EXOSIP_CALL_CLOSED:
			cout << "\n\t--> the remote hold the session!\n" << endl;
			// eXosip_call_build_ack(dialog_id, &ack);
			// eXosip_call_send_ack(dialog_id, ack); 
			i = eXosip_call_build_answer (je->tid, 200, &answer);
			if (i != 0)
			{
				printf ("This request msg is invalid!Cann't response!\n");
				eXosip_call_send_answer (je->tid, 400, NULL);
			}
			else
			{
				eXosip_call_send_answer (je->tid, 200, answer);
				cout << "\n\t--> bye send 200 over!\n";
			}
			break;

		case EXOSIP_CALL_MESSAGE_NEW:

			cout << "\n\t*** EXOSIP_CALL_MESSAGE_NEW\n" << endl;
			if (MSG_IS_INFO(je->request) ) // 如果传输的是 INFO 方法
			{
				eXosip_lock ();
				i = eXosip_call_build_answer (je->tid, 200, &answer);
				if (i == 0)
				{
					eXosip_call_send_answer (je->tid, 200, answer);
				}

				eXosip_unlock ();

				{
					osip_body_t *body;
					osip_message_get_body (je->request, 0, &body);
					cout << "the body is " << body->body << endl;
				}
			}
			break;

		default:
			cout << "\n\t--> Could not parse the msg!\n" << endl;
		}
		eXosip_event_free(je);
	}

	return 0;
}