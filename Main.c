#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct person {
	char FirstName[25];
	char LastName[25];
	char Gender[8];
	char Occupation[20];
	unsigned int Salary;
	//int id;
} person;

void set_data(char s[], int* k, char field[])
{
	int i = *k, j =0;
	while ((s[i] == ',') || (s[i] == '\"'))
	{
		i++;
	}
	while (s[i] != '\"')
	{
		field[j] = s[i];
		i++;
		j++;
	}
	field[j] = '\0';
	*k = i;
}

int main(int argc, char* argv[]) {
	FILE* f;
	char s[255];
	person temp;
	int n = 0, i;
	person* data = NULL;
	person tmp;
	
	if (NULL == (f = fopen("data.csv", "r"))) {
		fprintf(stderr, "cannot open file '%s'", "data.csv");
		return 1;
	}
	if (!(fopen_s(&f, "data.csv", "r"))) {
		fgets(s, 255, f);
		while (!feof(f)) {
			fgets(s, 255, f);
			data = (person*)realloc(data, (n + 1) * sizeof(person));
			i = 0;
			set_data(s, &i, data[n].FirstName);
			set_data(s, &i, data[n].LastName);
			set_data(s, &i, data[n].Gender);
			set_data(s, &i, data[n].Occupation);
			set_data(s, &i, &data[n].Salary);
			//data[n].id = n;
			n++;
		}
		fclose(f);
	}
	
	for(int p = 1; p <= n; p++ )
		for (int m = 0; m < n - p; m++)
		{
			int code = strcmp(data[m + 1].Occupation, data[m].Occupation);
			if (code < 0)
			{
				temp = data[m];
				data[m] = data[m + 1];
				data[m + 1] = temp;
			}
		}
	

	for (int f = 0; f < n - 1; f++) 
	{
			printf("%s %s %s %s %u \n",data[f].FirstName, data[f].LastName, data[f].Gender, data[f].Occupation, data[f].Salary/*,data[f].id*/);
	}



	return 0;
}//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#pragma warning(disable : 4996)
//
//int main() {
//    FILE* pf = fopen("data.csv", "rt");
//    size_t len;
//    fseek(pf, 0, SEEK_END);
//    len = ftell(pf);
//    fseek(pf, 0, SEEK_SET);
//    char* buf, ** lines;
//    size_t linenum = 0;
//    buf = (char*)malloc(sizeof(char) * (len + 1));
//
//    fread(buf, len, 1, pf);
//    fclose(pf);
//    
//    for (char* tmp = buf; tmp != NULL; tmp = strchr(tmp + 1, '\n'))linenum++;
//    if (buf[len - 1] == '\n') { buf[len - 1] = 0; linenum--; }
//
//    lines = (char**)malloc(sizeof(char*) * linenum);
//
//    lines[0] = buf;
//    for (size_t i = 1; i < linenum; i++) {
//        lines[i] = strchr(lines[i - 1], '\n') + 1;
//        lines[i][-1] = 0;
//    }
//    
//    for (size_t i = 0; i < linenum; i++)printf("%i: %s\n", i, lines[i]);
//
//    free(lines[0]);
//    free(lines);
//}
//