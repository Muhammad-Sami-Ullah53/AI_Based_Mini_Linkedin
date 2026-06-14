#include "JobRecommender.h"

void JobRecommender::recommendJobs(
    const Candidate& candidate,
    Job* jobs,
    int jobCount,
    int appliedJobId
)
{
    MatchingEngine engine;

    cout << "\n===== Recommended Jobs =====\n";

    double bestScore1 = -1;
    double bestScore2 = -1;
    double bestScore3 = -1;

    int bestIndex1 = -1;
    int bestIndex2 = -1;
    int bestIndex3 = -1;

    for(int i = 0; i < jobCount; i++)
    {
        if(
            jobs[i].getJobId()
            ==
            appliedJobId
        )
        {
            continue;
        }

        double score =
            engine.calculateOverallScore(
                candidate,
                jobs[i]
            );

        if(score > bestScore1)
        {
            bestScore3 = bestScore2;
            bestIndex3 = bestIndex2;

            bestScore2 = bestScore1;
            bestIndex2 = bestIndex1;

            bestScore1 = score;
            bestIndex1 = i;
        }
        else if(score > bestScore2)
        {
            bestScore3 = bestScore2;
            bestIndex3 = bestIndex2;

            bestScore2 = score;
            bestIndex2 = i;
        }
        else if(score > bestScore3)
        {
            bestScore3 = score;
            bestIndex3 = i;
        }
    }

    bool found = false;

    if(bestIndex1 != -1 && bestScore1 >= 60)
    {
        cout
            << "1. "
            << jobs[bestIndex1].getTitle()
            << " -> "
            << bestScore1
            << "%"
            << endl;

        found = true;
    }

    if(bestIndex2 != -1 && bestScore2 >= 60)
    {
        cout
            << "2. "
            << jobs[bestIndex2].getTitle()
            << " -> "
            << bestScore2
            << "%"
            << endl;

        found = true;
    }

    if(bestIndex3 != -1 && bestScore3 >= 60)
    {
        cout
            << "3. "
            << jobs[bestIndex3].getTitle()
            << " -> "
            << bestScore3
            << "%"
            << endl;

        found = true;
    }

    if(!found)
    {
        cout
            << "No suitable jobs found."
            << endl;
    }
}