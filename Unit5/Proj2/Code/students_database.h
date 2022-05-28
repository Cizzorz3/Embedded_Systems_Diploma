/*
 * students_database.h
 *
 *  Created on: May 22, 2022
 *      Author: Mohamed Adel
 */
#ifndef students_database_H__
#define students_database_H__

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include "queue.h"

#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdin); fflush(stdout)
#define SIZE 50

struct sinfo{
	char fname[50];
	char lname[50];
	int roll;
	float gpa;
	int cid[5];
}st[SIZE];



void add_student_file();
void add_student_manually();
void find_by_roll_no();
void find_by_first_name();
void find_by_course_id();
void find_total_no_of_students();
void delete_student();
void update_student();
void show_student();

#endif 