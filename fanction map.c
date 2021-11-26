#include<stdlib.h>
#include<stdio.h>
/*כל הקליטות יתבצעו על ידי gets
 בכל קליטה של סטרקט - יש לאתחל את כל השדות ברירת מחדל לתו "-"
*100 מערך משרות יהיה בגודל 
מערך מועמדים יהיה בגודל  100 
50 מערך מעסיקים יהיה בגודל
בכל םונקציה שמדפיסה משרות - יש לבדוק כתנאי האם הסטטוס של המשרה הוא זמין 
להוסיף שלוש שדות לסטרקט ג'וב - מועמד מס 1 מועמד מס 2 מועמד מס 3 - להתייחס אליהם בקליטה ובקריאה לקובץ
*/
enum = { true = 0,false = 1 }flag;

flag id_input_validity(char id[]); //tair

flag passpword_input_validity(char password[]); //tair

flag fulname_input_validity(char fulname[]); //tair

flag phonenum_input_validity(char phonenum[]); //reut

flag education_input_validity(char education[]);//reut

flag exeperience_input_validity(char exeperience[]); //reut

flag companyname_input_validity(char companyname[]); //adi ?? if not so tair

flag company_description_input_validity(char description[]); //adi ?? if not so tair

flag jobname_input_validity(char jobname[]); //tair need to do this

flag job_description_input_validity(char description[]); //adi - if not so tair

flag job_requirement_input_validity(char requirement[]); //adi - someone need to copy paste if not so tair

void user_main_menu() //tair

void new_user_menu()//tair

void exist_user_menu()//tair

void main_candidate_menu(); //תפריט דף הבית מועמד //reut

void main_employer_menu(); //תפריט דף הבית מעסיק //adi

void print_candidate_profile(Candidate.id); //שולחים לפונ זו את המצביע במערך לסטרקט //reut

void print_employer_profile(Employer); //adi

void menu_for_edit_c_profile(); //תפריט עריכת פרופיל מועמד //reut

void menu_for_edit_e_profile();//תפריט עריכת פרופיל מעסיק //adi

void present_candidate_history_4(Candidate candidate);//מחפשת בין כל המבנים של המשרות האם קיים שדה בשם candidate שערכו הוא תעודת הזהות של המועמד// shirel 
void printalljobs(); //shirel

void apply();//shirel

void filterjobs_5_2();//shirel

void menuforfilterjobs_5_2_1();//shirel

void filter_by_area_5_2_2();//shirel

void filter_jobs_by_profession_5_2_3();//shirel

void filter_jobs_by_scope_5_2_4(); //shirel

void filter_by_job_experience_5_2_5();//shirel

void printemployerjobs();//adi

void print_current_jobs(&jobarray[i]); //הדפסת משרה אחת//הפרמטר הוא הכתובת של המשרה הנוכחית , מתוך מערך כל המשרות//shirel

void edit_job_menu();//adi ?? if not so reut

void delete_job();// reut need to do

void viewing_candidate_profile();//הדפסת פרופיל מועמד -קוראת לפונקצית הדפסת פרופיל( שורה 26)  // reut

void post_new_job();//adi needs to do

void restore_job();//tair needs to do 

void logingout_5_4() //shirel













