#include <cstdio>
#include <cassert>
int ans[] = {0,2,1,32,30,80,109,6824,59808,147224,415870,1757896,1897056,4898872,7593125,776830421,290516100,746623577,293783147,33900006,735127505,565460332,428982705,472062098,161873957,117354594,515619293,578944191,312106242,569389279,391464593,261086313,584837659,683961846,468868529,211593382,736955478,229471758,157617135,398169441,360252438,629394768,264125799,647490480,342079395,391579767,225200475,486011304,513156108,628771752,132906648,142138221,20119449,444199674,195188679,387329805,44684703,651912135,737154512,612549793,519860281,186175544,212568440,240805271,239509872,581127897,6511239,156126222,509425833,672407328,366667722,459185405,509737025,554790222,165216555,703150560,74806569,398730015,383350905,506108358,51326142,298053147,104256117,391428765,374020479,206607807,87664059,275899176,56407680,551553401,448939463,582889860,129676638,226078251,135769095,61292868,578972226,190181628,390739055,184587732,446575689,732674124,232198470,676760679,352474101,611444862,575661807,628905585,320813094,522840969,469781928,156006018,554473341,239654268,643714911,433540170,199307003,496385218,291740751,67309914,370826673,202356819,279421821,421203111,63744786,520987612,550671827,482164403,768209115,462063756,154906374,36099042,341766705,678182556,621882744,478771358,231881111,175889805,243630450,168908523,671961765,55761813,652682670,773939082,517628076,756201264,124604900,750976272,498253248,676047609,137170026,705610017,495032139,561797418,703097347,500815609,95984586,739707108,265613565,387099846,777331779,594676173,591219559,407997044,208947235,93337440,478908360,685013007,487033953,671903001,39521181,738490312,33785059,465470131,310453920,54648783,346831137,427694175,474743430,705296781,435828036,429824745,663532359,261388683,244690731,533997135,596108961,506813013,371892402,590145264,104733162,143420103,654339672,700348950,685038942,578826927,286484229,501639192,434962491,299270097,27702486,335375775,111746817,565603164,294926121,676063665,735862995,710035809,437011960,668528077,138765186,508213986,615036450,353784942,624827616,343900011,241289776,52410890,72018835,352406796,415705878,4802637,376367145,65589678,333633477,341834527,303717460,282387700,42951006,254706039,423048528,526429710,68131467,669954708,12787348,500636381,317959019,479433192,657133515,416259390,610216692,340129188,44594256,257373347,138718678,530767740,292922628,37220268,605295159,480722613,458170419,30540300,487159055,232966794,149150650,412133651,386543325,139952108,289303402,102404925,317067177,396414708,80515854,663739304,317300809,228877044,493725043,715317967,490300965,315527373,743539734,488329191,553627998,533025234,242583957,706116537,614109258,645447222,523195911,492109128,722623041,111085128,766395126,654378921,691964847,496688157,399056049,654363234,102052314,191720088,473910948,259736526,332840025,388047555,665791056,627111387,139696515,441456687,443032569,283264821,771641703,452641455,511306362,117572859,127701891,721298331,176520078,357242229,611296308,696994956,405628839,429224274,465336054,695091546,689828796,574648641,351220905,507964023,675326610,517248963,453528621,220301928,494463186,681789969,339589656,44524053,417125457,339589404,747135963,341780733,734158215,396817281,21997836,5728464,147611205,456248898,714128667,377654949,3862068,128418948,589390074,304947090,11703825,228266073,127304142,429215724,361541124,521572968,468358191,341231688,65323503,613778508,15985323,291661029,410970006,591638112,349541550,89967528,224922159,361094166,584206074,640051812,324264456,652625388,693768537,11740617,309238398,211085469,194905872,639416484,110110707,296645895,748118511,131177718,511142751,775975599,421403409,475528473,434685258,1768977,80301375,708023862,569195676,56238084,632887668,88089750,631539342,396695565,38780154,695798271,469819224,439587099,69045921,682966116,112310856,64943298,534475872,40215357,389728458,286368453,736006257,501181650,54829908,603489402,338032656,512182818,627500097,462674016,3103092,157324491,43978329,596818971,259025598,9088632,91991781,577291428,211245489,429471231,142626330,172560633,510907446,444609585,758102058,375112647,744786693,276174402,19259856,233672418,745389414,225772848,23385663,324290610,519804558,120337812,402578568,360676008,450089262,551043738,337388940,512108856,28879011,690040638,106017282,558262341,99972432,608226003,612152037,42414435,776201013,39580443,518796945,494437752,583194366,723936555,415359657,309569589,751104774,166684527,249229170,353120823,130668327,753823584,580966092,561963717,543672234,393846327,586278000,327398400,278403867,156455586,363920382,190245195,290039148,547014447,466218648,146037150,585462906,666008595,691786683,374707494,622498779,231158277,685740951,115612245,681825249,545555745,551718468,277206615,640171035,757727334,195193908,658656684,457760646,225925875,505761984,18685233,506832921,112511021,396846646,290147622,113924623,669986155,336008070,63611061,238586775,119956662,616557739,772784623,334527774,410403148,51933421,};

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int cur = 0;
  for (int i = 1; i <= 256; i <<= 1) {
    for (int j = 1; j <= i; j++) {
      if (i == n && j == k) {
        printf("%d\n", ans[cur]);
        return 0;
      }
      ++cur;
    }
  }
  assert(false);
}