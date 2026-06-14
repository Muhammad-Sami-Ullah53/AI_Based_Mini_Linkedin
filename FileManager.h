#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <string>

#include "Candidate.h"
#include "HR.h"
#include "Job.h"
#include "Application.h"

using namespace std;

class FileManager
{
public:

    // Candidate CSV
    static void saveCandidates(
        Candidate* candidates,
        int count,
        string filename
    );

    static int loadCandidates(
        Candidate*& candidates,
        int& count,
        string filename
    );

    // Candidate Skills CSV
    static void saveCandidateSkills(
        Candidate* candidates,
        int count,
        string filename
    );

    static void loadCandidateSkills(
        Candidate* candidates,
        int count,
        string filename
    );

    // HR CSV
    static void saveHRs(
        HR* hrList,
        int count,
        string filename
    );

    static int loadHRs(
        HR*& hrList,
        int& count,
        string filename
    );

    // Job CSV
    static void saveJobs(
        Job* jobs,
        int count,
        string filename
    );

    static int loadJobs(
        Job*& jobs,
        int& count,
        string filename
    );

    // Job Skills CSV
    static void saveJobSkills(
        Job* jobs,
        int count,
        string filename
    );

    static void loadJobSkills(
        Job* jobs,
        int count,
        string filename
    );

    // Application CSV
    static void saveApplications(
        Application* apps,
        int count,
        string filename
    );

    static int loadApplications(
        Application*& apps,
        int& count,
        string filename
    );
};

#endif