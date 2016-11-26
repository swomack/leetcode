#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution 
{
public:
	int firstUniqChar(string s) 
	{
		vector<int> map(26);
		int result = 0;


		for_each(s.begin(), s.end(), [&map](char element) {
			map[element - 97]++;
		});


		string::iterator it = find_if(s.begin(), s.end(), [&result, &map](char element) {
			if (map[element - 97] == 1)
				return true;

			result++;
			return false;
		});

		if (it == s.end())
			return -1;

		return result;
	}
};

int main()
{
	Solution s;

	int location = s.firstUniqChar("qiwjhweofwcupofoiieacqkeidxwuzdijnjbllkqgwmerdsgxqhgotijtvfbenrgfthmpjivojciclljrnxmsbwefrsrcohkxjdwfjirvpavxpbheqbmnetesusoqwounbvpndmglaneqwdippeqvgpqdnoagxnmiseqiprlaektvbkcmljadwbrwoghuxvtbtrqmusrttxfwafxklatitrfffrushoagfdidlnxoelpldngbbqjcwiwotaoixhlritgdesfjrolfcbqblssdpgmtptgooqvitjughstkikasfktscfpbwknctikvwtnfaekkuvckkmotlxbfwcggcnlfvkutvfthvvwbckbbwhgjfbsahqcrfhvtopucujpgtdsssrjxoahsdanueqarfhemoiaiducbcpfmnuqvicjaftkswcsqdnpqnuchsjeccaibqjajgdnkklriffhnxsoxlmsvigtishsqoqjnwdcxepdajsaiqgbrhpgmodrtmttjosjhilarbqpqsimjaajwsoqlvsndoftuhwcjolaxcffkaqtafbnoeqhcciprrvdrsnlkgsarpxwvsbvnaiojfwmrixqlnckjxxnbkblhqoiqbudqbwchfioqohhcbfjcglhaqhwrurwvnjusplljtnfxtqfxxnwnosbwbnthejvlohjbmornjfjwibiqvdtdbtmtulbrqvxcmwqpgplnvktnvksgmwicvxgxdiqpqwlcwpdkgqrhaccukedcexdttosseujjelkdvksdmwlvjfpuphjdufgplpveqatauncvsgltimrvcmqltkoqgsjnfsjfpepkhtoisearcierrghcxojlqdsuiqvwjhlbwwlvieaubkeqpuusuclldkdonrjnnkjtrwtctnewgdhkugfrpxlixpukeeolnnbkisfakplobkhxatujdejserlqfsdrxpjesdjawdnusjtxtmjrpsojrbkqidanualtbiqahjtqavekuasqkbinahacmoobmjoglsjkvadkvbiimqrivikoxcggttudwklnraufpjispscjluvqqijupscedlsfucbpttcixlpipdpfjlhataxpiiomvgrwukqwjdrntpsefcjewvoivbdxjesgrlawpjrjchmlmfahrxpprtciqknnmvntgdhnvqkipaqskmjhcdjulfdacmgxhuxbgfgtwpnuinxkemonbgqvvkciepvhdbabhsoijfstvhideogshpdaulwagkctqlbucrwepsaggnmfqcbebpchtxqrpfovocjaxdxpbppndqkqrpifcvwarxwbjjquupixvqarmuxblxsmxgsmbkwnvlsrcoqhtshioxjslqrixdecchpiffcnqceslepadsucqjkdnuuexujqjjidphsqcessejdomakhufmcbpqltripwuuexihwtdwlfipjwlwwsmwaaswhclbaxjllnhrhcuqunhirjukxsfqwsfnpgrvbvifijfgljcgevoigucvktjtcxpfcfutepatdkjqsgccvwhoaigqxhqgwpjgsqtdhpcemjegeshdogplxnqkwujrrrkjghxoetnblonqjnxcxvqndtxlhdfnsgdgokatcnkqirnprhkwqfsgvreddddrlgddsansrlreukdcfpkprunwdrgdagdflrtsckplrfbcfiaclwuvctatpbocpcxbchksgavhknsuuvufnmsrdsthpstqjrnoaajtwcqnucgrkpofbrmkfbpcnuggujnlfliglahwxtkjvpxjrfcqwamcxxplskirbjoktstbljjnpuocmalmxwbjhcnhrowpesmixxdoimiepamhbbpfbnxpmwidtlwfhgjgiaifwdcgmrqacrpusdvkfmswhtblqegwufkhwandibtwgitpmqueebaqnmokagcqnwadwrrmcwvqfosifwlmiqnjnxwrqcossktraxxikanwhsvwhmddbaxchtqaorkoctkskspaareiuotsjjeqpawkdknamkfdhxgfwcitmhbhmantswnlcrlcrsfabxasqhwksplrgenspbsbelpuslwrrmpimxksntdsiaxkwohkfblvgqreigwpdadqhretolvuxofxegivphioammckkdehgcrjgnntwtipjvhjtqflfamsrhwbwhbfwetkgwjmnfgxrotlxgksjmpmntbolxvoxruciwobqnxroqjdassfetqobikxbgaqkhorgonchakexvtcpfhkoogjnnboqcdvpbaxownhcbajvcroehjlxujtacpjqdflwnlerfwjrgqwicrjxxohowcneqlcqsoupdnqheiwtpseiknbxoqnndiqhxfakxxxrfqdasuabnotfneaomhhcmmcswgturhtwqeomibvlqflhbhnkibmgbevngndhbgcmpqpkfppbxgnvonqmsimjrkxixshswvttpmhlspmctrhawojedtxsvnckavrpbkwndahhhiwilhdiglabddndmovebxqecitrrnvgdsebihhfacnvjwochuixdxvkamcwjrlpgnwwrbnouoiggxsiopcrowoblilfexqmssdhpgefcmbfbdrviqnkbcmbulowcumleqnucfeqigistueafnqefohktfmbskwvhatmjwuirlvmebbtgjlnspqlphtvfaikjbvqmbwvldrftkredbwohxnnramekhrccteqnxbwppslaifedpchuvqqijimcwbulgwebhffewcxvctdxsnakjxmvqfwfniceteetksikihjpanjgcajbeebahvssugkuboijxiitwlbbtknjamrauvoiwgijuuvmivxtoanvpexqsrjqtpsauefgdkptmqcljxckpqpidukxnmdktssqjqejiqiinddstwrwlrvnlsdumkehbgrrfbmcuidxfowagimwrmjuookpidmbukbcxpmairqjghuwtpcdrpjemqxsihknefjeikgelnpwahvujcneeuonvarcvwagcraxpsqvfdhebpbbiidkrbxjsokbwaerffxcepemolcgloinjtnuqqonckiptvhjvbwgxjqjhowcwdjjdsltsabuoueumnbmdfnsbqulpcmraagfgvvhgarmveookrjsnbdxjvclhimkduvrkeshukwfxkgiehbvovsuhoiqfangoholaxdlvvqqmxtikixklbqkemqltlrecblwpoivhrhffbwxffutofgapiatbxgfostaarrknwctbcieeuqawruiqqibvwfacsnkjbwveuttaipqpxljlvjhawknbgogobctnehewlaedvtkhvefwcppojfgnbixdxktbtdxclsxbhwtdfnmwguasqiexfnsaevuhhdhinqdsawklrmpddjrfnmijudqvrkegwxurhebgpmqqacggxgdgxrccvtqlmtlwcxnucebgeanjcgqoutwnohjliftrgokqcsdjhjkcpkaohsodqxjssngtnraqqmasncfbudmiisrphehwfduodujkmgqorvghfnultkrshhcfkoewsiiqbvjrfwtfqiuubexxdowhmsaxaomthuvruwgoaxauxxrljhpglwwppdowbeqwmhcivhklncxuviwtvoehfdplaskigcafbtqnkkcaewsejmknfansqvjsphepvpllwghamvqugvwenlgarokquefnvrfdhcsvdrfsmsexrvwnancebinxbqtcqcncnuefimvcipwboqankbfjfglcpisdbqlwnvcknpvqkvfloemhtihivapgontiruqxrftuccovidruabdatkkqkopnoxvppwdtqdauauhqetletjnstxdrsxlwxwjcsvfubaijfxrjnldujdrerpnehmmbjsgrmkfswfeddbdaluqcjgxwgcvqhvkhnsvkuoutwqudacwovotbctbjtxgvecehbawhkhsbbbpqoujtvjlwgsnmgxwuuctbxsihfvglxkgcuwvfsmrlekdxbcfmrxwwfjlthsjkirqkrxcwmbmhevedcaufcxgvvnrshmkuuxwxpqxvloftwrxhdrtqxtkwfnhewfsetnijvrfkamuwsxglkmbmxtlshlqrctqhnafilctwrlqarpgabsprmxrqsnckmhfptlvvbskihckjbrjvplmxfwtaomfgeaqtlurxxdjjlljklnxkmhrhkrjdtqsndaktgnrxvdjxteospcpxqwgamavqjabapvtavmmudljuiwqjgrcntxktrtupqwbwjikrwsdojdlilbiaokqtnmvgkcraiidpkrqwtovvakujtewgrnicgdadxnkejxguiamitkdcwkojhbrtgscjofdcbtpklttevuhwnmnmmjrxrwbauaiqvsnjwvrsgebpipjadnctdqmeaeiunjxxebhsatavdrborhrgenkibhqxeltpqlrxrlrvnvlkadlixvxrimxkqonqfdvjnhgxorsqxstkodgvebeahswrxesqdtudmmoxjrsnvextogdfhcaubosgvkhfonaunuaamdsmwriphpjbikcmorrqubvkopkvinubvrkdecnnivrqhxdiottpdhuelscnvatswrbmghhotxslnskiburtsednvghuuffewfqwuqgrxgfritivimtvjkduukrcnmjnfdocwurwecjcjjngbcauihtjjqsaqmqacuegumawbtpgioqdnaqbpmmvcwhvwprkphrnoanaarxwgibfnmnlwjoxrftrfdfftgpueavmqtqjbqrdhpecgoipuvuvpjmagpdnhmlsrldhdgqnvqqwvdlovfkacrnmrdxhnefdupxjksgugjhqupgddpgsqtahkkdkhxlgxqfoamrhbqrxmukwnrieqggmkmghgogedfegutmoigxldqwavupfblxarqrfqjwlqifswifkctbnlllxcamnvksvaitmxisvxpaafduchhwecxagenwntlasvsnvkclsolmltucwhkpakdocllgddgqxcxhxqriahmcqpthoktdcsoffpbmcncdvnxastlsrqcbrbhklilljrjewqqxprbrdajbxcrivtmcnrrmmjsofbuuooahehbrrbxjuvllcheuvajmkfinorhmlrbviplehcxjeubdslaaxuhllvvifjrvpkkblkprocsaehspurrnnwdjjpaojruwkhvkwwejobaxwwxpjaxmxwufensqdbgaksqbqeudvpbfrjaniibvdfuakfmfsrikrjmncnvqvmelvifwbjbptjbjfblggsknxorhsxqxnikjttwnmtvtxeeqfpkspcljkxpxkmnrntuosttakooivuupqjakgsvnmwveksdwoviddolxcdepplteafunstocvsmxatunhpghuvxdnqpinqhxefxftlhxdkexwggxrhadhrxejwgjvkjrnqjhsuqfiiffllclcgmgebtragdvrtjkkwcvombmllxqqjikentrbecdkoecqchjtxshxnjtflsrmsalpcfeauojfakjtpdgblieoossfafpxfbxrpkgqinedsnjrsudscnfkxcktcbljknwmcsqkhileoulcltvamrkthkdxkwvdskpinubvtppociwocahdkmkbqbmkgmeelrclprbblcalqcloadxkkgnnjjothtbnwrjhqsshxqvchikrduvffgmosqqcnsludmblpesfpkwepkshekceuvhfdxlijkttlafiwkbgeafaicljepwqvlfbfgxubdasmhdvudixmchgkpwwjriisahsgftwhfdpqptcjghkiqhgvitpfjjejumixmahjaeuvaghoufoikdrrobsoxifmpvursvgbdcbvmmvjftdvhlwwjbbgkokcisfcjslgqveosudtracvqaofattudklkqsttxrxqvwxsbwcupvscnspmnwbptfqopghvnarptvbqcminbrdcoqlmgscbqpcfnnipshjkrrdqfdxuvvohktkwmagbkxahrpwqaxhdjlmsbohdmbcitssaxqghdgdefokcnimkjdewidwqwehepovuhbatrlkmhatukjxvcieeqcgvkwffpgtrmuwfwhvxqnbgpcjfeskeseojcbvsldkovaavaruoqomamfqcplagojxtmkhttnmvtgfmakaxxlnriiputaokmqanjebqwlifowfivbadudlundtmxtdjesbwbvnjffpowhqkjxudawxwrxgammhrnwlwlvkwavaalbxdsmfvlgiifdhskdsuifvvrfqpxidlunrbjpctnigsrqwirxninpxlbvivkrqhcloowbdlwpruugmerqxxmdjimmbwbwiuochqrrbxvbsxauhubpihfrmuslullhkcnltrjatwuwarldkkterkxsxalbpnjfprcwkqifjhrplmwssvngipuoksphmkdivcekfeubuevemwbsrvqoifseotnmdmjhgtkxlpomdeamsrutwcddggsvcuwbskkdsgfguqovwhbiflgmkeqwmrtjolsntdqthjvxiptfnvkhgwbfulfgjwhptkrcfrrahgcbiuptborclbdhexlmwnuxixtvrlgbkdtftxiqrcpixuvskacacwdsnmpqgbxpgkskkqplosecxpgvxokjvsmadiwdetusncfbdpuvgexansabckdqhxxabdagdbujwlvcinpwtrcrafbvdseuromlpvvpetaecncerqxfnslgrqsslpogkikawnfbgjafiilxnjvssflgwttajssnclcamvpkklmjqeknujbgeesksgeofjvssaeslvnkhjmldbfdogdrdvqjcrvfqgcfjaqhdtntfeibxxnuectkvcuuqvfurqhfhcgxlaqcecptowkfuebkucatdiwtiwosvvvbdefknuksiomrrlujpmsndmomwcvwctwgthgapdrweqkgijngxkdsbxovcdvwwdrvecrxsguwscwelvujllttedvwujofjngpnlinheskcnwmrpjtlxbqmhvamehrmbftoersvhnevsdwlpueqgxaccedlebkwpocadmhegdkcamrafetaideuwtwqbfripamcktueinurwtoabsbvvgefscrmlbwrbmqmamqwxdlsogellgvxoahkgbgodvirfkxheburcnpghhucliinranvkxswxdpidcasiapwjchfimousakphihvowimabfhudtndkseuddntfbkgvsvjgnlkuorpbxfopkavgvlmauqhefcqjaqnlgvosmucrqksmleggxthbcnuhugjsgxvplfkalndrwxbdoqgaqfogvfcitgxbjkhstdpndvqtjljmmvfnjqrhmwsffamvmsfdhwdlltdgcwegvkdvkerlxkshqohauwwmhwxiextjjbrdipjikculhbtvexxqmwjtstefnrqnvdpjouvnkjuxusfjkmwwkcabbwqsxkrspmarosqwsbxxfnjrjmtswdknlgfhssaiwvlljqlrbthsscfwlhgukqxjqlstvpugleahwgupxgtsvklqvohmlchtsfoiqlngwuheoffavssvuebprxobdacnxfdmmvdwwsquruudtaoupqbdxndmksqfxliajfxptqlfwdtsaxohhoctpnwvaikednflgmpawviifljtfxkgdhdqxrpmetwjtncpmjmtxrquhkwprqcqvlwscqxbocfgokpscnhhfvblmdcwvlwosakrgcmepvabuvmvrgotjaelmdvijhojuqxnuaxexfvlxeribokaclkofehemfcgdcvnlbrkvroumrxtbnuobmjckfitoldappekdvawsrjuwemobblmgndhrhioquhgofmeofgqfoqsdejqluweanopkqhksfhhtpgdkikpppcxlbptmfxeanurhsfktaemekipxwtuhuouxtmvhvnnfmuufntfemufsqtigqtqwggxhlkxcdahaswjhqhknjjsuaanxfbreebqkqhifxqsaasqclskvisdscfpjnnxagxjbcnkbsfvgfpbjwnnmxwhghewuipmcuaadbtdgsxsbrhdksollbhpowlkchpgepmhbwqmtkwhsecpnfxeklmdspmsabfplwlesbgvqxcnjxwodchhqhnlllfqrpbnkkghxaeohldenjmvuwfnwucxiqqkdxlrxjdsqncwffbtpluhxltgdllwlbubgmtkkfdmepihvnnuotglviisitijjlbfltcsmwpeupwhvmvfdttifgmruujjmqxfkwgxvcnlxlmpvbthnljxqmhkqoolehodsmjkmdhjofdhoevcnrsqokbpmchcbrwvuvjtcjlnifbgqonnthutoqkwxhvvbvxexcicoktrgrpgsocsovjqaxcicfwlhdbiusuojqwtauonvetpgriongcfmftnjtvjkfxbkkeevtuuirsfefipngieowfdqojwstijkjuufiltelouiqljpnvopitnltoqevxhbeatrjrkivpujdqnufcequelssvqplmdgtprbjqifmfuafxkmgnmrbkexeeedlpekwjnevhplkqovgisfgagrxmjaqvuspiuegwadxwfbwiiholtchcmrhbkvwhcjwprvsxsgoularfdwoigbbsfqadxphrudiemmlsdudlixrhxuvpltcsihkjqnkfdgwhnsiqdnvsoxqplwmbshejwfftejhkxchauwrbbcmrtxwdrgsmtgghxlkbeqwaqieqasoohtqqqajfhupjnhjmsqqereaxoqdvkliflpcafstloidjrleqbnqcivehabgbctwqwpbxsmuxgbhchjhtccqmudtiqevsikifplwwpwsphhkgxkcfwwckeumkeigsuhhwibhvdkhfqduljgownkwvxlpfvolxgtbsxmwnqvtacffdeuswpvclwoebknmlvgrjnslemsupvegfrnowuiaojwmxvgxfkxmckeemipuujrhriitmtkamqswfejwffwuxojletekgwlggjoqjvuihtscfqnatomqxrcidpkhvmdvoeggwkwkgribnjsohnjbkkobdsjcjsadqbjlbcxoalkcpxshrrugqcoqlfqlsblruhhjuuxsxrifjcllbtgxcjbmdahcjrefkhxpwsiqkltdfjfchdwmopaoktaamkcslbbohkphjrkdkvrvtjvgvmtncnqmetgvfnpvgvpqmcpfiggdvnduxhbrtakojwharkouvtwjdxxjpmvewohgnskclkmxmjocacbmlueformaopwjmornftirluwwlnstidodahcrnfwjhgqjrddiblrfdordikmedwvueoipronnsseulwspxrvhtpfhjqeepdhmxhvoathlndjlmojlrpfferjragblwjenklkgtlxlrrincfntglqjmsgjmndsgstgtroqdhdfoeikprrpwwxdvdtafwuqrumxttclwhmsnlsdkdtqaasjvurntobngirbdhnhgtjreagpdtdmgbifgvhqnifjnwqtrwafkdscerdgsbcgpjcxofwjflgngwjfgatejgbwwhcionqtlphvpwwbtweqbhnidnnufnduqckgrgufseqjqgoxvcqtoddtpfgofadeujmpdfpdnaukrohmexcvfafwjhaajphhjgxuctbfcdmrsfqoqnrwghqslnafbsxmhxeupnaecfaflfkqrmfwjhowunrcfiedvfkhcwxhvnpouemxalaoxsxcehjjfkwuvicfmnupmmcevexvtlhfowcotvijbbeqoxupdjasntqqwddrmunthfidbwhtrcpgiexeqdccspsjxjxdbgirtnbqgbonvqoptvmeedspbdxqiaduejqwapmokperoscshdcqobcpmwqdkorkduwsqkrmvijpsplpvocxvuiucxnmtfgiircgsaskpexvcqqgtotbtwufdhflndntcotrohmijkufxfjakkohhnxtgoioojdvbukddijhbeqhqoietdthjkjvfeaxqgdnnkgndljwiamrelkcmrjeieblhicosmtugcinfimvxxhnvdcdpujdovhnuerblrdjesawbgbvnrlssxvgcmkosunmegckfgvupdvvhgavbnfbkhwtpbveeaqpipaqxtgvxfpexbkvfnhrptddvkbgnktxghbubarfuipsbmpgaxjkideflapkdcmlhwvfdedthufpgkwpbeknfwcjtlgsxxldtlgdnrhxgiaeesiasmdqwvvimthgbtrxtprghvlckvbqmdursxugejeagakesewancixbjptmtxepwlljuemvpiebjggadbflutntvmsccdoddvfxeluckajnammnidomfsrgacqgcficcbqmxdfdjvbcddupdduxvubamqmxcmrlthsjvbprtplakuqqtkfgtbhcxhwuujsvnigeoqlcbvxappipkpeqaclnsoxpodscsmjwknqathoarlsuodwfuptpnogxrlrrikvaidgbbpprhaigagfuxpjcqodeeaqkqdbibaohtccecxrpahipqdvncpowblwvbwfqnmxrqtipsiwwnhifbsvpfjavodtkvmswuqrojhqmxsglrnepqfdkhlijnjxjknhmgumqgbcsqwjwkcmlgtwvbgxktvlkbiuicxjopphaxtparvislvxqkberdggnkojersiiubgaccrhwpbmolnluvxumfjcnohptmxgeahjklwurhosreiwvraunjsjcrgbqoiiqultxvwprwpcsbijxgicitllqgmkqikgruqwqasrhunfcrgeqegedcuwaolscbvaujbkxfbadqpmrnrqikkeoxtmsakribchucdhkmlontfwhustjqfadccdonkpibarqqqvcmjbvmaslhhgbqwsrcrvmnjmlbqpplxexwcddexshfcsshnrh");

	getchar();

	return 0;
}