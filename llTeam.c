#include <stdio.h>
#include <stdlib.h>

//create a structure
struct Team
{
	char name[20];
	int points;
	struct Team *next;
};

//main
int main(int argc, char **argv)
{
	struct Team *teamHead = malloc(sizeof(struct Team));

	int numberT;

	//choose the number of teams
	do
	{
		printf("how many teams do you want to add?\n");
		scanf("%d", &numberT);
	} while (numberT == 0);

	//first team
	printf("write the name of the team\n");
	scanf("%s", teamHead->name);
	printf("how many points hs the team\n");
	scanf("%d", &teamHead->points);
	teamHead->next = NULL;

	//the rest of the teams
	if (numberT > 1)
	{
		for (int i = 1; i < numberT; i++)
		{
			struct Team *newTeam = malloc(sizeof(struct Team));
			printf("write the name of the team\n");
			scanf("%s", newTeam->name);
			printf("how many points has the team\n");
			scanf("%d", &newTeam->points);

			newTeam->next = teamHead;
			teamHead = newTeam;
		}
	}

	//print the teams information
	for (struct Team *p = teamHead; p != NULL; p = p->next)
	{
		printf("The team: %s has %d points\n", p->name, p->points);
	}

	free(teamHead);
	teamHead = NULL;

	return 0;
}