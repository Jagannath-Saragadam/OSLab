
int main()
{
        char buffer[40]; //buffer for reading and writing
        int filedes[2]; //file descriptors for pipe, fildes[0] for read and filedes[1] for write
        int filedes2[2]; //File descriptors for second pipe
        int cid; //child process ID

        pipe(filedes); //creating pipe for one way communication(half duplex) with filedes and attribute
        pipe(filedes2); //creating second pipe for one way comm. (full duplex)
        cid=fork(); //making fork call

        if(cid>0) //checking if child has been sucessfully created greater is parent, equal to is child
        {
                //parent section
                printf("I am parent process with id %d and child process id %d\n",getpid(),cid);

                write(filedes[1],"This is message from starfleet\n",31); //writing to pipe using filedes[1]               
                read(filedes2[0],buffer,40);
                printf("%s",buffer);
        }
                else
                {
                        //child section
                        printf("I am child\n");
                        read(filedes[0],buffer,30); //reading from pipe using filedes[0]
                        printf("buffer:%s\n",buffer);
                        write(filedes2[1],"This is reply to the starfleet message\n",40);
                }

        return 0;
}
"tryPipe3.c" 37L, 1117C                                                                                   37,1          Bot

