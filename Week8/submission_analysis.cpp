#include <bits/stdc++.h>
using namespace std;

struct Submission{
    string user_id;
    string problem_id;
    string time_point;
    string status;
    int point;
};

vector<Submission> submissions;
int totalNumberOfSubmissions = 0;
int numberErrorSubmissions = 0;
unordered_map<string, int> numberErrOfSubmissionsByUser;
map<pair<string, string>, int> totalPointOfSubmissionsByUser;
map<string, int> totalPointOfUser;

int totalSubmissions[86400];
int totalSubmissionsSecond[86400];


void processQuery(const string& query){
    stringstream ss(query);
    string command;
    ss >> command;
    if(command == "#"){
        return;
    }
    if(command == "?total_number_submissions"){
        cout << totalNumberOfSubmissions << "\n";
    }
    else if(command == "?number_error_submision"){
        cout << numberErrorSubmissions << "\n";
    }
    else if(command == "?number_error_submision_of_user"){
        string user_id;
        ss >> user_id;
        cout << numberErrOfSubmissionsByUser[user_id] << "\n";
    }
    else if(command == "?total_point_of_user"){
        string user_id;
        ss >> user_id;
        cout << totalPointOfUser[user_id] << "\n";
    }
    else if(command == "?number_submission_period"){
        string fromTime, toTime;
        ss >> fromTime >> toTime;
        int fromTimeSecond = stoi(fromTime.substr(0, 2)) * 3600 + stoi(fromTime.substr(3, 2)) * 60 + stoi(fromTime.substr(6, 2));
        int toTimeSecond = stoi(toTime.substr(0, 2)) * 3600 + stoi(toTime.substr(3, 2)) * 60 + stoi(toTime.substr(6, 2));
        int total = 0;
        cout << totalSubmissionsSecond[toTimeSecond] - totalSubmissionsSecond[fromTimeSecond - 1] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    while(getline(cin, line)){
        if(line == "#"){
            break;
        }
        stringstream ss(line);
        Submission submission;
        ss >> submission.user_id >> submission.problem_id >> submission.time_point >> submission.status >> submission.point;
        submissions.push_back(submission);
        totalNumberOfSubmissions++;
        if(submission.status == "ERR"){
            numberErrorSubmissions++;
            numberErrOfSubmissionsByUser[submission.user_id]++;
        }


        if(submission.status == "OK"){
            pair<string, string> userProblem = make_pair(submission.user_id, submission.problem_id);
            int point = submission.point;
            int problemPoint = totalPointOfSubmissionsByUser[userProblem];
            if(problemPoint < point){
                totalPointOfUser[submission.user_id] += point - problemPoint;
                totalPointOfSubmissionsByUser[userProblem] = point;
            }
        }


        int hour = stoi(submission.time_point.substr(0, 2));
        int minute = stoi(submission.time_point.substr(3, 2));
        int second = stoi(submission.time_point.substr(6, 2));
        int timePointSecond = hour * 3600 + minute * 60 + second;
        totalSubmissions[timePointSecond]++;
    }

    int totalSub = 0;
    for(int i = 0; i <= 86400; i++){
        totalSub += totalSubmissions[i];
        totalSubmissionsSecond[i] = totalSub;
    }
    
    string query;
    while (getline(cin, query))
    {
        if (query == "#")
        {
            break;
        }
        processQuery(query);
    }
    return 0;
}