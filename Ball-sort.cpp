#include <bits/stdc++.h>

using namespace std;

class ball_sort{
    vector<stack<char>> tubes;
    stack <char> temp;
    char arr[4] = {'R','G','B'};
public:
       ball_sort(){
           stack<char>tube;
           for(int i = 0; i < 4; i++){
            tubes.push_back(tube);
           }
       }

       void random_colors(char color){
           int random_index;
           srand(time(0));
           int counter = 4;
           while(counter != 0){
               random_index = rand() % 3 + 1;
               if(random_index == 1 && tubes[0].size() < 4){
                    tubes[0].push(color);
                    counter --;
               }
               else if(random_index == 2 && tubes[1].size() < 4){
                    tubes[1].push(color);
                    counter --;
               }
               else if(random_index == 3 && tubes[2].size() < 4){
                    tubes[2].push(color);
                    counter --;
               }
           }
        }

        void print(stack<char> tube){
            int s = tube.size();
            if(s == 0){
                for(int i = 0; i < 4; i++)
                    cout<<'|'<<' '<<'|'<<endl;
                return;
            }
            for(int j = 0; j < 4 - s; j++)
                cout<<'|'<<' '<<'|'<<endl;
            for(int j = 0; j < s; j++){
                cout<<'|'<<tube.top()<<'|'<<endl;
                tube.pop();
            }
        }

        void print(){
            print(tubes[0]);
            cout<<endl;
            print(tubes[1]);
            cout<<endl;
            print(tubes[2]);
            cout<<endl;
            print(tubes[3]);
            cout<<endl;
        }

        bool check_input(int i, int j){
            if(i < 0 || j < 0 || i > 3 || j > 3)
                return false;
            return true;
        }

        void play(){
            int i,j;
            cout<<"Index of two tubes:"<<endl;
            cin>>i>>j;
            while(!check_input(i,j)){
                cout<<"Invalid input"<<endl;
                cout<<"Index of two tubes:"<<endl;
                cin>>i>>j;
            }
            if((tubes[i].top() == tubes[j].top() || tubes[j].size() == 0) && tubes[j].size() < 4){
                tubes[j].push(tubes[i].top());
                tubes[i].pop();
            }
            else
            {
                cout<<"Invalid move"<<endl;
                play();
            }
        }

        bool check_win(stack<char> tube){
            for(int i = 0; i < 3; i++){
                temp.push(tube.top());
                tube.pop();
                if(temp.top() != tube.top())
                    return false;
            }
            return true;
        }

        bool check_win(){
            int counter = 0;
            for(int i = 0; i < 4; i++){
                if(check_win(tubes[i])){
                    counter ++;
                }
            }
            if(counter == 3)
                return true;
            return false;
        }
};
int main()
{
    ball_sort obj;
    obj.random_colors('R');
    obj.random_colors('B');
    obj.random_colors('G');
    obj.print();
    while(!obj.check_win()){
        obj.play();
        obj.print();
    }
    cout<<"You win :)"<<endl;
}
