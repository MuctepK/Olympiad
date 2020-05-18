#include <iostream>
using namespace std;
int c=0, N;
void mixed(const string& s, int op_r_br, int cl_r_br, int op_s_br, int cl_s_br, string st){
    if ((op_r_br+cl_r_br+op_s_br+cl_s_br)==N*2) {
        printf("%s\n", s.c_str());
    }

    if (op_r_br+op_s_br<N){
        st.push_back('(');
        mixed(s+'(', op_r_br+1, cl_r_br, op_s_br, cl_s_br, st);
        st.pop_back();
    }
    if (st.back()=='('){
        st.pop_back();
        mixed(s+')', op_r_br, cl_r_br+1, op_s_br, cl_s_br, st);
        st.push_back('(');
    }

    if (op_s_br+op_r_br<N){
        st.push_back('[');
        mixed(s+'[', op_r_br, cl_r_br, op_s_br+1, cl_s_br, st);
        st.pop_back();
    }
    if (st.back()=='['){
        st.pop_back();
        mixed(s+']', op_r_br, cl_r_br, op_s_br, cl_s_br+1,st);
        st.push_back('[');
    }

}
int main(){
    cin >> N;
    N/=2;
    mixed("",0,0,0,0, "");
}

