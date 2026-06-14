#include "MatchingEngine.h"

double MatchingEngine::calculateSkillMatch(
    const Candidate& candidate,
    const Job& job
)
{
    if(job.getSkillCount() == 0)
    {
        return 0;
    }

    double totalSkillScore = 0;

    for(int i = 0;
        i < job.getSkillCount();
        i++)
    {
        Skill requiredSkill =
            job.getRequiredSkillAt(i);

        bool found = false;

        for(int j = 0;
            j < candidate.getSkillCount();
            j++)
        {
            Skill candidateSkill =
                candidate.getSkillAt(j);

            if(
                requiredSkill.getSkillName()
                ==
                candidateSkill.getSkillName()
            )
            {
                found = true;

                int candidateLevel =
                    candidateSkill
                        .getSkillLevel();

                int requiredLevel =
                    requiredSkill
                        .getSkillLevel();

                double skillScore;

                if(candidateLevel >= requiredLevel)
                {
                    skillScore = 100;
                }
                else
                {
                    skillScore =
                        (
                            (double)
                            candidateLevel
                            /
                            requiredLevel
                        )
                        * 100;
                }

                totalSkillScore +=
                    skillScore;

                break;
            }
        }

        if(!found)
        {
            totalSkillScore += 0;
        }
    }

    return
        totalSkillScore
        /
        job.getSkillCount();
}


double MatchingEngine::
calculateEducationMatch(
    const Candidate& candidate,
    const Job& job
)
{
    if(
        candidate.getEducation()
        ==
        job.getRequiredEducation()
    )
    {
        return 100;
    }

    return 0;
}


double MatchingEngine::calculateExperienceMatch(
    const Candidate& candidate,
    const Job& job
)
{
    int candidateExp =
        candidate.getExperienceYears();

    int requiredExp =
        job.getRequiredExperience();

    if(requiredExp == 0)
    {
        return 100.0;
    }

    if(candidateExp >= requiredExp)
    {
        return 100.0;
    }

    return (
        (double)candidateExp
        /
        requiredExp
    ) * 100.0;
}

double MatchingEngine::calculateOverallScore(
    const Candidate& candidate,
    const Job& job
)
{
    double skillScore =
        calculateSkillMatch(
            candidate,
            job
        );

    double experienceScore =
        calculateExperienceMatch(
            candidate,
            job
        );

    double educationScore =
    calculateEducationMatch(
        candidate,
        job
    );

return
(skillScore * 0.6)
+
(experienceScore * 0.25)
+
(educationScore * 0.15);
}