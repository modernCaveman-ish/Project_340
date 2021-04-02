struct comment_struct{
    int comment_counter = 0;
    char *comment;
    struct comment_struct *next;
};

void createCommentToken(alpha_token_t comment, char *comment_content){
    int active_comments = 1;
    int current = input();
    int next = input();
    struct comment_struct *comment_list;

    comment_list = (struct comment_struct *)malloc(sizeof(struct comment_struct));
    comment_list->comment_counter++;

    while((current != EOF && next != EOF) && (current != 0 && next != 0)){
        /*Check for / and * */
        if(current == '*' && next != '*'){
            if(next == '/'){ /*closing comments */
                printf("Closing tag detected\n");
                active_comments--;
                if(active_comments = 0){
                    break; /*End of comments*/
                }
            else {
                current = input();
                next = input();
            }
           
            }
            else {
                curent = input();
                next = input();
            }
        }
        else if(current == '*' && next == '*'){ 
            current = next;
            next = input();
        }
        
    }

}

