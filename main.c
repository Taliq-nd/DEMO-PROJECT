#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);
    courses[n_courses++] = createCourse("CSE 4205", "Structured Programming II", 3.0, 2);

    for (int i = 0; i < n_courses; i++)
    {
        double marks;
        printf("Marks for %s: ", courses[i].name);
        scanf("%lf", &marks);
        results[i] = createCourseResult(&courses[i], marks);
    }

    printf("\n--- Course Results ---\n");
    for (int i = 0; i < n_courses; i++)
    {
        viewCourseResult(results[i]);
    }

    printf("\n--- Semester GPAs ---\n");
    for (int semester = 1; semester <= 2; semester++)
    {
        CourseResult semesterResults[1000];
        filterCourseResultsBySemester(results, n_courses, semester, semesterResults);
        int n_semesterResults = countCourseResultsBeforeNull(semesterResults, n_courses);
        double semesterGPA = calculateGPA(semesterResults, n_semesterResults);
        printf("Semester %d GPA: %.2f\n", semester, semesterGPA);
    }

    double cgpa = calculateGPA(results, n_courses);
    printf("CGPA: %.2f\n", cgpa);

    return 0;
}