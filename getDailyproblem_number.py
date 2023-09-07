# coding=<encoding name> ： # coding=utf-8
from datetime import datetime
import requests
import json
import smtplib
from email.mime.text import MIMEText

base_url = 'https://leetcode-cn.com'

# 获取今日每日一题的题名(英文)
response = requests.post(base_url + "/graphql", json={
    "operationName": "questionOfToday",
    "variables": {},
    "query": "query questionOfToday { todayRecord {   question {     questionFrontendId     questionTitleSlug     __typename   }   lastSubmission {     id     __typename   }   date   userStatus   __typename }}"
})
leetcodeTitle = json.loads(response.text).get('data').get('todayRecord')[0].get("question").get('questionTitleSlug')

# 获取今日每日一题的所有信息
url = base_url + "/problems/" + leetcodeTitle
response = requests.post(base_url + "/graphql",
                         json={"operationName": "questionData", "variables": {"titleSlug": leetcodeTitle},
                               "query": "query questionData($titleSlug: String!) {  question(titleSlug: $titleSlug) {    questionId    questionFrontendId    boundTopicId    title    titleSlug    content    translatedTitle    translatedContent    isPaidOnly    difficulty    likes    dislikes    isLiked    similarQuestions    contributors {      username      profileUrl      avatarUrl      __typename    }    langToValidPlayground    topicTags {      name      slug      translatedName      __typename    }    companyTagStats    codeSnippets {      lang      langSlug      code      __typename    }    stats    hints    solution {      id      canSeeDetail      __typename    }    status    sampleTestCase    metaData    judgerAvailable    judgeType    mysqlSchemas    enableRunCode    envInfo    book {      id      bookName      pressName      source      shortDescription      fullDescription      bookImgUrl      pressImgUrl      productUrl      __typename    }    isSubscribed    isDailyQuestion    dailyRecordStatus    editorType    ugcQuestionId    style    __typename  }}"})
# 转化成json格式
jsonText = json.loads(response.text).get('data').get("question")
# 题目题号
daily_number = jsonText.get('questionFrontendId')

print("daily problem number is: " + daily_number);