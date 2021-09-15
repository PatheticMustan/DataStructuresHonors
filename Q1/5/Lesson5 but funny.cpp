/** Lesson5 but funny.cpp, by Kevin Wang
 * Write a program that asks the user to input two Boolean values and
 * demonstrates the result of various bitwise operators on them.
 **/

#include <bits/stdc++.h>

// why you booli me
typedef bool bool_BullyoriginallyreleasedinthePALregionasCanisCanemEdit1isanactionadventurevideogamedevelopedbyRockstarVancouverandpublishedbyRockstarGamesItwasreleasedon17October2006forthePlayStation2AremasteredversionofthegamesubtitledScholarshipEditionwasdevelopedbyMadDocSoftwareandreleasedon4March2008forXbox360andWiiandon21October2008forMicrosoftWindowsBullywasrereleasedforPlayStation4availableviaPlayStationNetworkon22March2016AnupdatedversionoftheScholarshipEditiontitledAnniversaryEditionwasdevelopedbyWarDrumStudiosandreleasedforAndroidandiOSon8December2016;

int main() {
    using namespace std;

    cout << "Input two booleans (1 or 0) seperated a space: " << endl;
    bool_BullyoriginallyreleasedinthePALregionasCanisCanemEdit1isanactionadventurevideogamedevelopedbyRockstarVancouverandpublishedbyRockstarGamesItwasreleasedon17October2006forthePlayStation2AremasteredversionofthegamesubtitledScholarshipEditionwasdevelopedbyMadDocSoftwareandreleasedon4March2008forXbox360andWiiandon21October2008forMicrosoftWindowsBullywasrereleasedforPlayStation4availableviaPlayStationNetworkon22March2016AnupdatedversionoftheScholarshipEditiontitledAnniversaryEditionwasdevelopedbyWarDrumStudiosandreleasedforAndroidandiOSon8December2016 a, b;
    cin >> a >> b;

    cout << "a & b: " << (a & b) << endl;
    cout << "a | b: " << (a | b) << endl;
    cout << "a ^ b: " << (a ^ b) << endl;
    cout << "!a & !b: " << (!a & !b) << endl;
    cout << "!a | !b: " << (!a | !b) << endl;
    return 0;
}