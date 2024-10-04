#include<stdio.h>
#include<string.h>

struct Names // Structure 1
{
    char n1[50];
    char n2[50];
    char n3[50];
    char n4[50];
    char n5[50];
};

struct Students  // Structure 2
{
    int id;
    char name[100];
    float tgpa;
    float ssc;
    float hsc;
};

void main()
{
    int i,j,k;

    struct Students students[7];
    struct Names names[7];

    FILE *f1 = fopen("student_data.txt","r"); // Given file

    if(f1 == NULL)
    {
        printf("File not found!");
        exit(1);
    }

    for(i=0; i<7; i++) // Scan all the values from given file.
    {
        fscanf(f1, "%s", &names[i].n1);
        fscanf(f1, "%d", &students[i].id);
        fscanf(f1, "%s", &names[i].n2);
        fscanf(f1, "%s", &students[i].name);
        fscanf(f1, "%s", &names[i].n3);
        fscanf(f1, "%f", &students[i].tgpa);
        fscanf(f1, "%s", &names[i].n4);
        fscanf(f1, "%f", &students[i].hsc);
        fscanf(f1, "%s", &names[i].n5);
        fscanf(f1, "%f", &students[i].ssc);
    }


    // Total GPA Analysis //

    int count=0;

    float t1[7], t2[7];

    for(i=0; i<7; i++)  // storing all total GPA values in t1
    {
        t1[i] = students[i].tgpa;
    }

    for(i=0; i<7; i++) // removing all duplicate elements from t1 and store in t2.
    {
        for(j=0; j<count; j++)
        {
            if(t1[i] == t2[j])
            {
                break;
            }
        }
        if(j==count)
        {
            t2[count] = t1[i];
            count++;
        }
    }

    float a;

    for(i=0; i<7; i++) // set all the "total GPA" values in descending order.
    {
        if(t2[i] > 8.00)
        {
            for(j=i+1; j<7; j++)
            {
                if(t2[i] < t2[j])
                {
                    a = t2[i];
                    t2[i] = t2[j];
                    t2[j] = a;
                }
            }
        }
    }

    FILE *f2 = fopen("total_gpa_analysis.txt","w");  // create a new file for "Total GPA Analysis //
    f1 = fopen("student_data.txt","a");

    fprintf(f2,"For Bangla Medium: \n");
    fprintf(f2,"==================");

    fprintf(f1,"\n\n\n");
    fprintf(f1,"TOTAL GPA ANALYSIS\n");
    fprintf(f1,"..................\n");
    fprintf(f1,"For Bangla Medium: \n");
    fprintf(f1,"==================");

    for(j=0; j<7; j++) // Put all the total GPA for Bangla Medium in total gpa analysis file .
    {
        if(t2[j] > 8.00)
        {
            fprintf(f2,"\n\nTotal GPA: %.2f:", t2[j]);
            fprintf(f2,"\n---------------");

            fprintf(f1,"\n\nTotal GPA: %.2f:", t2[j]);
            fprintf(f1,"\n---------------");

            for(i=0; i<7; i++)
            {
                if(students[i].tgpa == t2[j])
                {
                    fprintf(f2,"\nID: %d; Name: %s ", students[i].id,students[i].name);

                    fprintf(f1,"\nID: %d; Name: %s ", students[i].id,students[i].name);
                }
            }
        }
    }

    fprintf(f2,"\n\n\n\n");
    fprintf(f2,"For English Medium: \n");
    fprintf(f2,"==================");

    fprintf(f1,"\n\n\n\n");
    fprintf(f1,"For English Medium: \n");
    fprintf(f1,"==================");

    for(j=0; j<7; j++)  // Put all the total GPA for English Medium in total gpa analysis file .
    {
        if(t2[j] >= 1 && t2[j] <= 8.00)
        {
            fprintf(f2,"\n\nTotal GPA: %.2f:", t2[j]);
            fprintf(f2,"\n---------------");

            fprintf(f1,"\n\nTotal GPA: %.2f:", t2[j]);
            fprintf(f1,"\n---------------");

            for(i=0; i<7; i++)
            {
                if(students[i].tgpa == t2[j])
                {
                    fprintf(f2,"\nID: %d; Name: %s ", students[i].id,students[i].name);

                    fprintf(f1,"\nID: %d; Name: %s ", students[i].id,students[i].name);
                }
            }
        }
    }

    printf("\nTotal GPA Analysis has run successfully!");


    // SSC GPA Analysis //


    int count1=0;

    float t3[7], t4[7];

    for(i=0; i<7; i++) // storing all ssc gpa information in t3.
    {
        t3[i] = students[i].ssc;
    }

    for(i=0; i<7; i++) // removing duplicate elements from t3 and store in t4.
    {
        for(j=0; j<count1; j++)
        {
            if(t3[i] == t4[j])
            {
                break;
            }
        }
        if(j==count1)
        {
            t4[count1] = t3[i];
            count1++;
        }
    }

    float b;

    for(i=0; i<7; i++) // set all the "SSC GPA" information in descending order.
    {
        if(t4[i] > 4.00)
        {
            for(j=i+1; j<7; j++)
            {
                if(t4[i] < t4[j])
                {
                    b = t4[i];
                    t4[i] = t4[j];
                    t4[j] = b;
                }
            }
        }
    }

    FILE *f3 = fopen("ssc_gpa_analysis.txt","w"); // create new file for ssc gpa analysis.
    f1 = fopen("student_data.txt","a");

    fprintf(f3,"For Bangla Medium: \n");
    fprintf(f3,"==================");

    fprintf(f1,"\n\n\n");
    fprintf(f1,"SSC GPA ANALYSIS\n");
    fprintf(f1,"..................\n");
    fprintf(f1,"For Bangla Medium: \n");
    fprintf(f1,"==================");

    for(j=0; j<7; j++) // Put all the ssc GPA for Bangla Medium in total ssc analysis file .
    {
        if(t4[j] > 4.00)
        {
            fprintf(f3,"\n\nSSC GPA: %.2f:", t4[j]);
            fprintf(f3,"\n---------------");

            fprintf(f1,"\n\nSSC GPA: %.2f:", t4[j]);
            fprintf(f1,"\n---------------");
            for(i=0; i<7; i++)
            {
                if(students[i].ssc==t4[j])
                {
                    fprintf(f3,"\nID: %d; Name: %s ", students[i].id,students[i].name);

                    fprintf(f1,"\nID: %d; Name: %s ", students[i].id,students[i].name);
                }
            }
        }
    }

    fprintf(f3,"\n\n\n\n");
    fprintf(f3,"For English Medium: \n");
    fprintf(f3,"==================");

    fprintf(f1,"\n\n\n\n");
    fprintf(f1,"For English Medium: \n");
    fprintf(f1,"==================");

    for(j=0; j<7; j++) // Put all the ssc GPA for English Medium in total gpa analysis file .
    {
        if(t4[j] > 1.00 && t4[j] <= 4.00)
        {
            fprintf(f3,"\n\nOlevel GPA: %.2f:", t4[j]);
            fprintf(f3,"\n---------------");

            fprintf(f1,"\n\nOlevel GPA: %.2f:", t4[j]);
            fprintf(f1,"\n---------------");
            for(i=0; i<7; i++)
            {
                if(students[i].ssc == t4[j])
                {
                    fprintf(f3,"\nID: %d; Name: %s ", students[i].id,students[i].name);

                    fprintf(f1,"\nID: %d; Name: %s ", students[i].id,students[i].name);
                }
            }
        }
    }

    printf("\nSSC GPA Analysis has run successfully!");


    // HSC GPA Analysis //


    int count2=0;

    float t5[7], t6[7];

    for(i=0; i<7; i++) // storing hsc gpa information in t5 .
    {
        t5[i] = students[i].hsc;
    }

    for(i=0; i<7; i++) // removing all duplicate elements from t5 and storing in t6.
    {
        for(j=0; j<count2; j++)
        {
            if(t5[i] == t6[j])
            {
                break;
            }
        }
        if(j == count2)
        {
            t6[count2] = t5[i];
            count2++;
        }
    }

    float c;

    for(i=0; i<7; i++) // set all the hsc gpa in descending order.
    {
        if(t6[i] > 4.00)
        {
            for(j=i+1; j<7; j++)
            {
                if(t6[i] < t6[j])
                {
                    c = t6[i];
                    t6[i] = t6[j];
                    t6[j] = c;
                }
            }
        }
    }

    FILE *f4 = fopen("hsc_gpa_analysis.txt","w"); // create and write new txt file for hsc gpa analysis .
    f1 = fopen("student_data.txt","a");

    fprintf(f4,"For Bangla Medium: \n");
    fprintf(f4,"==================");

    fprintf(f1,"\n\n\n");
    fprintf(f1,"HSC GPA ANALYSIS\n");
    fprintf(f1,"..................\n");
    fprintf(f1,"For Bangla Medium: \n");
    fprintf(f1,"==================");

    for(j=0; j<7; j++) // Put all the hsc GPA for Bangla Medium in hsc gpa analysis file .
    {
        if(t6[j] > 4.00)
        {
            fprintf(f4,"\n\nHSC GPA: %.2f:", t6[j]);
            fprintf(f4,"\n---------------");

            fprintf(f1,"\n\nHSC GPA: %.2f:", t6[j]);
            fprintf(f1,"\n---------------");

            for(i=0; i<7; i++)
            {
                if(students[i].hsc == t6[j])
                {
                    fprintf(f4,"\nID: %d; Name: %s ", students[i].id,students[i].name);

                    fprintf(f1,"\nID: %d; Name: %s ", students[i].id,students[i].name);
                }
            }
        }
    }

    fprintf(f4,"\n\n\n\n");
    fprintf(f4,"For English Medium: \n");
    fprintf(f4,"==================");

    fprintf(f1,"\n\n\n\n");
    fprintf(f1,"For English Medium: \n");
    fprintf(f1,"==================");

    for(j=0; j<7; j++) // Put all the hsc GPA for English Medium in hsc gpa analysis file .
    {
        if(t6[j] > 1.00 && t6[j] <= 4.00)
        {
            fprintf(f4,"\n\nAlevel GPA: %.2f:", t6[j]);
            fprintf(f4,"\n---------------");

            fprintf(f1,"\n\nOlevel GPA: %.2f:", t6[j]);
            fprintf(f1,"\n---------------");
            for(i=0; i<7; i++)
            {

                if(students[i].hsc == t6[j])
                {
                    fprintf(f4,"\nID: %d; Name: %s ", students[i].id,students[i].name);

                    fprintf(f1,"\nID: %d; Name: %s ", students[i].id,students[i].name);
                }
            }
        }
    }

    printf("\nHSC GPA Analysis has run successfully!");

    char ch;

    f1 = fopen("student_data.txt","r");
    printf("\n\n The contents of main file:\n");

    while((ch = fgetc(f1)) != EOF) // print all the data form "Main File" on console.
    {
        printf("%c", ch);
    }

    fclose(f1); // close all the file.
    fclose(f2);
    fclose(f3);
    fclose(f4);
}
