// testCall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <osip2/osip_mt.h>
#include <eXosip2/eXosip.h>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	eXosip_event_t *je;
	osip_message_t *reg = NULL;
	osip_message_t *invite = NULL;
	osip_message_t *ack = NULL;
	osip_message_t *info = NULL;
	osip_message_t *message = NULL;
	int call_id, dialog_id;
	int i,flag;
	int flag1 = 1;
	int id;

	string strIdentity = "sip:136@133.37.55.136";
	string strRegisterer = "sip:133.37.55.136:5060"; // server ip

	string strSrcCall = "sip:uac@192.168.2.100";
	string strDestCall = "sip:2809099@ineen.com"; // server ip


	char *result;
	size_t length;

	char command;
	char tmp[4096];
	char localip[128];
	string inputStr;
	string strHelp = string("\n\t--> 命令字符 功能描述 <--\n\n")
		+ "\t\tr 向服务器注册\n"
		+ "\t\tc 取消注册\n"
		+ "\t\ti 发起呼叫请求\n"
		+ "\t\th 挂断\n"
		+ "\t\tq 退出程序\n"
		+ "\t\ts 执行方法 INFO\n"
		+ "\t\tm 执行方法 MESSAGE\n"
		+ "\t\te 帮助\n\n";
	cout << strHelp;

	string strMsg;

	i = eXosip_init ();
	if (i != 0)
	{
		cout << "\t--> Couldn't initialize eXosip! <--\n";
		return -1;
	}
	else
	{
		cout << "\t--> eXosip_init successfully! <-- \n\n";
	}

	i = eXosip_listen_addr (IPPROTO_UDP, NULL, 0, AF_INET, 0);

	if (i != 0)
	{
		eXosip_quit ();
		cerr << "\n\t--> Couldn't initialize transport layer! <-- \n\n";
		return -1;
	}
	flag = 1;
	while (flag)
	{
		cout << "请输入一个命令字符：\t";
		cin >> command;

		switch (command)
		{
		case 'r':
			cout << "\n\t--> This modal isn't commpleted! \n" << endl;
			break;

		case 'i': // 初始化的 INVITE 请求

			cout<< "input sip : ";
			cin>> inputStr;
			i = eXosip_call_build_initial_invite (&invite,
				inputStr.c_str(),
				strSrcCall.c_str(),
				NULL,
				"This is a call for a conversation");
			if (i != 0)
			{
				cout << "\n --> Intial INVITE failed! <-- \n";
				break;
			}
			
			// 符合 SDP 格式, 其中属性 a 是自定义格式,也就是说可以存放自己的信息, 
			// 但是只能是两列,比如帐户信息
			// 但是经测试,格式: v o t必不可少,原因未知,估计是协议栈在传输时需要检查的

			strMsg = string("v=0\r\n")
				+ "o=anonymous 0 0 IN IP4 0.0.0.0\r\n"
				+ "t=1 10\r\n"
				+ "a=username:bluesea\r\n"
				+ "a=password:123456\r\n";

			osip_message_set_body (invite, strMsg.c_str(), strMsg.length());
			osip_message_set_content_type (invite, "application/sdp");


			osip_message_to_str(invite,&result,&length);

			osip_free (result);

			// 这里使用了锁机制以保证同步
			eXosip_lock ();
			i = eXosip_call_send_initial_invite (invite);
			eXosip_unlock ();
			flag1 = 1;
			while (flag1)
			{
				je = eXosip_event_wait (0, 200);
				if (je == NULL)
				{
				//	cout << "\n\t--> No response or the time is over! <--\n" << endl;
					continue;
				}

				switch (je->type)
				{
				case EXOSIP_CALL_INVITE:
					cout << "\n\t--> a new invite reveived! <--\n" << endl;
					break;

					// announce processing by a remote app
				case EXOSIP_CALL_PROCEEDING:
					cout << "\n\t--> proceeding! <--\n" << endl;
					break;

					// announce ringback
				case EXOSIP_CALL_RINGING:
					cout << "\n\t--> ringing! <--\n"
						<< "\n\tcall_id is " << je->cid
						<< ", dialog_id is " << je->did << endl;
					break;

					// 收到请求，表示连接成功，下面发送回复确认
				case EXOSIP_CALL_ANSWERED:
					cout << "\n\t--> ok! connected! <--\n" << endl;
					call_id = je->cid;
					dialog_id = je->did;
					cout << "\n\tcall_id is " << je->cid
						<< ", dialog_id is " << je->did << endl;
					eXosip_call_build_ack (je->did, &ack);
					eXosip_call_send_ack (je->did, ack);
					flag1 = 0;
					break;

				case EXOSIP_CALL_CLOSED:
					cout << "\n\t--> the other sid closed! <--\n" << endl;
					break;

				case EXOSIP_CALL_ACK:
					cout << "\n\t--> ACK received! <--\n" << endl;
					break;

				default:
					cout << "\n\t--> other response!\n" <<endl;
					flag1 = false;
					break;
				}

				eXosip_event_free (je);
			}

			break;

		case 'h':
			cout << "\n\t--> Holded ! \n" << endl;

			eXosip_lock ();
			eXosip_call_terminate (call_id, dialog_id);
			eXosip_unlock ();
			break;

		case 'c':
			cout << "\n\t--> This modal isn't commpleted! \n" << endl;
			break;

		case 's':
			// 传输 INFO 方法
			eXosip_call_build_info (dialog_id, &info);

			snprintf (tmp , 4096, "hello,bluesea");
			osip_message_set_body (info, tmp, strlen(tmp));

			// 格式可以任意设定, text/plain 代表文本信息
			osip_message_set_content_type (info, "text/plain");
			eXosip_call_send_request (dialog_id, info);
			break;

		case 'm':
			// 传输 MESSAGE方法,也就是即时消息，
			// 和 INFO 方法相比，主要区别，是 MESSAGE 不用建立连接，直接传输信息，
			// 而 INFO 必须在建立 INVITE 的基础上传输。
			cout << "\n\t--> the mothed :MESSAGE \n" << endl;
			eXosip_message_build_request (&message,
				"MESSAGE",
				strDestCall.c_str(),
				strSrcCall.c_str(),
				NULL);
			strMsg = "message: hello bluesea!";
			osip_message_set_body (message, strMsg.c_str(), strMsg.length());

			// 假设格式是xml
			osip_message_set_content_type (message, "text/xml");
			eXosip_message_send_request (message);
			break;

		case 'q':
			eXosip_quit ();
			cout << "\n\t--> Exit the setup! \n" << endl;;
			flag = 0;
			break;

		case 'e':
			cout << strHelp << endl;
			break;

		default:
			cout << "\n\t--> 不支持的命令 <--\n" << endl;
			break;
		}
	}

	return 0;
}