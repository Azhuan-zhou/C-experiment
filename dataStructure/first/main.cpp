#include "Linklist.cpp"

int main()
{
    LList<int> L;
    L.append(2);
    L.append(23);
    L.append(15);
    L.append(5);
    L.append(9);
    int a;
    // ?????????????
    cout<<"ɾ��ǰ������"<<endl;
    for(int i= 0;i<L.length();i++)
    {
        L.moveToPos(i);
        cout<<L.getValue()<<' ';
    }
    cout<<endl;
    for(int i= 0;i<L.length();i++)
    {
        L.moveToPos(i);
        a = L.getValue();
        if(a==15)
        {
            cout<<"Ҫɾ����Ԫ��"<<L.remove()<<endl;
            break;
        }
    }
    cout<<"ɾ��Ԫ�غ������"<<endl;
    for(int i= 0;i<L.length();i++)
    {
        L.moveToPos(i);
        cout<<L.getValue()<<' ';
    }

}
//int main()
//{
//  AStack<int>s;
//  int a;
//  cout<<"?????????????????????????��?????????";
//  cin>>a;
//  if(a==1||a==2)
//  {
//      cout<<"????????"<<1;
//  .   exit(1);
//  }
//  s.push(1);
//  s.push(1);
//  int m,n,result;
//  for(inti=3;i<=a;++i)
//  {
//      m=s.pop();//?????????
//      n=s.pop();
//      s.push(m);
//      s.push(m+n);
//  }
//   cout<<"??????:"<<s.topValue();
// }

//int main()
//
//   int a;
//   AQueue<int> q;
//   AStack<int> s;
//   cout<<"????????��?????0???????: ";
//   while(true)
//   {
//       cin >> a;
//       if (a==0)
//       {
//           break;
//       }
//       else
//       {
//           q.enqueue(a);
//       }
//   }
//   int l = q.length();
//   int x;
//   for (int i = 0; i < l; ++i) {
//       x = q.dequeue();
//       s.push(x);
//   }
//   for (int i = 0; i < l; ++i) {
//       x = s.pop();
//       q.enqueue(x);
//   }
//   cout<<"??��????��? ";
//   for (int i = 0; i < l; ++i) {
//       cout<<q.dequeue()<<' ';
//   }
//}
