#include "GapAnalyzer.h"

void GapAnalyzer::findMissingSkills(
    const Candidate& candidate,
    const Job& job
) const
{
    cout << "\n===== Missing Skills =====\n";

    bool foundMissing = false;

    for(int i = 0;
        i < job.getSkillCount();
        i++)
    {
        Skill requiredSkill =
            job.getRequiredSkillAt(i);

        bool skillFound = false;

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
                skillFound = true;
                break;
            }
        }

        if(!skillFound)
        {
            cout
                << "- "
                << requiredSkill.getSkillName()
                << endl;

            foundMissing = true;
        }
    }

    if(!foundMissing)
    {
        cout << "No missing skills.\n";
    }
}

void GapAnalyzer::analyzeExperienceGap(
    const Candidate& candidate,
    const Job& job
) const
{
    cout << "\n===== Experience Analysis =====\n";

    int candidateExp =
        candidate.getExperienceYears();

    int requiredExp =
        job.getRequiredExperience();

    if(candidateExp >= requiredExp)
    {
        cout
            << "Experience requirement satisfied."
            << endl;
    }
    else
    {
        cout
            << "Need "
            << (requiredExp - candidateExp)
            << " more year(s) of experience."
            << endl;
    }
}