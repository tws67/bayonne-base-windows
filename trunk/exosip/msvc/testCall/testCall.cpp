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
	string strHelp = string("\n\t--> �����ַ� �������� <--\n\n")
		+ "\t\tr �������ע��\n"
		+ "\t\tc ȡ��ע��\n"
		+ "\t\ti �����������\n"
		+ "\t\th �Ҷ�\n"
		+ "\t\tq �˳�����\n"
		+ "\t\ts ִ�з��� INFO\n"
		+ "\t\tm ִ�з��� MESSAGE\n"
		+ "\t\te ����\n\n";
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
		cout << "������һ�������ַ���\t";
		cin >> command;

		switch (command)
		{
		case 'r':
			cout << "\n\t--> This modal isn't commpleted! \n" << endl;
			break;

		case 'i': // ��ʼ���� INVITE ����

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
			
			// ���� SDP ��ʽ, �������� a ���Զ����ʽ,Ҳ����˵���Դ���Լ�����Ϣ, 
			// ����ֻ��������,�����ʻ���Ϣ
			// ���Ǿ�����,��ʽ: v o t�ز�����,ԭ��δ֪,������Э��ջ�ڴ���ʱ��Ҫ����

			strMsg = string("v=0\r\n")
				+ "o=anonymous 0 0 IN IP4 0.0.0.0\r\n"
				+ "t=1 10\r\n"
				+ "a=username:bluesea\r\n"
				+ "a=password:123456\r\n";

			osip_message_set_body (invite, strMsg.c_str(), strMsg.length());
			osip_message_set_content_type (invite, "application/sdp");


			osip_message_to_str(invite,&result,&length);

			osip_free (result);

			// ����ʹ�����������Ա�֤ͬ��
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

					// �յ����󣬱�ʾ���ӳɹ������淢�ͻظ�ȷ��
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
			// ���� INFO ����
			eXosip_call_build_info (dialog_id, &info);

			snprintf (tmp , 4096, "hello,bluesea");
			osip_message_set_body (info, tmp, strlen(tmp));

			// ��ʽ���������趨, text/plain �����ı���Ϣ
			osip_message_set_content_type (info, "text/plain");
			eXosip_call_send_request (dialog_id, info);
			break;

		case 'm':
			// ���� MESSAGE����,Ҳ���Ǽ�ʱ��Ϣ��
			// �� INFO ������ȣ���Ҫ������ MESSAGE ���ý������ӣ�ֱ�Ӵ�����Ϣ��
			// �� INFO �����ڽ��� INVITE �Ļ����ϴ��䡣
			cout << "\n\t--> the mothed :MESSAGE \n" << endl;
			eXosip_message_build_request (&message,
				"MESSAGE",
				strDestCall.c_str(),
				strSrcCall.c_str(),
				NULL);
			strMsg = "message: hello bluesea!";
			osip_message_set_body (message, strMsg.c_str(), strMsg.length());

			// �����ʽ��xml
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
			cout << "\n\t--> ��֧�ֵ����� <--\n" << endl;
			break;
		}
	}

	return 0;
}