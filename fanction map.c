#include<stdlib.h>
#include<stdio.h>
/*�� ������� ������ �� ��� gets
 ��� ����� �� ����� - �� ����� �� �� ����� ����� ���� ��� "-"
*100 ���� ����� ���� ����� 
���� ������� ���� �����  100 
50 ���� ������� ���� �����
��� ������� ������� ����� - �� ����� ����� ��� ������ �� ����� ��� ���� 
������ ���� ���� ������ �'�� - ����� �� 1 ����� �� 2 ����� �� 3 - ������� ����� ������ ������� �����
*/
enum = { true = 0,false = 1 }flag;

flag id_input_validity(char id[]); //tair V

flag passpword_input_validity(char password[]); //tair V

flag fulname_input_validity(char fulname[]); //tair V

flag phonenum_input_validity(char phonenum[]); //reut V

flag education_input_validity(char education[]);//reut V

flag exeperience_input_validity(char exeperience[]); //reut V

flag companyname_input_validity(char companyname[]); //adi ?? if not so tair

flag company_description_input_validity(char description[]); //adi ?? if not so tair

flag jobname_input_validity(char jobname[]); //tair need to do this

flag job_description_input_validity(char description[]); //adi - if not so tair

flag job_requirement_input_validity(char requirement[]); //adi - someone need to copy paste if not so tair

void user_main_menu() //tair

void new_user_menu()//tair

void exist_user_menu()//tair

void main_candidate_menu(); //����� �� ���� ����� //reut  V

void main_employer_menu(); //����� �� ���� ����� //adi

void candidate_profile(Candidate* candidate); //reut V

void employer_profile(Employer* employer);//adi

void menu_edit_c_profile(); //����� ����� ������ ����� //reut V

void menu_edit_e_profile();//����� ����� ������ ����� //adi

void present_candidate_history_4(Candidate candidate);//����� ��� �� ������ �� ������ ��� ���� ��� ��� candidate ����� ��� ����� ����� �� ������// shirel 
void printalljobs(); //shirel

void apply();//shirel

void filterjobs_5_2();//shirel

void menuforfilterjobs_5_2_1();//shirel

void filter_by_area_5_2_2();//shirel

void filter_jobs_by_profession_5_2_3();//shirel

void filter_jobs_by_scope_5_2_4(); //shirel

void filter_by_job_experience_5_2_5();//shirel

void printemployerjobs();//adi

void print_current_jobs(&jobarray[i]); //����� ���� ���//������ ��� ������ �� ����� ������� , ���� ���� �� ������//shirel

void edit_job_menu();//adi ?? if not so reut 

void delete_job();// reut need to do V

void viewing_candidate_profile();//����� ������ ����� -����� �������� ����� ������( ���� 26)  // reut

void post_new_job();//adi needs to do

void restore_job();//tair needs to do 

void logingout_5_4() //shirel













