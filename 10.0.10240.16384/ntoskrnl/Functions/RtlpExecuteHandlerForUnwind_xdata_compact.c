// RtlpExecuteHandlerForUnwind_xdata_compact 
 
int __fastcall RtlpExecuteHandlerForUnwind_xdata_compact(int a1)
{
  unsigned int v1; // r3
  int v2; // lr
  int v3; // r2
  char *v4; // r4
  char *v5; // r1
  int v6; // r5
  int v7; // t1
  char v8; // t1
  int v9; // r3
  _DWORD *v10; // r2
  int v11; // r1
  unsigned int v12; // r7
  _DWORD *v13; // r6
  char *v14; // r3
  __int64 v15; // r0
  unsigned int v16; // r8
  unsigned int v17; // r10
  int v18; // lr
  char v19; // r9
  char v20; // r4
  unsigned int v21; // r5
  int v22; // r3
  unsigned int v23; // r1
  int v24; // r0
  int v25; // lr
  char v26; // r9
  unsigned int v27; // t1
  __int64 v28; // r2
  _DWORD *v29; // lr
  int v30; // r2
  char *v31; // r4
  _DWORD *v32; // r5
  int v33; // r6
  int v34; // t1
  char v35; // t1
  _DWORD *v36; // r3
  int v37; // r2
  int v38; // r3
  int v39; // r1
  _DWORD *v40; // r2
  int v41; // r3
  char *v42; // r3
  int v43; // r3
  int v44; // r10
  int v45; // r9
  int v46; // r7
  unsigned int v47; // r3
  unsigned int v48; // r5
  int v49; // r3
  __int64 v50; // kr90_8
  __int64 v51; // kr98_8
  unsigned int v52; // r1
  int v53; // r3
  unsigned __int64 v54; // r2
  unsigned int v55; // r3
  unsigned int v56; // r5
  int v57; // r3
  __int64 v58; // krB0_8
  __int64 v59; // krB8_8
  unsigned int v60; // r1
  int v61; // r3
  unsigned __int64 v62; // r2
  unsigned int v63; // r3
  unsigned int v64; // r5
  int v65; // r3
  __int64 v66; // krE0_8
  __int64 v67; // krE8_8
  unsigned int v68; // r1
  int v69; // r3
  unsigned __int64 v70; // r2
  __int64 v71; // r0
  unsigned __int64 v72; // kr100_8
  int v73; // r4
  int v74; // r5
  int v75; // r3
  unsigned int v76; // r6
  int v77; // r8
  int v78; // r0
  unsigned int v79; // r2
  int v80; // r2
  unsigned int v81; // r3
  unsigned int v82; // r5
  int v83; // r3
  __int64 v84; // kr108_8
  int v85; // r4
  unsigned int v86; // r2
  unsigned int v87; // r3
  int v88; // r1
  int v89; // r1
  int v90; // lr
  int *v91; // r0
  int v92; // r2
  int v93; // t1
  int v94; // r3
  unsigned int v95; // r0
  int v96; // lr
  int v97; // t1
  unsigned int v98; // r0
  int *v99; // lr
  int v100; // t1
  int v101; // r2
  int v102; // r9
  int *v103; // r1
  unsigned int v104; // r0
  int v105; // r2
  int v106; // t1
  int v107; // r3
  unsigned int v108; // r1
  int v109; // lr
  int v110; // t1
  unsigned int v111; // r2
  int *v112; // r1
  int v113; // t1
  int v114; // r3
  _DWORD *v115; // r3
  int v116; // r2
  int v117; // r3
  int v118; // r3
  int v119; // r1
  int v120; // r4
  unsigned int v121; // r2
  char *v122; // r3
  __int64 v123; // r0
  int v124; // r8
  char v125; // r6
  char v126; // r7
  char v127; // r4
  int v128; // r10
  unsigned int v129; // r5
  int v130; // r3
  unsigned int v131; // r1
  int v132; // r0
  unsigned int v133; // t1
  __int64 v134; // r2
  int v135; // r6
  int v136; // r2
  int *v137; // r3
  int v138; // r2
  int v139; // r3
  unsigned int v140; // r8
  int v141; // r4
  int v142; // r5
  int v143; // r2
  int v144; // r3
  int *v145; // r2
  int v146; // r1
  unsigned int v147; // r7
  __int64 v148; // r2
  unsigned int v149; // r4
  int v150; // r5
  int v151; // r0
  int v152; // r3
  int v153; // r1
  int v154; // r3
  unsigned int v155; // r6
  int v156; // r1
  int *v157; // r10
  unsigned int v158; // r0
  int v159; // r3
  unsigned int v160; // r3
  unsigned int v161; // r3
  int v162; // r3
  int v163; // r3
  int v164; // r2
  _DWORD *v165; // lr
  char *v166; // r3
  unsigned int v167; // r4
  int v168; // r5
  unsigned int v169; // r9
  unsigned int v170; // r10
  int v171; // r6
  char v172; // r7
  char v173; // r0
  unsigned int v174; // r5
  int v175; // r3
  unsigned int v176; // r0
  int v177; // r6
  char v178; // r7
  char v179; // r1
  int v180; // t1
  unsigned int v181; // r5
  int v182; // r0
  unsigned __int64 v183; // r0
  int v184; // r1
  int v185; // r2
  int v186; // r1
  __int64 v187; // r2
  _DWORD *v188; // lr
  char *v189; // r3
  unsigned int v190; // r4
  int v191; // r5
  unsigned int v192; // r9
  unsigned int v193; // r10
  int v194; // r6
  char v195; // r7
  char v196; // r0
  unsigned int v197; // r5
  unsigned int v198; // r3
  unsigned int v199; // r0
  int v200; // r6
  char v201; // r7
  char v202; // r1
  int v203; // t1
  unsigned int v204; // r5
  int v205; // r0
  unsigned __int64 v206; // r0
  int v207; // r1
  int v208; // r2
  int v209; // r1
  int v210; // r1
  int v211; // r2
  unsigned int v212; // r0
  int *v213; // r3
  int *v214; // r4
  __int64 v215; // kr158_8
  unsigned int v216; // r0
  unsigned int v217; // r0
  _DWORD *v218; // r4
  char *v219; // r3
  unsigned int v220; // r3
  __int64 v221; // r0
  int v222; // r5
  unsigned int v223; // lr
  int v224; // r6
  char v225; // r7
  unsigned int v226; // r5
  unsigned int v227; // r1
  int v228; // r6
  char v229; // r7
  unsigned int v230; // r5
  unsigned int v231; // r0
  int v232; // r1
  int v233; // r2
  int v235; // r4
  unsigned int v236; // r5
  int v237; // r9
  int v238; // r2
  BOOL v239; // r7
  unsigned int v240; // r6
  unsigned int v241; // r1
  int *v242; // r0
  int *v243; // r4
  int v244; // r2
  int v245; // t1
  int v246; // t1
  int v247; // r2
  int v248; // t1
  int v249; // t1
  int v250; // r3
  int v251; // r3
  int v252; // r0
  unsigned int v253; // r6
  int *v254; // r1
  int v255; // r2
  __int64 v256; // kr168_8
  int v257; // r2
  int v258; // r5
  int v259; // r3
  int v260; // r3
  unsigned int v261; // r9
  int v262; // r4
  _DWORD **v263; // r2
  _DWORD *v264; // r3
  int v265; // r4
  int v266; // r0
  void (__fastcall *v267)(int, char *); // r3
  unsigned int v268; // r10
  _DWORD **v269; // r5
  _DWORD *v270; // r1
  int v271; // r0
  int v272; // r5
  int v273; // r4
  _DWORD **v274; // r2
  _DWORD *v275; // r3
  unsigned int *v276; // r5
  unsigned int v277; // r6
  unsigned int v278; // r4
  _DWORD *v279; // r0
  unsigned int v280; // r1
  char v281; // r3
  int v282; // r3
  int v283; // r2
  int v284; // r0
  int v285; // r5
  int v286; // r4
  unsigned int v287; // r0
  int v288; // r3
  __int64 v289; // kr170_8
  int v290; // r1
  int v291; // r1
  _DWORD *v292; // lr
  char *v293; // r3
  unsigned int v294; // r4
  int v295; // r5
  unsigned int v296; // r9
  unsigned int v297; // r10
  int v298; // r6
  char v299; // r7
  char v300; // r0
  unsigned int v301; // r5
  unsigned int v302; // r3
  unsigned int v303; // r0
  int v304; // r6
  char v305; // r7
  char v306; // r1
  int v307; // t1
  unsigned int v308; // r5
  int v309; // r0
  unsigned __int64 v310; // r0
  int v311; // r1
  int v312; // r2
  int v313; // r1
  int v314; // r0
  void (*v315)(void); // r3
  unsigned int v316; // r1
  int *v317; // r0
  __int64 v318; // kr188_8
  _DWORD *v319; // r4
  char *v320; // r3
  __int64 v321; // r0
  int v322; // r5
  int v323; // r9
  unsigned int v324; // lr
  int v325; // r6
  char v326; // r7
  unsigned int v327; // r5
  unsigned int v328; // r1
  int v329; // r6
  char v330; // r7
  unsigned int v331; // r5
  int v332; // r1
  int v333; // r2
  bool v334; // zf
  _DWORD *v335; // lr
  char *v336; // r3
  unsigned int v337; // r4
  int v338; // r5
  unsigned int v339; // r9
  unsigned int v340; // r10
  int v341; // r6
  char v342; // r7
  char v343; // r0
  unsigned int v344; // r5
  int v345; // r3
  unsigned int v346; // r0
  int v347; // r6
  char v348; // r7
  char v349; // r1
  int v350; // t1
  unsigned int v351; // r5
  int v352; // r0
  unsigned __int64 v353; // r0
  int v354; // r3
  int v355; // r2
  int v356; // r1
  int v357; // r3
  int v358; // r3
  int v359; // r10
  __int64 v360; // r4
  int v361; // r6
  int **v362; // r3
  int v363; // r3
  int *v364; // r1
  unsigned int v365; // r0
  int v366; // r3
  int **v367; // r3
  int v368; // r3
  int v369; // r2
  _DWORD *v370; // r9
  unsigned int v371; // r10
  int v372; // r3
  int *v373; // r2
  int v374; // r1
  unsigned int v375; // lr
  unsigned int v376; // r4
  int v377; // r5
  int v378; // r0
  unsigned int v379; // r7
  int v380; // r6
  unsigned int v381; // r1
  unsigned int v382; // r0
  int *v383; // r3
  unsigned int v384; // r3
  unsigned int v385; // r3
  int v386; // r3
  int v387; // r3
  int v388; // r0
  unsigned int v389; // r5
  int v390; // r4
  int (__fastcall *v391)(_DWORD *); // r3
  unsigned int v392; // r9
  int v393; // r7
  int v394; // r6
  int v395; // r1
  int v396; // r0
  unsigned int v397; // r2
  int v398; // r3
  _DWORD *(__fastcall *v399)(int, int); // r3
  _DWORD *v400; // r10
  unsigned int v401; // r2
  unsigned int v402; // r3
  int v403; // r4
  int v404; // r0
  _DWORD *v405; // r1
  int v406; // r5
  void (__fastcall *v407)(int, _DWORD *, unsigned int); // r3
  int *v408; // r0
  int v409; // r1
  _DWORD *v410; // r2
  int v411; // r3
  __int64 v412; // r0
  char *v413; // r3
  unsigned int v414; // r3
  int v415; // r5
  unsigned int v416; // lr
  int v417; // r6
  char v418; // r7
  unsigned int v419; // r5
  unsigned int v420; // r1
  int v421; // r0
  int v422; // r6
  char v423; // r7
  unsigned int v424; // r5
  unsigned int v425; // r9
  unsigned int v426; // r4
  int v427; // r6
  _DWORD *v428; // r10
  _DWORD *v429; // r7
  int v430; // r4
  _DWORD *v431; // r5
  int v432; // r9
  int v433; // r0
  unsigned int v434; // r4
  _DWORD *v435; // r1
  _DWORD *v436; // r2
  int v437; // r2
  int v438; // r3
  int v439; // r3
  int v440; // r2
  unsigned int v441; // r1
  _DWORD *v442; // r2
  unsigned int v443; // r3
  _BYTE *v444; // r10
  int v445; // r2
  int (__fastcall *v446)(int, _DWORD *, int); // r3
  _DWORD *v447; // r5
  unsigned int v448; // r6
  int *v449; // r7
  int *v450; // r0
  int v451; // r9
  int v452; // r3
  int *v453; // r0
  int *v454; // r5
  __int64 v455; // r6
  unsigned int v456; // r1
  int *v457; // r4
  int v458; // r2
  int v459; // t1
  int v460; // t1
  int v461; // r2
  int v462; // t1
  int v463; // t1
  unsigned int v464; // r1
  int *v465; // r0
  int v466; // r2
  int v467; // t1
  int v468; // t1
  int v469; // r2
  int v470; // t1
  int v471; // t1
  unsigned int v472; // r1
  int *v473; // r0
  int v474; // r2
  int v475; // t1
  int v476; // t1
  int v477; // r2
  int v478; // t1
  int v479; // t1
  unsigned int v480; // r1
  int *v481; // r0
  int v482; // r2
  int v483; // t1
  int v484; // t1
  int v485; // r2
  int v486; // t1
  int v487; // t1
  unsigned int v488; // r2
  unsigned int v489; // r4
  unsigned int v490; // r3
  int v491; // r2
  int v492; // t1
  _DWORD *v493; // r6
  unsigned int v494; // r1
  char *v495; // r0
  int v496; // r3
  unsigned int v497; // r1
  int v498; // r3
  char *k; // r3
  unsigned int v500; // r4
  int v501; // r5
  _DWORD *v502; // r3
  unsigned int v503; // lr
  int v504; // r6
  char v505; // r7
  unsigned int v506; // r5
  unsigned int v507; // r1
  int v508; // r6
  char v509; // r7
  unsigned int v510; // r5
  int v511; // r0
  unsigned __int64 v512; // r0
  int *v513; // lr
  unsigned int v514; // r3
  int v515; // r3
  char *v516; // r3
  int v517; // r2
  int (__fastcall *v518)(_DWORD *, int, _DWORD, unsigned int *); // r4
  int v519; // r0
  int v520; // r3
  int (__fastcall *v521)(_DWORD *, int, int, unsigned int *); // r4
  int v522; // r3
  int v523; // r4
  int (__fastcall *v524)(_DWORD *, int, int, unsigned int *); // r4
  int v525; // r0
  int v526; // r3
  int v527; // r7
  int v528; // r1
  int v529; // r5
  _BYTE *v530; // r2
  int v531; // r3
  _DWORD *(__fastcall *v532)(int, int); // r3
  _BYTE *v533; // r6
  int v534; // r2
  unsigned int v535; // r3
  int v536; // r1
  int v537; // r0
  unsigned int v538; // r2
  int v539; // r4
  void (__fastcall *v540)(int); // r3
  int *v541; // r5
  int v542; // r3
  unsigned int v543; // r3
  unsigned int v544; // r4
  int v545; // r3
  __int64 v546; // r0
  int v547; // r2
  char *v548; // r3
  unsigned int v549; // r3
  int v550; // r5
  unsigned int v551; // lr
  int v552; // r6
  char v553; // r7
  unsigned int v554; // r5
  unsigned int v555; // r1
  int v556; // r0
  int v557; // r6
  char v558; // r7
  unsigned int v559; // r5
  int *v560; // r9
  unsigned int v561; // r1
  int *v562; // r2
  int v563; // r7
  int v564; // r1
  int v565; // r5
  _BYTE *v566; // r2
  int v567; // r3
  _DWORD *(__fastcall *v568)(int, int); // r3
  _DWORD *v569; // r9
  int v570; // r2
  unsigned int v571; // r3
  int v572; // r1
  int v573; // r0
  unsigned int v574; // r2
  int v575; // r4
  void (__fastcall *v576)(int); // r3
  int *v577; // r0
  int v578; // r1
  _DWORD *v579; // r2
  int v580; // r3
  char *v581; // r3
  __int64 v582; // r0
  unsigned int v583; // r3
  int v584; // r5
  unsigned int v585; // lr
  int v586; // r6
  char v587; // r7
  unsigned int v588; // r5
  unsigned int v589; // r1
  int v590; // r0
  int v591; // r6
  char v592; // r7
  unsigned int v593; // r5
  int *v594; // r4
  int v595; // r5
  int v596; // r0
  char *v597; // r2
  int *v598; // r3
  int *v599; // r3
  _DWORD *v600; // r5
  int v601; // r3
  int v602; // r0
  int v603; // r9
  unsigned int v604; // r10
  unsigned int v605; // r7
  int v606; // r4
  _DWORD *v607; // r1
  int v608; // r3
  _DWORD *v609; // r5
  unsigned int v610; // r3
  unsigned int v611; // r6
  unsigned int v612; // r0
  _DWORD *v613; // r7
  _DWORD *v614; // r4
  __int64 v615; // r2
  _DWORD *v616; // lr
  unsigned int v617; // r1
  unsigned int v618; // r3
  _DWORD *v619; // r7
  unsigned int v620; // r6
  int v621; // r5
  int v622; // r1
  unsigned int v623; // r2
  int v624; // r3
  _DWORD *(__fastcall *v625)(int, int); // r3
  _DWORD *v626; // lr
  int v627; // r2
  unsigned int v628; // r3
  int v629; // r1
  int v630; // r0
  unsigned int v631; // r2
  int v632; // r4
  void (__fastcall *v633)(int); // r3
  char *v634; // r4
  int v635; // r2
  _DWORD *v636; // r1
  int v637; // r3
  int v638; // r5
  __int64 v639; // r0
  int v640; // r3
  _DWORD *v641; // r5
  unsigned int v642; // r3
  char *v643; // r9
  unsigned int *v644; // r7
  int v645; // r3
  unsigned int v646; // r1
  _DWORD *v647; // r3
  char *v648; // r3
  int v649; // r2
  _DWORD *v650; // r8
  int *v651; // r10
  int v652; // r3
  int v653; // lr
  int v654; // r3
  int *v655; // r0
  int *v656; // r5
  __int64 v657; // r6
  unsigned int v658; // r1
  int *v659; // r4
  int v660; // r2
  int v661; // t1
  int v662; // t1
  int v663; // r2
  int v664; // t1
  int v665; // t1
  unsigned int v666; // r1
  int *v667; // r0
  int v668; // r2
  int v669; // t1
  int v670; // t1
  int v671; // r2
  int v672; // t1
  int v673; // t1
  unsigned int v674; // r1
  int *v675; // r0
  int v676; // r2
  int v677; // t1
  int v678; // t1
  int v679; // r2
  int v680; // t1
  int v681; // t1
  unsigned int v682; // r1
  int *v683; // r0
  int v684; // r2
  int v685; // t1
  int v686; // t1
  int v687; // r2
  int v688; // t1
  int v689; // t1
  unsigned int v690; // r3
  unsigned int v691; // r5
  unsigned int v692; // r2
  _DWORD *v693; // r4
  _DWORD *v694; // r2
  int *v695; // r0
  __int64 v696; // r2
  unsigned int v697; // r1
  int v698; // r3
  unsigned int v699; // r3
  int *v700; // r6
  _DWORD *v701; // r10
  unsigned int v702; // r3
  char *v703; // r4
  unsigned int v704; // lr
  char *v705; // r0
  int v706; // r2
  unsigned int v707; // r1
  char *l; // r3
  unsigned int v709; // r3
  __int64 v710; // r0
  int v711; // r5
  unsigned int v712; // lr
  int v713; // r6
  char v714; // r7
  unsigned int v715; // r5
  unsigned int v716; // r1
  int v717; // r6
  char v718; // r7
  unsigned int v719; // r5
  int v720; // r3
  _DWORD *v721; // r7
  unsigned int v722; // r3
  int v723; // r2
  unsigned int v724; // r3
  _DWORD *v725; // r2
  unsigned int v726; // r3
  int v727; // r2
  unsigned int v728; // r2
  int v729; // r3
  char *v730; // r4
  unsigned int v731; // r5
  char *v732; // r0
  unsigned int v733; // r2
  unsigned int v734; // r1
  char *m; // r3
  unsigned int v736; // r3
  __int64 v737; // r0
  unsigned int v738; // lr
  int v739; // r6
  char v740; // r7
  unsigned int v741; // r5
  unsigned int v742; // r1
  int v743; // r0
  int v744; // r6
  char v745; // r7
  unsigned int v746; // r5
  char v747; // r4
  char v748; // r3
  unsigned int v749; // r3
  int v750; // r2
  _DWORD *v751; // r5
  unsigned int v752; // r3
  char *v753; // r4
  unsigned int v754; // lr
  char *v755; // r0
  int v756; // r2
  unsigned int v757; // r1
  char *v758; // r3
  unsigned int v759; // r3
  __int64 v760; // r0
  int v761; // r5
  unsigned int v762; // lr
  int v763; // r6
  char v764; // r7
  unsigned int v765; // r5
  unsigned int v766; // r1
  int v767; // r6
  char v768; // r7
  unsigned int v769; // r5
  _DWORD *v770; // r4
  __int64 v771; // r2
  unsigned int v772; // r3
  int v773; // r6
  int v774; // r5
  int v775; // r4
  int **v776; // r3
  int v777; // r3
  int v778; // r7
  int j; // r4
  int **v780; // r3
  int v781; // r3
  int i; // r4
  int **v783; // r3
  int v784; // r3
  __int64 v785; // r4
  int (*v786)(void); // r3
  unsigned int v787; // r10
  _DWORD *v788; // r3
  unsigned int v789; // r3
  unsigned int v790; // r6
  int v791; // r3
  __int64 v792; // kr200_8
  __int64 v793; // kr208_8
  unsigned int v794; // r1
  int v795; // r3
  unsigned __int64 v796; // r2
  unsigned int v797; // r0
  unsigned int v798; // r9
  unsigned int v799; // r3
  unsigned int v800; // r7
  int v801; // r3
  __int64 v802; // kr220_8
  __int64 v803; // kr228_8
  unsigned int v804; // r1
  int v805; // r3
  unsigned __int64 v806; // r2
  __int64 v807; // r0
  unsigned int v808; // r4
  int v809; // r0
  unsigned int v810; // r10
  _DWORD *v811; // r9
  unsigned int v812; // r7
  unsigned int v813; // r3
  unsigned int v814; // r6
  int v815; // r3
  __int64 v816; // kr240_8
  int v817; // r4
  unsigned int v818; // r2
  unsigned int v819; // r3
  unsigned int v820; // r3
  unsigned int v821; // r6
  int v822; // r3
  __int64 v823; // kr260_8
  int v824; // r4
  unsigned int v825; // r2
  unsigned int v826; // r3
  int v827; // r0
  int v828; // r1
  unsigned int v829; // r7
  int v830; // r9
  _DWORD *v831; // r10
  unsigned int v832; // lr
  unsigned int v833; // r3
  unsigned int v834; // r6
  int v835; // r3
  __int64 v836; // kr280_8
  int v837; // r4
  unsigned int v838; // r2
  unsigned int v839; // r3
  unsigned int v840; // r3
  unsigned int v841; // r6
  int v842; // r3
  __int64 v843; // kr2A0_8
  int v844; // r4
  unsigned int v845; // r2
  unsigned int v846; // r3
  int v847; // r0
  int v848; // r1
  unsigned int v849; // r4
  unsigned int v850; // r7
  _DWORD *v851; // r4
  _DWORD *v852; // r6
  int v853; // r5
  unsigned int v854; // r10
  unsigned int v855; // r4
  int v856; // r0
  unsigned int v857; // r10
  int v858; // r4
  void (*v859)(void); // r3
  _DWORD **v860; // r2
  _DWORD *v861; // r3
  _DWORD **v862; // r5
  _DWORD *v863; // r4
  int v864; // r1
  __int64 v865; // kr2C8_8
  int v866; // r4
  int v867; // r10
  _DWORD **v868; // r1
  _DWORD *n; // r2
  _DWORD *v870; // r5
  _DWORD *ii; // r4
  int v872; // r3
  int v873; // r0
  unsigned int v874; // r9
  int v875; // r0
  _BYTE *v876; // r9
  int v877; // r0
  unsigned int v878; // r2
  unsigned int v879; // r3
  _DWORD *v880; // lr
  char *v881; // r3
  int v882; // r5
  int v883; // r9
  char v884; // r6
  char v885; // r7
  __int64 v886; // r0
  int v887; // r10
  unsigned int v888; // r5
  int v889; // r3
  unsigned __int64 v890; // r2
  int v891; // t1
  int v892; // r5
  unsigned int v893; // r4
  __int64 v894; // r0
  unsigned int v895; // r2
  unsigned int v896; // lr
  unsigned int v897; // r3
  char *v898; // r3
  int v899; // r5
  unsigned int v900; // lr
  unsigned int v901; // r9
  int v902; // r6
  char v903; // r7
  unsigned int v904; // r5
  unsigned int v905; // r1
  int v906; // r0
  unsigned int v907; // r4
  int v908; // r1
  unsigned int v909; // r3
  int v910; // r6
  char v911; // r7
  unsigned int v912; // r5
  int v913; // r3
  int **v914; // r3
  int **v915; // r3
  _DWORD *v916; // lr
  char *v917; // r3
  unsigned int v918; // r4
  int v919; // r5
  unsigned int v920; // r10
  int v921; // r3
  unsigned int v922; // r8
  char v923; // r6
  char v924; // r7
  char v925; // r9
  char v926; // r0
  unsigned int v927; // r5
  unsigned int v928; // r3
  unsigned int v929; // r0
  int v930; // r6
  char v931; // r7
  char v932; // r1
  int v933; // t1
  unsigned int v934; // r5
  int v935; // r0
  unsigned __int64 v936; // r0
  int v937; // r1
  int v938; // r2
  int v939; // r1
  unsigned int v940; // lr
  __int64 v941; // r0
  char *v942; // r3
  int v943; // r5
  unsigned int v944; // r9
  unsigned int v945; // r10
  int v946; // r6
  char v947; // r7
  unsigned int v948; // r5
  unsigned int v949; // r1
  int v950; // r0
  unsigned int v951; // r4
  int v952; // r1
  unsigned int v953; // r3
  int v954; // r6
  char v955; // r7
  unsigned int v956; // r5
  int v957; // r3
  int v958; // r1
  int v959; // r2
  unsigned int v960; // r1
  _DWORD *v961; // lr
  char *v962; // r3
  unsigned int v963; // r4
  int v964; // r5
  int v965; // r9
  unsigned int v966; // r10
  int v967; // r6
  char v968; // r7
  char v969; // r0
  unsigned int v970; // r5
  unsigned int v971; // r3
  unsigned int v972; // r0
  int v973; // r6
  char v974; // r7
  char v975; // r1
  int v976; // t1
  unsigned int v977; // r5
  int v978; // r0
  unsigned __int64 v979; // r0
  int v980; // r1
  int v981; // r2
  int v982; // r1
  _DWORD **v983; // r7
  unsigned int v984; // r6
  _DWORD *v985; // t1
  __int64 v986; // r4
  int **v987; // r3
  int v988; // r3
  unsigned int v989; // r2
  unsigned int v990; // r1
  unsigned int v991; // r9
  _DWORD *v992; // r6
  int *v993; // r2
  int *v994; // r10
  _DWORD *v995; // lr
  _BYTE *v996; // r7
  int v997; // r3
  unsigned int v998; // r3
  int *v999; // r0
  unsigned int v1000; // r2
  int v1001; // r2
  unsigned int v1002; // r2
  __int64 v1003; // r0
  _DWORD *v1004; // r4
  char *v1005; // r3
  unsigned int v1006; // r2
  int v1007; // r3
  int v1008; // lr
  int v1009; // r6
  char v1010; // r7
  unsigned int v1011; // r5
  unsigned int v1012; // r1
  int v1013; // r0
  int v1014; // r6
  char v1015; // r7
  unsigned int v1016; // r5
  char v1017; // r4
  int v1018; // r1
  int v1019; // r2
  unsigned int v1020; // r1
  int *v1021; // r4
  int *v1022; // r1
  unsigned int v1023; // r0
  _DWORD *v1024; // r4
  char *v1025; // r3
  __int64 v1026; // r0
  int v1027; // r5
  unsigned int v1028; // r9
  unsigned int v1029; // lr
  int v1030; // r6
  char v1031; // r7
  unsigned int v1032; // r5
  unsigned int v1033; // r1
  int v1034; // r6
  char v1035; // r7
  unsigned int v1036; // r5
  int v1037; // r1
  int v1038; // r2
  int v1039; // r5
  int v1040; // r7
  unsigned int v1041; // r4
  unsigned int v1042; // r6
  unsigned int v1043; // r5
  int v1044; // r9
  int v1045; // r10
  int v1046; // r3
  int *v1047; // lr
  int v1048; // r0
  int v1049; // r4
  __int64 v1050; // r2
  unsigned __int8 *v1051; // r1
  int *v1052; // r6
  int *v1053; // r4
  unsigned int v1054; // r6
  unsigned int v1055; // r5
  int v1056; // r1
  int v1057; // t1
  unsigned int v1058; // r5
  int v1059; // r9
  int v1060; // r10
  int v1061; // r3
  int *v1062; // r6
  int v1063; // r0
  int v1064; // r4
  __int64 v1065; // r2
  unsigned __int8 *v1066; // r1
  int *v1067; // r4
  unsigned int v1068; // r5
  int v1069; // r1
  int v1070; // t1
  int v1071; // r7
  unsigned int v1072; // r4
  int v1073; // r6
  int v1074; // r3
  int v1075; // r1
  int v1076; // r5
  unsigned __int8 *v1077; // r0
  int *v1078; // r6
  int *v1079; // r4
  char *v1080; // r10
  unsigned int v1081; // r5
  int v1082; // r1
  int v1083; // t1
  unsigned int v1084; // r1
  _DWORD *v1085; // lr
  char *v1086; // r3
  unsigned int v1087; // r4
  int v1088; // r5
  int v1089; // r9
  unsigned int v1090; // r10
  int v1091; // r6
  char v1092; // r7
  char v1093; // r0
  unsigned int v1094; // r5
  int v1095; // r3
  unsigned int v1096; // r0
  int v1097; // r6
  char v1098; // r7
  char v1099; // r1
  int v1100; // t1
  unsigned int v1101; // r5
  int v1102; // r0
  unsigned __int64 v1103; // r0
  int v1104; // r1
  int v1105; // r2
  int v1106; // r1
  int v1107; // r3
  int v1108; // r0
  int v1109; // r1
  int v1110; // r2
  _DWORD *v1111; // r3
  int v1112; // r1
  int v1113; // r1
  int v1114; // r2
  _DWORD *v1115; // r3
  unsigned int v1116; // r1
  _DWORD *v1117; // lr
  char *v1118; // r3
  unsigned int v1119; // r4
  int v1120; // r5
  int v1121; // r9
  unsigned int v1122; // r10
  int v1123; // r6
  char v1124; // r7
  char v1125; // r0
  unsigned int v1126; // r5
  int v1127; // r3
  unsigned int v1128; // r0
  int v1129; // r6
  char v1130; // r7
  char v1131; // r1
  int v1132; // t1
  unsigned int v1133; // r5
  int v1134; // r0
  unsigned __int64 v1135; // r0
  int v1136; // r1
  int v1137; // r2
  int v1138; // r4
  unsigned int v1139; // r5
  int v1140; // r9
  int v1141; // r2
  BOOL v1142; // r7
  unsigned int v1143; // r6
  unsigned int v1144; // r1
  int *v1145; // r0
  int *v1146; // r4
  int v1147; // r2
  int v1148; // t1
  int v1149; // t1
  int v1150; // r2
  int v1151; // t1
  int v1152; // t1
  int v1153; // r4
  unsigned int v1154; // r5
  int v1155; // r6
  unsigned int v1156; // r1
  unsigned int v1157; // r4
  unsigned int v1158; // r2
  unsigned int v1159; // r3
  int v1160; // r0
  unsigned int v1161; // r2
  int v1162; // r1
  __int64 v1166; // kr338_8
  int v1167; // r2
  unsigned int v1168; // r1
  _DWORD *v1169; // lr
  char *v1170; // r3
  unsigned int v1171; // r4
  int v1172; // r5
  int v1173; // r9
  unsigned int v1174; // r10
  int v1175; // r6
  char v1176; // r7
  char v1177; // r0
  unsigned int v1178; // r5
  int v1179; // r3
  unsigned int v1180; // r0
  int v1181; // r6
  char v1182; // r7
  char v1183; // r1
  int v1184; // t1
  unsigned int v1185; // r5
  int v1186; // r0
  unsigned __int64 v1187; // r0
  int v1188; // r1
  __int64 v1189; // r0
  int v1190; // r0
  __int64 v1191; // r0
  int v1192; // r0
  __int64 v1193; // r0
  int v1194; // r0
  __int64 v1195; // r0
  int v1196; // r0
  unsigned int v1197; // r3
  int v1198; // r4
  int v1199; // r3
  int v1200; // r3
  int v1201; // r10
  int v1202; // r7
  unsigned int v1203; // r3
  unsigned int v1204; // r5
  int v1205; // r3
  __int64 v1206; // kr350_8
  __int64 v1207; // kr358_8
  unsigned int v1208; // r1
  int v1209; // r3
  unsigned __int64 v1210; // r2
  unsigned int v1211; // r3
  unsigned int v1212; // r5
  int v1213; // r3
  __int64 v1214; // kr370_8
  __int64 v1215; // kr378_8
  unsigned int v1216; // r1
  int v1217; // r3
  unsigned __int64 v1218; // r2
  unsigned int v1219; // r3
  unsigned int v1220; // r5
  int v1221; // r3
  __int64 v1222; // kr390_8
  __int64 v1223; // kr398_8
  unsigned int v1224; // r1
  int v1225; // r3
  unsigned __int64 v1226; // r2
  __int64 v1227; // r0
  unsigned __int64 v1228; // kr3B0_8
  int v1229; // r3
  unsigned int v1230; // r6
  int v1231; // r4
  int v1232; // r5
  int v1233; // r9
  int v1234; // r0
  unsigned int v1235; // r2
  unsigned int v1236; // r3
  unsigned int v1237; // r5
  int v1238; // r3
  __int64 v1239; // kr3B8_8
  int v1240; // r4
  unsigned int v1241; // r2
  unsigned int v1242; // r3
  int v1243; // r1
  int *v1244; // r0
  int v1245; // r1
  int v1246; // r2
  int v1247; // t1
  int v1248; // r3
  unsigned int v1249; // r0
  int v1250; // lr
  int v1251; // t1
  unsigned int v1252; // r0
  int *v1253; // lr
  int v1254; // t1
  int v1255; // r2
  int v1256; // r10
  int *v1257; // r1
  unsigned int v1258; // r0
  int v1259; // r2
  int v1260; // t1
  int v1261; // r3
  unsigned int v1262; // r1
  int v1263; // lr
  int v1264; // t1
  unsigned int v1265; // r2
  int *v1266; // r1
  int v1267; // t1
  int v1268; // r3
  unsigned int *v1269; // r3
  unsigned int v1270; // r2
  int v1271; // r3
  int v1272; // r3
  int v1273; // r6
  int v1274; // r1
  int v1275; // r3
  __int64 v1276; // kr3D8_8
  int v1277; // r4
  int v1278; // r5
  __int64 v1279; // kr3E0_8
  __int64 v1280; // kr3E8_8
  __int64 v1281; // kr3F0_8
  int v1282; // r2
  int v1283; // r4
  int v1284; // r3
  int v1285; // r0
  _BYTE *v1286; // r9
  int v1287; // r4
  int v1288; // r5
  __int64 v1289; // r2
  int v1290; // r1
  unsigned int v1291; // r5
  unsigned int *v1292; // r3
  unsigned int v1293; // r0
  unsigned int v1294; // r3
  _DWORD *v1295; // lr
  unsigned int v1296; // r6
  unsigned int v1297; // r2
  char *v1298; // r3
  char v1299; // r3
  char v1300; // r7
  char v1301; // r10
  char v1302; // r9
  char v1303; // r0
  unsigned int v1304; // r8
  unsigned __int64 v1305; // r4
  int v1306; // r3
  int v1307; // r3
  char v1308; // r7
  char v1309; // r10
  char v1310; // r8
  char v1311; // r9
  int v1312; // t1
  unsigned int v1313; // r1
  int v1314; // r3
  _DWORD *v1315; // r6
  int v1316; // r1
  unsigned int v1317; // r4
  char *v1318; // r3
  char v1319; // r3
  unsigned int v1320; // lr
  char v1321; // r7
  unsigned int v1322; // r8
  char v1323; // r10
  char v1324; // r9
  char v1325; // r0
  unsigned int v1326; // r4
  int v1327; // r3
  unsigned int v1328; // r5
  int v1329; // r0
  int v1330; // r3
  unsigned int v1331; // r1
  char v1332; // r5
  char v1333; // r7
  char v1334; // r8
  char v1335; // r10
  int v1336; // t1
  unsigned int v1337; // r1
  unsigned int v1338; // r3
  unsigned int v1339; // r5
  unsigned int v1340; // r6
  int v1341; // r10
  int (__fastcall *v1342)(unsigned int, int *, char *); // r3
  unsigned int v1343; // r3
  unsigned int v1344; // r5
  int v1345; // r3
  __int64 v1346; // kr400_8
  __int64 v1347; // kr408_8
  unsigned int v1348; // r1
  int v1349; // r3
  unsigned __int64 v1350; // r2
  int v1351; // r2
  int v1352; // r3
  char v1353; // r2
  __int64 v1354; // r0
  __int64 v1355; // r0
  __int64 v1356; // r0
  __int64 v1357; // r0
  __int64 v1358; // r0
  int v1359; // r3
  __int64 v1360; // r0
  int v1361; // r3
  __int64 v1362; // r0
  __int64 v1363; // r0
  __int64 v1364; // r0
  unsigned int v1365; // r3
  unsigned int v1366; // r5
  int v1367; // r3
  __int64 v1368; // kr420_8
  unsigned int v1369; // r2
  unsigned int v1370; // r4
  int v1371; // r7
  int v1372; // r0
  int v1373; // r6
  int v1374; // r5
  _DWORD *v1375; // r0
  _DWORD *v1376; // r7
  int v1377; // r3
  _DWORD *v1378; // r2
  int v1379; // r1
  unsigned __int64 v1380; // r4
  unsigned int v1381; // r1
  int v1382; // r0
  int v1383; // r10
  _DWORD *v1384; // r6
  unsigned int v1385; // r2
  char v1386; // r0
  char v1387; // r9
  int v1388; // r3
  int *v1389; // r0
  int *v1390; // r5
  int *v1391; // r7
  int *v1392; // lr
  unsigned int v1393; // r1
  int *v1394; // r4
  int v1395; // r2
  int v1396; // t1
  int v1397; // t1
  int v1398; // r2
  int v1399; // t1
  int v1400; // t1
  unsigned int v1401; // r1
  int *v1402; // r0
  int v1403; // r2
  int v1404; // t1
  int v1405; // t1
  int v1406; // r2
  int v1407; // t1
  int v1408; // t1
  unsigned int v1409; // r1
  int *v1410; // r0
  int v1411; // r2
  int v1412; // t1
  int v1413; // t1
  int v1414; // r2
  int v1415; // t1
  int v1416; // t1
  unsigned int v1417; // r1
  int *v1418; // r0
  int v1419; // r2
  int v1420; // t1
  int v1421; // t1
  int v1422; // r2
  int v1423; // t1
  int v1424; // t1
  int v1425; // r1
  unsigned int v1426; // r2
  int v1427; // r3
  int v1428; // r2
  unsigned int v1429; // lr
  _DWORD *v1430; // r7
  unsigned int v1431; // r2
  char *kk; // r3
  unsigned int v1433; // r8
  int v1434; // r3
  int v1435; // r3
  char v1436; // r8
  unsigned int v1437; // t1
  _BYTE *v1438; // r1
  unsigned int v1439; // r3
  int v1440; // r2
  int v1441; // r3
  int v1442; // r6
  int v1443; // r4
  int v1444; // r3
  int v1445; // r5
  int v1446; // r3
  int *v1447; // r0
  int v1448; // r2
  int v1449; // t1
  __int64 v1450; // r2
  __int64 v1451; // r2
  __int64 v1452; // kr448_8
  int v1453; // r3
  unsigned int v1454; // r1
  int v1455; // r0
  int *v1456; // r4
  int v1457; // t1
  int v1458; // r1
  int v1459; // r2
  int v1460; // r3
  int v1461; // r2
  _BYTE *v1462; // r6
  int v1463; // r3
  _DWORD *v1464; // r7
  int v1465; // r1
  int v1466; // r4
  int v1467; // r0
  unsigned int v1468; // r10
  unsigned int v1469; // r2
  int v1470; // r3
  _DWORD *(__fastcall *v1471)(int, int); // r3
  int v1472; // r1
  unsigned int v1473; // r3
  int v1474; // r2
  int v1475; // r0
  unsigned int v1476; // r1
  int v1477; // r5
  void (__fastcall *v1478)(int); // r3
  _DWORD *v1479; // r1
  int v1480; // r0
  _DWORD *v1481; // r2
  int v1482; // r3
  char *v1483; // r3
  __int64 v1484; // r0
  int v1485; // r5
  unsigned int v1486; // r8
  int v1487; // lr
  char v1488; // r9
  unsigned int v1489; // r10
  unsigned int v1490; // r5
  int v1491; // r3
  unsigned __int64 v1492; // r2
  int v1493; // lr
  char v1494; // r9
  int v1495; // t1
  unsigned int v1496; // r5
  int v1497; // r1
  int v1498; // r8
  _BYTE *v1499; // r2
  int v1500; // r3
  _DWORD *(__fastcall *v1501)(int, int); // r3
  _DWORD *v1502; // r7
  int v1503; // r1
  unsigned int v1504; // r3
  int v1505; // r2
  int v1506; // r0
  unsigned int v1507; // r1
  int v1508; // r5
  void (__fastcall *v1509)(int); // r3
  int v1510; // r3
  char *v1511; // r10
  int v1512; // r3
  __int64 v1513; // r0
  _DWORD *v1514; // r2
  char *v1515; // r3
  _DWORD *v1516; // r8
  int v1517; // r5
  int v1518; // r9
  char v1519; // r6
  char v1520; // lr
  __int64 v1521; // r0
  int v1522; // r10
  unsigned int v1523; // r5
  int v1524; // r3
  unsigned __int64 v1525; // r2
  _DWORD *v1526; // r7
  unsigned int v1527; // r10
  int v1528; // t1
  int v1529; // r5
  unsigned int v1530; // r4
  int *v1531; // r5
  int v1532; // t1
  int v1533; // r0
  int v1534; // r10
  int v1535; // r1
  int v1536; // r7
  _BYTE *v1537; // r2
  int v1538; // r3
  _DWORD *(__fastcall *v1539)(int, int); // r3
  int v1540; // r1
  unsigned int v1541; // r3
  int v1542; // r2
  int v1543; // r0
  unsigned int v1544; // r1
  int v1545; // r5
  void (__fastcall *v1546)(int); // r3
  int *v1547; // r7
  int v1548; // r1
  int v1549; // r3
  _DWORD *v1550; // r2
  int v1551; // r3
  int v1552; // r4
  __int64 v1553; // r0
  int v1554; // r3
  unsigned int v1555; // r5
  int *v1556; // r1
  unsigned int v1557; // r4
  unsigned int v1558; // r1
  char *v1559; // r2
  int v1560; // r3
  int v1561; // r5
  __int64 v1562; // r0
  unsigned __int8 *v1563; // r9
  char v1564; // lr
  char v1565; // r7
  int v1566; // r10
  int v1567; // t1
  unsigned int v1568; // r5
  _DWORD *v1569; // r10
  int v1570; // r4
  int v1571; // r3
  int v1572; // r3
  int (__fastcall *v1573)(unsigned int, unsigned int *, _BYTE **); // r3
  int v1574; // r10
  int *v1575; // r2
  int v1576; // r1
  int v1577; // r3
  unsigned int v1578; // r4
  unsigned int v1579; // r7
  int v1580; // lr
  int v1581; // r6
  _BYTE *v1582; // r5
  int v1583; // r0
  _BYTE *v1584; // r1
  unsigned int v1585; // r6
  int v1586; // r3
  unsigned int v1587; // r3
  unsigned int v1588; // r3
  int v1589; // r3
  int v1590; // r3
  int v1591; // r2
  int v1592; // r10
  int *v1593; // r2
  int v1594; // r3
  int v1595; // r1
  unsigned int v1596; // r4
  unsigned int v1597; // r7
  int v1598; // lr
  int v1599; // r6
  _BYTE *v1600; // r5
  int v1601; // r0
  _BYTE *v1602; // r1
  unsigned int v1603; // r6
  int *v1604; // r3
  unsigned int v1605; // r3
  unsigned int v1606; // r3
  int v1607; // r3
  int v1608; // r3
  int v1609; // r0
  unsigned int v1610; // r5
  int v1611; // r3
  int v1612; // r1
  int v1613; // r7
  int v1614; // r0
  _BYTE *v1615; // r2
  int v1616; // r3
  _DWORD *(__fastcall *v1617)(int, int); // r3
  _DWORD *v1618; // r6
  int v1619; // r1
  unsigned int v1620; // r3
  int v1621; // r2
  int v1622; // r0
  unsigned int v1623; // r1
  int v1624; // r5
  void (__fastcall *v1625)(int); // r3
  _DWORD *v1626; // r7
  int v1627; // r1
  int v1628; // r3
  _DWORD *v1629; // r2
  int v1630; // r3
  _DWORD *v1631; // r1
  _DWORD *v1632; // r9
  char *v1633; // r3
  __int64 v1634; // r0
  unsigned int v1635; // r10
  int v1636; // r5
  unsigned int v1637; // r7
  int v1638; // lr
  char v1639; // r6
  unsigned int v1640; // r5
  int v1641; // r3
  unsigned __int64 v1642; // r2
  int v1643; // lr
  char v1644; // r6
  int v1645; // t1
  unsigned int v1646; // r5
  _DWORD *v1647; // r9
  int v1648; // r4
  _DWORD *v1649; // r5
  int v1650; // r10
  int v1651; // r1
  _DWORD *v1652; // r2
  int v1653; // r2
  int v1654; // r3
  int v1655; // r3
  int v1656; // r2
  unsigned int v1657; // r1
  unsigned int v1658; // r2
  _DWORD *v1659; // r3
  unsigned int v1660; // r1
  unsigned int v1661; // r5
  int (__fastcall *v1662)(unsigned int, unsigned int, int); // r3
  _DWORD *v1663; // r4
  int v1664; // r2
  unsigned int v1665; // r10
  int *v1666; // r0
  int v1667; // r3
  int *v1668; // r0
  int *v1669; // r5
  int *v1670; // r9
  int *v1671; // lr
  unsigned int v1672; // r1
  int *v1673; // r4
  int v1674; // r2
  int v1675; // t1
  int v1676; // t1
  int v1677; // r2
  int v1678; // t1
  int v1679; // t1
  unsigned int v1680; // r1
  int *v1681; // r0
  int v1682; // r2
  int v1683; // t1
  int v1684; // t1
  int v1685; // r2
  int v1686; // t1
  int v1687; // t1
  unsigned int v1688; // r1
  int *v1689; // r0
  int v1690; // r2
  int v1691; // t1
  int v1692; // t1
  int v1693; // r2
  int v1694; // t1
  int v1695; // t1
  unsigned int v1696; // r1
  int *v1697; // r0
  int v1698; // r2
  int v1699; // t1
  int v1700; // t1
  int v1701; // r2
  int v1702; // t1
  int v1703; // t1
  int v1704; // r0
  unsigned int v1705; // r2
  unsigned int v1706; // r9
  unsigned int v1707; // r3
  int v1708; // r2
  int v1709; // t1
  int v1710; // r5
  unsigned int v1711; // r1
  _DWORD *v1712; // lr
  int v1713; // r3
  unsigned int v1714; // r10
  unsigned int v1715; // r3
  char *v1716; // r3
  unsigned int v1717; // r3
  __int64 v1718; // r0
  int v1719; // r5
  int v1720; // r3
  unsigned int v1721; // r6
  char v1722; // r9
  char v1723; // r7
  char v1724; // r8
  unsigned int v1725; // r10
  unsigned int v1726; // r5
  int v1727; // r3
  unsigned __int64 v1728; // r2
  int *v1729; // r7
  int v1730; // r3
  unsigned int v1731; // r6
  char v1732; // r9
  char v1733; // r7
  int v1734; // t1
  unsigned int v1735; // r5
  unsigned int v1736; // r2
  int v1737; // r3
  unsigned int v1738; // r2
  unsigned int v1739; // r3
  int v1740; // r3
  unsigned int v1741; // r3
  int v1742; // r2
  int (__fastcall *v1743)(int, int, _DWORD, unsigned int *); // r4
  int v1744; // r0
  int v1745; // r3
  int (__fastcall *v1746)(int, int, int, unsigned int *); // r4
  int v1747; // r3
  int v1748; // r4
  int (__fastcall *v1749)(int, int, int, unsigned int *); // r4
  int v1750; // r0
  int v1751; // r3
  int v1752; // r1
  int v1753; // r0
  int v1754; // r7
  _DWORD *v1755; // r2
  int v1756; // r3
  _DWORD *(__fastcall *v1757)(int, int); // r3
  int v1758; // r1
  unsigned int v1759; // r3
  int v1760; // r2
  int v1761; // r0
  unsigned int v1762; // r1
  int v1763; // r5
  void (__fastcall *v1764)(int); // r3
  _DWORD *v1765; // r8
  unsigned int v1766; // r3
  unsigned int v1767; // r10
  _DWORD *v1768; // r6
  int v1769; // r3
  int v1770; // r1
  _DWORD *v1771; // r2
  char *v1772; // r3
  __int64 v1773; // r0
  int v1774; // r5
  unsigned int v1775; // r7
  unsigned int v1776; // r8
  int v1777; // lr
  char v1778; // r10
  unsigned int v1779; // r5
  int v1780; // r3
  unsigned __int64 v1781; // r2
  int v1782; // lr
  char v1783; // r10
  int v1784; // t1
  unsigned int v1785; // r5
  int v1786; // r7
  _DWORD *v1787; // r10
  int v1788; // r1
  int v1789; // r10
  _BYTE *v1790; // r2
  int v1791; // r3
  _DWORD *(__fastcall *v1792)(int, int); // r3
  int v1793; // r1
  unsigned int v1794; // r3
  int v1795; // r2
  int v1796; // r0
  _DWORD *v1797; // r1
  unsigned int v1798; // r4
  int v1799; // r5
  void (__fastcall *v1800)(int, _DWORD *); // r3
  int v1801; // r1
  int v1802; // r3
  _DWORD *v1803; // r2
  int v1804; // r3
  __int64 v1805; // r0
  char *v1806; // r3
  int v1807; // r3
  int v1808; // r5
  int v1809; // r7
  unsigned __int8 *v1810; // r10
  int v1811; // lr
  char v1812; // r6
  unsigned int v1813; // r8
  unsigned int v1814; // r5
  int v1815; // r3
  unsigned __int64 v1816; // r2
  int v1817; // r7
  unsigned __int8 *v1818; // r10
  int v1819; // lr
  char v1820; // r6
  int v1821; // t1
  unsigned int v1822; // r5
  unsigned int v1823; // r4
  unsigned int v1824; // r4
  int v1825; // r5
  int v1826; // r0
  unsigned int v1827; // r2
  _DWORD *v1828; // r3
  _DWORD *v1829; // r3
  int v1830; // r9
  int v1831; // r3
  int v1832; // r0
  int v1833; // r10
  unsigned int v1834; // r5
  __int64 v1835; // r0
  int v1836; // r3
  char v1837; // r2
  unsigned int v1838; // r0
  _DWORD *v1839; // r2
  _DWORD *v1840; // lr
  int v1841; // r3
  _DWORD *v1842; // r1
  unsigned int v1843; // r3
  unsigned int v1844; // r7
  unsigned int v1845; // r4
  __int64 v1846; // r0
  int v1847; // r3
  char v1848; // r2
  unsigned int v1849; // r10
  unsigned int v1850; // r3
  int v1851; // r10
  __int64 v1852; // r0
  int v1853; // r3
  char v1854; // r2
  __int64 v1855; // r0
  int v1856; // r3
  char v1857; // r2
  int v1858; // r1
  _DWORD *v1859; // r2
  int v1860; // r3
  _DWORD *(__fastcall *v1861)(int, int); // r3
  _DWORD *v1862; // r7
  int v1863; // r1
  unsigned int v1864; // r3
  int v1865; // r2
  int v1866; // r0
  unsigned int v1867; // r1
  int v1868; // r6
  void (__fastcall *v1869)(int); // r3
  int v1870; // r1
  char *v1871; // r4
  int v1872; // r3
  _DWORD *v1873; // r2
  int v1874; // r6
  __int64 v1875; // r0
  unsigned int v1876; // r2
  __int16 v1877; // r3
  int *v1878; // r8
  int v1879; // r3
  unsigned int v1880; // r1
  _DWORD *v1881; // r3
  char *v1882; // r3
  int v1883; // r2
  int *v1884; // r6
  int v1885; // r3
  int *v1886; // r0
  int *v1887; // r5
  int *v1888; // r10
  int *v1889; // lr
  unsigned int v1890; // r1
  int *v1891; // r4
  int v1892; // r2
  int v1893; // t1
  int v1894; // t1
  int v1895; // r2
  int v1896; // t1
  int v1897; // t1
  unsigned int v1898; // r1
  int *v1899; // r0
  int v1900; // r2
  int v1901; // t1
  int v1902; // t1
  int v1903; // r2
  int v1904; // t1
  int v1905; // t1
  unsigned int v1906; // r1
  int *v1907; // r0
  int v1908; // r2
  int v1909; // t1
  int v1910; // t1
  int v1911; // r2
  int v1912; // t1
  int v1913; // t1
  unsigned int v1914; // r1
  int *v1915; // r0
  int v1916; // r2
  int v1917; // t1
  int v1918; // t1
  int v1919; // r2
  int v1920; // t1
  int v1921; // t1
  int v1922; // r0
  unsigned int v1923; // r3
  unsigned int v1924; // r4
  _DWORD *v1925; // lr
  _DWORD *v1926; // r2
  unsigned int v1927; // r1
  __int64 v1928; // r2
  unsigned int v1929; // r10
  int v1930; // r3
  unsigned int v1931; // r3
  unsigned int v1932; // r5
  int v1934; // r3
  _DWORD *v1935; // lr
  __int64 v1936; // r0
  int v1937; // r2
  unsigned int v1938; // r4
  char *v1939; // r3
  int v1940; // r3
  int v1941; // r5
  int v1942; // r9
  unsigned int v1943; // r6
  int v1944; // r8
  char v1945; // r7
  unsigned int v1946; // r5
  int v1947; // r3
  unsigned __int64 v1948; // r2
  int v1949; // r9
  int v1950; // r8
  char v1951; // r7
  int v1952; // t1
  unsigned int v1953; // r5
  int v1954; // r3
  _DWORD *v1955; // r4
  unsigned int v1956; // r3
  int v1957; // r2
  unsigned int v1958; // r3
  _DWORD *v1959; // r2
  char *v1960; // r6
  unsigned int v1961; // r3
  int v1962; // r2
  unsigned int v1963; // r2
  _DWORD *v1964; // lr
  unsigned int v1965; // r5
  unsigned int v1966; // r8
  unsigned int v1967; // r1
  unsigned int mm; // r2
  unsigned int v1969; // r0
  char *v1970; // r3
  unsigned int v1971; // r3
  __int64 v1972; // r0
  unsigned int v1973; // r9
  unsigned int v1974; // r6
  int v1975; // r10
  char v1976; // r7
  char v1977; // r4
  unsigned int v1978; // r5
  int v1979; // r3
  unsigned int v1980; // r1
  int v1981; // r0
  unsigned int v1982; // r9
  int v1983; // r10
  char v1984; // r7
  unsigned int v1985; // t1
  __int64 v1986; // r2
  char v1987; // r4
  char v1988; // r3
  unsigned int v1989; // r3
  int v1990; // r2
  int *v1991; // r8
  int v1992; // r3
  _DWORD *v1993; // lr
  __int64 v1994; // r0
  int v1995; // r2
  unsigned int v1996; // r4
  char *v1997; // r3
  int v1998; // r5
  int v1999; // r10
  int v2000; // r3
  unsigned int v2001; // r7
  char v2002; // r8
  char v2003; // r9
  char v2004; // r6
  unsigned int v2005; // r5
  int v2006; // r3
  unsigned __int64 v2007; // r2
  int v2008; // r8
  char v2009; // r9
  int v2010; // t1
  unsigned int v2011; // r5
  _DWORD *v2012; // r4
  __int64 v2013; // r2
  unsigned int v2014; // r3
  _BYTE *v2015; // r3
  int v2016; // r3
  int v2017; // r0
  unsigned int v2018; // r1
  int v2019; // r2
  unsigned int v2020; // r0
  unsigned int v2021; // r5
  int ll; // r4
  int v2023; // r3
  int v2024; // r1
  int v2025; // r0
  int v2026; // r0
  int v2027; // r4
  unsigned int v2028; // r3
  unsigned int v2029; // r5
  int v2030; // r3
  __int64 v2031; // kr4D8_8
  __int64 v2032; // kr4E0_8
  unsigned int v2033; // r1
  int v2034; // r3
  unsigned __int64 v2035; // r2
  int v2036; // r3
  int *v2037; // r9
  _DWORD *v2038; // r6
  unsigned int v2039; // lr
  char *v2040; // r3
  __int64 v2041; // r0
  int v2042; // r5
  unsigned int v2043; // r10
  int v2044; // r7
  char v2045; // r9
  unsigned int v2046; // lr
  unsigned int v2047; // r5
  int v2048; // r3
  unsigned __int64 v2049; // r2
  int v2050; // r7
  char v2051; // r9
  int v2052; // t1
  unsigned int v2053; // r5
  int v2054; // r1
  int v2055; // r2
  int v2056; // r1
  int v2057; // r3
  int v2058; // r0
  void (__fastcall *v2059)(int); // r2
  int v2060; // r4
  __int64 v2061; // r0
  unsigned int v2062; // r3
  unsigned int v2063; // r5
  int v2064; // r3
  __int64 v2065; // kr508_8
  __int64 v2066; // kr510_8
  unsigned int v2067; // r1
  int v2068; // r3
  unsigned __int64 v2069; // r2
  unsigned int v2070; // r3
  unsigned int v2071; // r6
  int v2072; // r3
  __int64 v2073; // kr528_8
  __int64 v2074; // kr530_8
  unsigned int v2075; // r1
  int v2076; // r3
  unsigned __int64 v2077; // r2
  int v2078; // r0
  int v2079; // r10
  unsigned int v2080; // r3
  unsigned int v2081; // r6
  int v2082; // r3
  __int64 v2083; // kr548_8
  __int64 v2084; // kr550_8
  unsigned int v2085; // r1
  int v2086; // r3
  unsigned __int64 v2087; // r2
  unsigned int v2088; // r4
  int v2089; // r2
  int (__fastcall *v2090)(int, int, int); // r5
  unsigned int v2091; // r3
  int v2092; // r1
  int v2093; // r3
  unsigned int v2094; // r3
  unsigned int v2095; // r5
  int v2096; // r3
  __int64 v2097; // kr568_8
  __int64 v2098; // kr570_8
  unsigned int v2099; // r1
  int v2100; // r3
  unsigned __int64 v2101; // r2
  __int64 v2102; // r0
  _BYTE *v2103; // r10
  _BYTE *v2104; // r4
  int v2105; // r0
  _DWORD *v2106; // r10
  _BYTE *v2107; // r7
  int *v2108; // r10
  int v2109; // r0
  int v2110; // r0
  unsigned int v2111; // r3
  int *v2112; // lr
  unsigned int v2113; // r7
  unsigned int v2114; // r9
  unsigned int v2115; // r3
  unsigned int v2116; // r6
  int v2117; // r3
  unsigned int v2118; // r5
  int v2119; // r4
  unsigned int v2120; // r2
  unsigned int v2121; // r3
  unsigned int v2122; // r3
  unsigned int v2123; // r5
  int v2124; // r3
  unsigned int v2125; // r6
  int v2126; // r4
  unsigned int v2127; // r2
  unsigned int v2128; // r3
  unsigned int v2129; // r7
  int v2130; // r0
  int v2131; // r1
  unsigned int v2132; // lr
  _DWORD *v2133; // r7
  int v2134; // r3
  unsigned int v2135; // r7
  int *v2136; // r9
  unsigned int v2137; // r3
  unsigned int v2138; // r6
  int v2139; // r3
  unsigned int v2140; // r5
  int v2141; // r4
  unsigned int v2142; // r2
  unsigned int v2143; // r3
  unsigned int v2144; // r3
  unsigned int v2145; // r5
  int v2146; // r3
  __int64 v2147; // kr5E8_8
  int v2148; // r4
  unsigned int v2149; // r2
  unsigned int v2150; // r3
  int v2151; // r1
  unsigned int v2152; // r4
  int *v2153; // r9
  int v2154; // r0
  int v2155; // r1
  int v2156; // r9
  int v2157; // r2
  char *v2158; // r1
  _DWORD *v2159; // r0
  int v2160; // t1
  int nn; // r9
  char v2162; // t1
  unsigned int v2163; // r3
  int v2164; // r2
  unsigned int v2165; // r3
  unsigned int v2166; // r5
  int v2167; // r3
  __int64 v2168; // kr608_8
  int v2169; // r2
  int v2170; // r2
  char *v2171; // r1
  char *v2172; // r0
  int v2173; // r4
  int v2174; // t1
  char v2175; // t1
  int v2176; // r3
  _DWORD *v2177; // r2
  int v2178; // r1
  unsigned int v2179; // r10
  _DWORD *v2180; // r6
  char *v2181; // r3
  int v2182; // r3
  unsigned int v2183; // r1
  int v2184; // r5
  unsigned int v2185; // r8
  int v2186; // r9
  int v2187; // lr
  char v2188; // r7
  char v2189; // r0
  char v2190; // r4
  unsigned int v2191; // r5
  int v2192; // r3
  unsigned int v2193; // r1
  int v2194; // r0
  int v2195; // r9
  int v2196; // lr
  char v2197; // r10
  int v2198; // t1
  unsigned int v2199; // r5
  int v2200; // r0
  unsigned int v2201; // r2
  char *v2202; // r0
  _DWORD *v2203; // r4
  unsigned int v2204; // r3
  int v2205; // r2
  int v2206; // r6
  int v2207; // t1
  char v2208; // t1
  unsigned int v2209; // r0
  _DWORD *v2210; // r1
  int v2211; // r2
  unsigned int v2212; // r2
  int *v2213; // r1
  int v2214; // t1
  int v2215; // r3
  unsigned int v2216; // r3
  unsigned int v2217; // r5
  int v2218; // r3
  __int64 v2219; // kr618_8
  __int64 v2220; // kr620_8
  unsigned int v2221; // r1
  int v2222; // r3
  unsigned __int64 v2223; // r2
  unsigned int v2224; // r4
  int v2225; // r6
  int *v2226; // r0
  unsigned int v2227; // r5
  int v2228; // r1
  int v2229; // lr
  int v2230; // r3
  unsigned int v2231; // r9
  int v2232; // r3
  int v2233; // t1
  int v2234; // r3
  __int64 v2235; // r6
  char *v2236; // r3
  __int64 v2237; // r0
  int v2238; // r5
  int v2239; // r10
  int v2240; // lr
  char v2241; // r9
  unsigned int v2242; // r5
  int v2243; // r3
  unsigned __int64 v2244; // r2
  int v2245; // lr
  char v2246; // r9
  int v2247; // t1
  unsigned int v2248; // r5
  int v2249; // r6
  int v2250; // r10
  int v2251; // r3
  int v2252; // r9
  int v2253; // r1
  int v2254; // r2
  int v2255; // r3
  _DWORD *(__fastcall *v2256)(int, int); // r3
  _DWORD *v2257; // r0
  int v2258; // r3
  unsigned int v2259; // r3
  int v2260; // r2
  unsigned int v2261; // r10
  unsigned int v2262; // r3
  unsigned int v2263; // r5
  int v2264; // r3
  __int64 v2265; // kr640_8
  int v2266; // r2
  int v2267; // r2
  char *v2268; // r0
  char *v2269; // r1
  int v2270; // r4
  int v2271; // t1
  char v2272; // t1
  int v2273; // r3
  _DWORD *v2274; // r2
  int v2275; // r1
  unsigned int v2276; // lr
  _DWORD *v2277; // r6
  char *v2278; // r3
  unsigned int v2279; // r3
  unsigned int v2280; // r1
  int v2281; // r5
  int v2282; // r3
  unsigned int v2283; // r8
  unsigned int v2284; // r10
  char v2285; // r7
  char v2286; // r9
  char v2287; // r0
  char v2288; // r4
  unsigned int v2289; // r5
  int v2290; // r3
  unsigned int v2291; // r1
  int v2292; // r0
  unsigned int v2293; // r10
  int v2294; // r7
  char v2295; // lr
  int v2296; // t1
  unsigned int v2297; // r5
  int v2298; // r0
  unsigned int v2299; // r2
  char *v2300; // r0
  _DWORD *v2301; // r4
  unsigned int v2302; // r3
  int v2303; // r2
  int v2304; // r6
  int v2305; // t1
  char v2306; // t1
  unsigned int v2307; // r1
  _DWORD *v2308; // r2
  int v2309; // r0
  int *v2310; // r2
  int v2311; // t1
  int v2312; // r3
  unsigned int v2313; // r3
  unsigned int v2314; // r5
  int v2315; // r3
  __int64 v2316; // kr650_8
  __int64 v2317; // kr658_8
  unsigned int v2318; // r1
  int v2319; // r3
  unsigned __int64 v2320; // r2
  unsigned int v2321; // r4
  int v2322; // r6
  int *v2323; // r0
  int v2324; // r5
  int v2325; // r1
  int v2326; // r7
  int v2327; // r3
  int v2328; // r3
  int v2329; // t1
  int v2330; // r3
  unsigned int v2331; // r3
  int v2332; // r2
  unsigned int v2333; // r10
  unsigned int v2334; // r3
  unsigned int v2335; // r5
  int v2336; // r3
  __int64 v2337; // kr670_8
  int v2338; // r2
  int v2339; // r2
  char *v2340; // r0
  char *v2341; // r1
  int v2342; // r4
  int v2343; // t1
  char v2344; // t1
  int v2345; // r3
  _DWORD *v2346; // r2
  int v2347; // r1
  unsigned int v2348; // lr
  _DWORD *v2349; // r6
  char *v2350; // r3
  unsigned int v2351; // r3
  unsigned int v2352; // r1
  int v2353; // r5
  int v2354; // r3
  unsigned int v2355; // r8
  unsigned int v2356; // r10
  char v2357; // r7
  char v2358; // r9
  char v2359; // r0
  char v2360; // r4
  unsigned int v2361; // r5
  int v2362; // r3
  unsigned int v2363; // r1
  int v2364; // r0
  unsigned int v2365; // r10
  int v2366; // r7
  char v2367; // lr
  int v2368; // t1
  unsigned int v2369; // r5
  int v2370; // r0
  unsigned int v2371; // r2
  char *v2372; // r0
  _DWORD *v2373; // r4
  unsigned int v2374; // r3
  int v2375; // r2
  int v2376; // r6
  int v2377; // t1
  char v2378; // t1
  unsigned int v2379; // r1
  _DWORD *v2380; // r2
  int v2381; // r0
  int *v2382; // r2
  int v2383; // t1
  int v2384; // r3
  unsigned int v2385; // r3
  unsigned int v2386; // r5
  int v2387; // r3
  __int64 v2388; // kr680_8
  __int64 v2389; // kr688_8
  unsigned int v2390; // r1
  int v2391; // r3
  unsigned __int64 v2392; // r2
  unsigned int v2393; // r4
  int v2394; // r6
  int *v2395; // r0
  int v2396; // r5
  int v2397; // r1
  int v2398; // r7
  int v2399; // r3
  int v2400; // r3
  int v2401; // t1
  int v2402; // r3
  unsigned int v2403; // r3
  unsigned int v2404; // r5
  int v2405; // r3
  __int64 v2406; // kr6A0_8
  __int64 v2407; // kr6A8_8
  int v2408; // r3
  int v2409; // r3
  int v2410; // r0
  unsigned int v2411; // r2
  int v2412; // r2
  char *v2413; // r0
  char *v2414; // r1
  int v2415; // r4
  int v2416; // t1
  char v2417; // t1
  int v2418; // r3
  _DWORD *v2419; // r2
  int v2420; // r1
  unsigned int v2421; // r7
  _DWORD *v2422; // r6
  char *v2423; // r3
  __int64 v2424; // r0
  unsigned int v2425; // r10
  unsigned int v2426; // r9
  int v2427; // lr
  char v2428; // r7
  char v2429; // r4
  unsigned int v2430; // r5
  int v2431; // r3
  unsigned int v2432; // r1
  int v2433; // r0
  int v2434; // lr
  char v2435; // r7
  unsigned int v2436; // t1
  __int64 v2437; // r2
  unsigned int v2438; // r2
  char *v2439; // r4
  _DWORD *v2440; // r5
  unsigned int v2441; // r3
  int v2442; // r2
  int v2443; // r6
  int v2444; // t1
  char v2445; // t1
  unsigned int v2446; // r3
  int v2447; // r10
  __int64 v2448; // kr6B0_8
  unsigned int v2449; // r4
  unsigned int v2450; // r3
  int *v2451; // r0
  unsigned int v2452; // r5
  int v2453; // r6
  int v2454; // r1
  int v2455; // r7
  int v2456; // r3
  unsigned int v2457; // lr
  unsigned int v2458; // r9
  int v2459; // r3
  int v2460; // t1
  int v2461; // r2
  int v2462; // r8
  int v2463; // r2
  int *v2464; // r0
  int v2465; // r4
  char *v2466; // r1
  int v2467; // t1
  char v2468; // t1
  int v2469; // r7
  unsigned int v2470; // r3
  unsigned int v2471; // r5
  int v2472; // r3
  __int64 v2473; // kr6B8_8
  __int64 v2474; // kr6C0_8
  unsigned int v2475; // r1
  int v2476; // r3
  unsigned __int64 v2477; // r2
  __int64 v2478; // r0
  int v2479; // r10
  int v2480; // r2
  int v2481; // r7
  int v2482; // r3
  unsigned int v2483; // r5
  int v2484; // lr
  unsigned __int64 v2485; // r2
  int v2486; // r8
  int v2487; // r2
  int v2488; // t1
  unsigned int v2489; // r4
  unsigned __int64 v2490; // r2
  int v2491; // r5
  int v2492; // r2
  int v2493; // r1
  int *v2494; // r0
  int v2495; // t1
  int v2496; // t1
  int v2497; // r3
  int *v2498; // r8
  unsigned int v2499; // r3
  unsigned int v2500; // r6
  int v2501; // r3
  __int64 v2502; // kr708_8
  __int64 v2503; // kr710_8
  unsigned int v2504; // r1
  int v2505; // r3
  unsigned __int64 v2506; // r2
  __int64 v2507; // r0
  int v2508; // r0
  int v2509; // r1
  int v2510; // r5
  int v2511; // r2
  unsigned int v2512; // r3
  int v2513; // r2
  int *v2514; // r0
  int v2515; // r4
  char *v2516; // r1
  int v2517; // t1
  char v2518; // t1
  int v2519; // r5
  int v2520; // r2
  int v2521; // r2
  int *v2522; // r0
  int v2523; // r4
  char *v2524; // r1
  int v2525; // t1
  char v2526; // t1
  unsigned int v2527; // r3
  unsigned int v2528; // r5
  int v2529; // r3
  __int64 v2530; // kr728_8
  __int64 v2531; // kr730_8
  unsigned int v2532; // r1
  int v2533; // r3
  unsigned __int64 v2534; // r2
  __int64 v2535; // r8
  unsigned int v2536; // r3
  unsigned int v2537; // r5
  int v2538; // r3
  __int64 v2539; // kr748_8
  int v2540; // r4
  unsigned int v2541; // r1
  unsigned int v2542; // r5
  unsigned int v2543; // kr758_4
  unsigned int v2544; // r4
  unsigned __int64 v2545; // r2
  int v2546; // r0
  int v2547; // lr
  int v2548; // r8
  int v2549; // r9
  int v2550; // r10
  unsigned int v2551; // r2
  unsigned int v2552; // r1
  _DWORD *v2553; // r7
  int v2554; // r3
  _DWORD *v2555; // r4
  int v2556; // r3
  unsigned int v2557; // r5
  char **v2558; // r10
  int *v2559; // r9
  unsigned int v2560; // lr
  int v2561; // r1
  int *v2562; // r0
  int *v2563; // t1
  int v2564; // r3
  int v2565; // r0
  int v2566; // r7
  int v2567; // r3
  _DWORD *v2568; // r2
  int v2569; // r1
  unsigned int v2570; // r3
  unsigned int *v2571; // r1
  int v2572; // r0
  unsigned int v2573; // r3
  unsigned int *v2574; // r1
  int v2575; // r0
  unsigned int v2576; // r2
  char *v2577; // lr
  char *v2578; // t1
  unsigned int v2579; // r5
  unsigned int v2580; // r0
  int v2581; // r2
  unsigned int v2582; // r1
  int v2583; // r8
  int v2584; // r5
  int v2585; // r7
  _DWORD *v2586; // r2
  int v2587; // r5
  int v2588; // r3
  unsigned int *v2589; // r5
  unsigned int v2590; // r3
  int v2591; // r7
  unsigned int v2592; // r3
  unsigned int *v2593; // r5
  int v2594; // r7
  unsigned int v2595; // r2
  unsigned int v2596; // r7
  int *v2597; // r5
  char *v2598; // r8
  unsigned int v2599; // r6
  int v2600; // t1
  int v2601; // r8
  int v2602; // r3
  int v2603; // r7
  int v2604; // r0
  int v2605; // r5
  int v2606; // r3
  _DWORD *v2607; // r2
  int v2608; // r1
  unsigned int v2609; // r3
  unsigned int *v2610; // r1
  int v2611; // r0
  unsigned int v2612; // r3
  unsigned int *v2613; // r1
  int v2614; // r0
  __int16 *v2615; // lr
  unsigned int v2616; // r9
  unsigned int v2617; // r7
  unsigned int v2618; // r0
  int v2619; // r2
  unsigned int v2620; // r1
  int v2621; // lr
  int v2622; // r4
  int v2623; // r5
  _DWORD *v2624; // r2
  int v2625; // r4
  int v2626; // r3
  unsigned int *v2627; // r4
  unsigned int v2628; // r3
  int v2629; // r5
  unsigned int v2630; // r3
  unsigned int *v2631; // r4
  int v2632; // r5
  unsigned int v2633; // r2
  __int16 *v2634; // r4
  unsigned int v2635; // r5
  char *v2636; // lr
  unsigned int v2637; // r8
  int v2638; // t1
  int v2639; // lr
  int v2640; // r3
  int v2641; // r5
  int v2642; // r0
  int v2643; // r4
  int v2644; // r3
  _DWORD *v2645; // r2
  int v2646; // r1
  unsigned int v2647; // r3
  unsigned int *v2648; // r1
  int v2649; // r0
  unsigned int v2650; // r3
  unsigned int *v2651; // r1
  int v2652; // r0
  unsigned int v2653; // r0
  int v2654; // r1
  unsigned int v2655; // r5
  unsigned int i2; // r0
  unsigned int v2657; // r4
  unsigned int v2658; // r2
  char v2659; // r1
  unsigned int i3; // r3
  char v2661; // r6
  int v2662; // r1
  int v2663; // r3
  int v2664; // r1
  __int64 v2665; // kr768_8
  int v2666; // r1
  int v2667; // r0
  unsigned __int8 *v2668; // r3
  unsigned int v2669; // r2
  int v2670; // r2
  unsigned __int8 *v2671; // r3
  unsigned int v2672; // r2
  int v2673; // r3
  int v2674; // r3
  _DWORD *v2675; // r3
  unsigned __int8 *v2677; // r4
  unsigned int v2678; // r5
  int *v2679; // r4
  unsigned int v2680; // [sp+10h] [bp-3E8h]
  unsigned int v2681; // [sp+10h] [bp-3E8h]
  int v2682; // [sp+10h] [bp-3E8h]
  unsigned int v2683; // [sp+10h] [bp-3E8h]
  int v2684; // [sp+10h] [bp-3E8h]
  unsigned int v2685; // [sp+10h] [bp-3E8h]
  unsigned int v2686; // [sp+10h] [bp-3E8h]
  unsigned int v2687; // [sp+10h] [bp-3E8h]
  unsigned int v2688; // [sp+10h] [bp-3E8h]
  unsigned int v2689; // [sp+10h] [bp-3E8h]
  unsigned int v2690; // [sp+10h] [bp-3E8h]
  int v2691; // [sp+10h] [bp-3E8h]
  int v2692; // [sp+10h] [bp-3E8h]
  int v2693; // [sp+10h] [bp-3E8h]
  _DWORD *v2694; // [sp+10h] [bp-3E8h]
  unsigned int v2695; // [sp+10h] [bp-3E8h]
  int v2696; // [sp+10h] [bp-3E8h]
  _BYTE *v2697; // [sp+10h] [bp-3E8h]
  unsigned int v2698; // [sp+10h] [bp-3E8h]
  int v2699; // [sp+10h] [bp-3E8h]
  int v2700; // [sp+10h] [bp-3E8h]
  unsigned int v2701; // [sp+10h] [bp-3E8h]
  unsigned int v2702; // [sp+10h] [bp-3E8h]
  _DWORD *v2703; // [sp+10h] [bp-3E8h]
  int v2704; // [sp+10h] [bp-3E8h]
  int v2705; // [sp+10h] [bp-3E8h]
  int v2706; // [sp+10h] [bp-3E8h]
  __int16 *i1; // [sp+10h] [bp-3E8h]
  BOOL v2708; // [sp+14h] [bp-3E4h]
  int v2709; // [sp+14h] [bp-3E4h]
  unsigned int v2710; // [sp+14h] [bp-3E4h]
  BOOL v2711; // [sp+14h] [bp-3E4h]
  int v2712; // [sp+14h] [bp-3E4h]
  int *v2713; // [sp+14h] [bp-3E4h]
  int v2714; // [sp+14h] [bp-3E4h]
  unsigned int v2715; // [sp+14h] [bp-3E4h]
  int v2716; // [sp+14h] [bp-3E4h]
  unsigned int v2717; // [sp+14h] [bp-3E4h]
  unsigned int v2718; // [sp+14h] [bp-3E4h]
  unsigned int v2719; // [sp+14h] [bp-3E4h]
  _DWORD *v2720; // [sp+14h] [bp-3E4h]
  unsigned int v2721; // [sp+14h] [bp-3E4h]
  unsigned int v2722; // [sp+14h] [bp-3E4h]
  unsigned int v2723; // [sp+14h] [bp-3E4h]
  unsigned int v2724; // [sp+14h] [bp-3E4h]
  char v2725; // [sp+14h] [bp-3E4h]
  _BYTE *v2726; // [sp+14h] [bp-3E4h]
  unsigned int v2727; // [sp+14h] [bp-3E4h]
  int *v2728; // [sp+14h] [bp-3E4h]
  int v2729; // [sp+14h] [bp-3E4h]
  int v2730; // [sp+14h] [bp-3E4h]
  int v2731; // [sp+14h] [bp-3E4h]
  int v2732; // [sp+14h] [bp-3E4h]
  unsigned int v2733; // [sp+14h] [bp-3E4h]
  _BYTE *v2734; // [sp+18h] [bp-3E0h]
  unsigned int v2735; // [sp+18h] [bp-3E0h]
  _BYTE *v2736; // [sp+18h] [bp-3E0h]
  _BYTE *v2737; // [sp+18h] [bp-3E0h]
  int v2738; // [sp+1Ch] [bp-3DCh]
  char *v2739; // [sp+1Ch] [bp-3DCh]
  int v2740; // [sp+1Ch] [bp-3DCh]
  _DWORD *v2741; // [sp+1Ch] [bp-3DCh]
  int v2742; // [sp+1Ch] [bp-3DCh]
  unsigned int v2743; // [sp+1Ch] [bp-3DCh]
  int v2744; // [sp+1Ch] [bp-3DCh]
  int v2745; // [sp+1Ch] [bp-3DCh]
  unsigned int v2746; // [sp+20h] [bp-3D8h]
  _DWORD *v2747; // [sp+20h] [bp-3D8h]
  unsigned int v2748; // [sp+20h] [bp-3D8h]
  int v2749; // [sp+20h] [bp-3D8h]
  int v2750; // [sp+20h] [bp-3D8h]
  int v2751; // [sp+20h] [bp-3D8h]
  char *v2752; // [sp+20h] [bp-3D8h]
  int v2753; // [sp+20h] [bp-3D8h]
  int *v2754; // [sp+20h] [bp-3D8h]
  int v2755; // [sp+20h] [bp-3D8h]
  _DWORD *v2756; // [sp+20h] [bp-3D8h]
  unsigned int v2757; // [sp+20h] [bp-3D8h]
  unsigned int v2758; // [sp+20h] [bp-3D8h]
  _DWORD *v2759; // [sp+28h] [bp-3D0h]
  int *v2760; // [sp+28h] [bp-3D0h]
  unsigned int v2761; // [sp+28h] [bp-3D0h]
  unsigned int v2762; // [sp+28h] [bp-3D0h]
  char *v2763; // [sp+28h] [bp-3D0h]
  __int64 v2764; // [sp+28h] [bp-3D0h]
  _DWORD *v2765; // [sp+28h] [bp-3D0h]
  int v2766; // [sp+28h] [bp-3D0h]
  int v2767; // [sp+28h] [bp-3D0h]
  unsigned int v2768; // [sp+28h] [bp-3D0h]
  int v2769; // [sp+28h] [bp-3D0h]
  unsigned int v2770; // [sp+28h] [bp-3D0h]
  int v2771; // [sp+28h] [bp-3D0h]
  unsigned int v2772; // [sp+28h] [bp-3D0h]
  unsigned int v2773; // [sp+28h] [bp-3D0h]
  unsigned int v2774; // [sp+28h] [bp-3D0h]
  int v2775; // [sp+28h] [bp-3D0h]
  char v2776; // [sp+28h] [bp-3D0h]
  char v2777; // [sp+28h] [bp-3D0h]
  int v2778; // [sp+28h] [bp-3D0h]
  int v2779; // [sp+28h] [bp-3D0h]
  int v2780; // [sp+28h] [bp-3D0h]
  int v2781; // [sp+28h] [bp-3D0h]
  unsigned int v2782; // [sp+28h] [bp-3D0h]
  unsigned int v2783; // [sp+28h] [bp-3D0h]
  int (__fastcall *v2784)(_BYTE *, int); // [sp+28h] [bp-3D0h]
  int v2785; // [sp+28h] [bp-3D0h]
  int v2786; // [sp+28h] [bp-3D0h]
  int v2787; // [sp+28h] [bp-3D0h]
  unsigned int v2788; // [sp+28h] [bp-3D0h]
  unsigned int v2789; // [sp+28h] [bp-3D0h]
  unsigned int v2790; // [sp+28h] [bp-3D0h]
  int v2791; // [sp+28h] [bp-3D0h]
  int v2792; // [sp+28h] [bp-3D0h]
  int v2793; // [sp+28h] [bp-3D0h]
  unsigned int v2794; // [sp+28h] [bp-3D0h]
  int *v2795; // [sp+30h] [bp-3C8h]
  unsigned int v2796; // [sp+30h] [bp-3C8h]
  unsigned int v2797; // [sp+30h] [bp-3C8h]
  unsigned int v2798; // [sp+30h] [bp-3C8h]
  char *v2799; // [sp+30h] [bp-3C8h]
  int v2800; // [sp+30h] [bp-3C8h]
  _DWORD *v2801; // [sp+30h] [bp-3C8h]
  _DWORD *v2802; // [sp+30h] [bp-3C8h]
  char *v2803; // [sp+30h] [bp-3C8h]
  _DWORD *v2804; // [sp+30h] [bp-3C8h]
  unsigned __int8 *v2805; // [sp+30h] [bp-3C8h]
  unsigned int v2806; // [sp+30h] [bp-3C8h]
  int v2807; // [sp+30h] [bp-3C8h]
  int v2808; // [sp+30h] [bp-3C8h]
  int v2809; // [sp+30h] [bp-3C8h]
  void (__fastcall *v2810)(_DWORD, _DWORD, __int64 *); // [sp+34h] [bp-3C4h]
  _BYTE *v2811; // [sp+34h] [bp-3C4h]
  BOOL v2812; // [sp+34h] [bp-3C4h]
  _DWORD *v2813; // [sp+34h] [bp-3C4h]
  int *v2814; // [sp+34h] [bp-3C4h]
  int *v2815; // [sp+34h] [bp-3C4h]
  _DWORD *v2816; // [sp+34h] [bp-3C4h]
  unsigned int v2817; // [sp+34h] [bp-3C4h]
  int v2818; // [sp+34h] [bp-3C4h]
  unsigned int v2819; // [sp+34h] [bp-3C4h]
  unsigned int v2820; // [sp+34h] [bp-3C4h]
  char **v2821; // [sp+34h] [bp-3C4h]
  int *v2822; // [sp+38h] [bp-3C0h]
  int v2823; // [sp+3Ch] [bp-3BCh]
  unsigned int v2824; // [sp+3Ch] [bp-3BCh]
  int v2825; // [sp+3Ch] [bp-3BCh]
  int v2826; // [sp+3Ch] [bp-3BCh]
  unsigned int v2827; // [sp+3Ch] [bp-3BCh]
  unsigned int v2828; // [sp+40h] [bp-3B8h]
  _DWORD *v2829; // [sp+40h] [bp-3B8h]
  int v2830; // [sp+40h] [bp-3B8h]
  int v2831; // [sp+40h] [bp-3B8h]
  _DWORD *v2832; // [sp+40h] [bp-3B8h]
  int v2833; // [sp+40h] [bp-3B8h]
  _DWORD *v2834; // [sp+40h] [bp-3B8h]
  int v2835; // [sp+40h] [bp-3B8h]
  unsigned int v2836; // [sp+40h] [bp-3B8h]
  _DWORD *v2837; // [sp+40h] [bp-3B8h]
  int v2838; // [sp+48h] [bp-3B0h] BYREF
  int v2839; // [sp+4Ch] [bp-3ACh]
  int v2840; // [sp+50h] [bp-3A8h]
  unsigned int v2841; // [sp+54h] [bp-3A4h]
  unsigned int v2842; // [sp+58h] [bp-3A0h]
  unsigned int *v2843; // [sp+5Ch] [bp-39Ch]
  _DWORD *v2844; // [sp+60h] [bp-398h]
  unsigned int v2845; // [sp+64h] [bp-394h]
  unsigned int v2846; // [sp+68h] [bp-390h]
  unsigned int v2847; // [sp+6Ch] [bp-38Ch]
  unsigned int jj; // [sp+70h] [bp-388h]
  int v2849; // [sp+74h] [bp-384h]
  _DWORD *v2850; // [sp+78h] [bp-380h]
  int *v2851; // [sp+7Ch] [bp-37Ch]
  unsigned int v2852; // [sp+80h] [bp-378h]
  _BYTE *v2853; // [sp+84h] [bp-374h]
  _DWORD *v2854; // [sp+88h] [bp-370h]
  unsigned int v2855; // [sp+90h] [bp-368h]
  int v2856; // [sp+94h] [bp-364h]
  unsigned int v2857; // [sp+98h] [bp-360h]
  int v2858; // [sp+9Ch] [bp-35Ch]
  unsigned int v2859; // [sp+A0h] [bp-358h]
  int v2860; // [sp+A4h] [bp-354h]
  unsigned int v2861; // [sp+A8h] [bp-350h]
  int v2862; // [sp+ACh] [bp-34Ch]
  int v2863; // [sp+B0h] [bp-348h]
  char v2864[4]; // [sp+B4h] [bp-344h] BYREF
  unsigned int v2865; // [sp+B8h] [bp-340h] BYREF
  unsigned int v2866; // [sp+BCh] [bp-33Ch] BYREF
  unsigned __int8 v2867; // [sp+C0h] [bp-338h] BYREF
  char v2868[3]; // [sp+C1h] [bp-337h] BYREF
  BOOL v2869; // [sp+C4h] [bp-334h] BYREF
  unsigned int v2870; // [sp+C8h] [bp-330h]
  int v2871; // [sp+CCh] [bp-32Ch]
  _DWORD *v2872; // [sp+D0h] [bp-328h]
  int v2873; // [sp+D4h] [bp-324h]
  int v2874; // [sp+D8h] [bp-320h] BYREF
  int v2875; // [sp+DCh] [bp-31Ch] BYREF
  int v2876; // [sp+E0h] [bp-318h]
  int v2877; // [sp+E4h] [bp-314h]
  int v2878; // [sp+E8h] [bp-310h]
  int v2879; // [sp+ECh] [bp-30Ch]
  int v2880; // [sp+F0h] [bp-308h]
  unsigned int v2881; // [sp+F4h] [bp-304h] BYREF
  int v2882; // [sp+F8h] [bp-300h]
  int v2883; // [sp+FCh] [bp-2FCh]
  int v2884; // [sp+100h] [bp-2F8h]
  int v2885; // [sp+104h] [bp-2F4h]
  int v2886; // [sp+108h] [bp-2F0h]
  int v2887; // [sp+10Ch] [bp-2ECh] BYREF
  int v2888; // [sp+110h] [bp-2E8h]
  int v2889; // [sp+114h] [bp-2E4h]
  int v2890; // [sp+118h] [bp-2E0h]
  int v2891; // [sp+11Ch] [bp-2DCh]
  int v2892; // [sp+120h] [bp-2D8h]
  int v2893; // [sp+124h] [bp-2D4h]
  int v2894; // [sp+128h] [bp-2D0h]
  int v2895; // [sp+12Ch] [bp-2CCh]
  unsigned int v2896; // [sp+130h] [bp-2C8h] BYREF
  unsigned int v2897; // [sp+138h] [bp-2C0h]
  unsigned int v2898; // [sp+140h] [bp-2B8h]
  unsigned int v2899; // [sp+148h] [bp-2B0h]
  unsigned int v2900; // [sp+150h] [bp-2A8h]
  unsigned int v2901; // [sp+158h] [bp-2A0h]
  __int64 v2902; // [sp+160h] [bp-298h] BYREF
  __int64 v2903; // [sp+168h] [bp-290h] BYREF
  char v2904[16]; // [sp+170h] [bp-288h] BYREF
  char v2905[16]; // [sp+180h] [bp-278h] BYREF
  char v2906[16]; // [sp+190h] [bp-268h] BYREF
  char v2907[16]; // [sp+1A0h] [bp-258h] BYREF
  __int16 v2908[4]; // [sp+1B0h] [bp-248h] BYREF
  unsigned int v2909; // [sp+1B8h] [bp-240h]
  int v2910; // [sp+1C0h] [bp-238h] BYREF
  unsigned int v2911; // [sp+1C8h] [bp-230h]
  _BYTE *v2912; // [sp+1D0h] [bp-228h] BYREF
  unsigned int v2913; // [sp+1D8h] [bp-220h]
  unsigned int v2914; // [sp+1E0h] [bp-218h]
  unsigned int v2915; // [sp+1E8h] [bp-210h]
  unsigned int v2916; // [sp+1F0h] [bp-208h] BYREF
  unsigned int v2917; // [sp+1F4h] [bp-204h] BYREF
  int v2918; // [sp+1F8h] [bp-200h] BYREF
  int v2919; // [sp+1FCh] [bp-1FCh] BYREF
  int v2920; // [sp+200h] [bp-1F8h] BYREF
  int v2921; // [sp+204h] [bp-1F4h] BYREF
  int v2922; // [sp+208h] [bp-1F0h] BYREF
  int v2923; // [sp+20Ch] [bp-1ECh] BYREF
  int v2924; // [sp+210h] [bp-1E8h] BYREF
  int v2925; // [sp+214h] [bp-1E4h] BYREF
  int v2926; // [sp+218h] [bp-1E0h] BYREF
  int v2927; // [sp+21Ch] [bp-1DCh] BYREF
  int v2928; // [sp+220h] [bp-1D8h] BYREF
  int v2929; // [sp+228h] [bp-1D0h] BYREF
  int v2930; // [sp+22Ch] [bp-1CCh]
  int v2931; // [sp+230h] [bp-1C8h]
  int v2932; // [sp+238h] [bp-1C0h] BYREF
  int v2933; // [sp+23Ch] [bp-1BCh]
  int v2934; // [sp+240h] [bp-1B8h]
  int v2935; // [sp+248h] [bp-1B0h] BYREF
  int v2936; // [sp+24Ch] [bp-1ACh]
  int v2937; // [sp+250h] [bp-1A8h]
  int v2938[4]; // [sp+258h] [bp-1A0h] BYREF
  int v2939[4]; // [sp+268h] [bp-190h] BYREF
  int v2940; // [sp+278h] [bp-180h] BYREF
  int v2941; // [sp+27Ch] [bp-17Ch] BYREF
  __int16 v2942[2]; // [sp+280h] [bp-178h] BYREF
  int *v2943; // [sp+284h] [bp-174h]
  int v2944[4]; // [sp+288h] [bp-170h] BYREF
  __int16 v2945[2]; // [sp+298h] [bp-160h] BYREF
  int *v2946; // [sp+29Ch] [bp-15Ch]
  char v2947[8]; // [sp+2A0h] [bp-158h] BYREF
  int v2948[4]; // [sp+2A8h] [bp-150h] BYREF
  char v2949[4]; // [sp+2B8h] [bp-140h] BYREF
  char v2950[4]; // [sp+2BCh] [bp-13Ch] BYREF
  char v2951[4]; // [sp+2C0h] [bp-138h] BYREF
  char v2952[4]; // [sp+2C4h] [bp-134h] BYREF
  char v2953[8]; // [sp+2C8h] [bp-130h] BYREF
  char v2954[24]; // [sp+2D0h] [bp-128h] BYREF
  char v2955[4]; // [sp+2E8h] [bp-110h] BYREF
  char v2956[4]; // [sp+2ECh] [bp-10Ch] BYREF
  char v2957[4]; // [sp+2F0h] [bp-108h] BYREF
  char v2958[4]; // [sp+2F4h] [bp-104h] BYREF
  char v2959[8]; // [sp+2F8h] [bp-100h] BYREF
  int v2960[2]; // [sp+300h] [bp-F8h] BYREF
  int v2961; // [sp+308h] [bp-F0h]
  _BYTE *v2962; // [sp+310h] [bp-E8h]
  unsigned int v2963; // [sp+318h] [bp-E0h]
  int v2964; // [sp+320h] [bp-D8h]
  char v2965[16]; // [sp+328h] [bp-D0h] BYREF
  char v2966[16]; // [sp+338h] [bp-C0h] BYREF
  char v2967[16]; // [sp+348h] [bp-B0h] BYREF
  char v2968[16]; // [sp+358h] [bp-A0h] BYREF
  char v2969[16]; // [sp+368h] [bp-90h] BYREF
  char v2970[16]; // [sp+378h] [bp-80h] BYREF
  char v2971[16]; // [sp+388h] [bp-70h] BYREF
  char v2972[16]; // [sp+398h] [bp-60h] BYREF
  char v2973[16]; // [sp+3A8h] [bp-50h] BYREF
  char v2974[16]; // [sp+3B8h] [bp-40h] BYREF
  char v2975[48]; // [sp+3C8h] [bp-30h] BYREF

  *(_DWORD *)(a1 + 856) = 0;
  v1 = *(_DWORD *)(a1 + 768);
  v2 = a1;
  v2858 = a1;
  v2870 = v1;
  v3 = 16;
  v4 = v2973;
  v2855 = *(_DWORD *)(a1 + 772);
  v5 = (char *)(a1 + 752);
  v6 = 4;
  do
  {
    v7 = *(_DWORD *)v5;
    v5 += 4;
    v3 -= 4;
    --v6;
    *(_DWORD *)v4 = v7;
    v4 += 4;
  }
  while ( v6 );
  for ( ; v3; ++v4 )
  {
    v8 = *v5++;
    --v3;
    *v4 = v8;
  }
  *(_DWORD *)(a1 + 768) = 0;
  *(_DWORD *)(a1 + 772) = 0;
  v9 = 16;
  *(_DWORD *)(a1 + 856) = 0;
  v10 = (_DWORD *)(a1 + 752);
  v11 = 4;
  do
  {
    v9 -= 4;
    --v11;
    *v10++ = 0;
  }
  while ( v11 );
  for ( ; v9; --v9 )
  {
    *(_BYTE *)v10 = 0;
    v10 = (_DWORD *)((char *)v10 + 1);
  }
  v12 = *(_DWORD *)(a1 + 796);
  v13 = (_DWORD *)a1;
  v14 = (char *)a1;
  if ( a1 < v12 + a1 )
  {
    do
    {
      __pld(v14);
      v14 += 128;
    }
    while ( (unsigned int)v14 < v12 + a1 );
  }
  v15 = *(_QWORD *)(a1 + 840);
  v16 = v12;
  if ( v12 >= 8 )
  {
    v17 = v12 >> 3;
    v18 = *(_DWORD *)(v2 + 836) & 0x3F;
    v19 = 64 - v18;
    v20 = 32 - v18;
    do
    {
      v16 -= 8;
      v21 = *v13 ^ v15;
      v22 = v13[1];
      v13 += 2;
      v23 = HIDWORD(v15) ^ v22;
      v24 = (v21 >> v19) | (v23 << (v18 - 32)) | (v23 >> v20);
      HIDWORD(v15) = (v23 >> v19) | (__PAIR64__(v23, v21) << v18 >> 32);
      LODWORD(v15) = v24 | (v21 << v18);
      v20 = 32 - v18;
      --v17;
    }
    while ( v17 );
    v2 = v2858;
  }
  if ( v16 )
  {
    v25 = *(_DWORD *)(v2 + 836) & 0x3F;
    v26 = 64 - v25;
    do
    {
      v27 = *(unsigned __int8 *)v13;
      v13 = (_DWORD *)((char *)v13 + 1);
      v28 = (v15 ^ v27) << v25;
      LODWORD(v15) = ((v27 ^ (unsigned int)v15) >> v26) | (HIDWORD(v15) << (v25 - 32)) | (HIDWORD(v15) >> (32 - v25)) | ((v27 ^ (unsigned int)v15) << v25);
      HIDWORD(v15) = (HIDWORD(v15) >> v26) | HIDWORD(v28);
      --v16;
    }
    while ( v16 );
  }
  v29 = (_DWORD *)v2858;
  v30 = 16;
  v31 = v2973;
  v32 = (_DWORD *)(v2858 + 752);
  *(_DWORD *)(v2858 + 856) += v12;
  v33 = 4;
  v29[192] = v2870;
  v29[193] = v2855;
  do
  {
    v34 = *(_DWORD *)v31;
    v31 += 4;
    v30 -= 4;
    --v33;
    *v32++ = v34;
  }
  while ( v33 );
  for ( ; v30; v32 = (_DWORD *)((char *)v32 + 1) )
  {
    v35 = *v31++;
    --v30;
    *(_BYTE *)v32 = v35;
  }
  if ( *((_QWORD *)v29 + 96) != v15 )
  {
    v36 = (_DWORD *)v29[172];
    v37 = v29[199];
    *v36 = v29;
    v36[2] = v37;
    if ( !v29[220] )
      *(_QWORD *)(v29[172] + 16) = *((_QWORD *)v29 + 96) ^ v15;
    if ( !v29[220] )
    {
      v29[222] = v29 - 462279366;
      v29[223] = 0;
      v29[224] = 0;
      v29[225] = 0;
      v29[226] = 257;
      v29[227] = 0;
      v29[228] = v15;
      v29[229] = 0;
      v29[220] = 1;
    }
  }
  v38 = v29[248];
  v2863 = 0x10000;
  if ( ((v38 & 0x10000) == 0 || (v38 & 0x100000) == 0) && (v38 & 0x10) != 0 )
  {
    __disable_irq();
    v39 = __mrc(14, 0, 0, 2, 2);
    if ( v29[231] == -1 && (v29[248] ^= (v29[248] ^ (32 * ((v39 & 0x8000) != 0))) & 0x20, v29[231] == -1)
      || *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) == v29[231] )
    {
      __mcr(14, 0, v39 & 0xFFFF7FFF, 0, 2, 2);
      __isb(0xFu);
    }
    if ( v29[231] == -1 )
      v29[231] = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
    __enable_irq();
  }
  v40 = v29;
  v29[248] |= 4u;
  ++v29[217];
  if ( (v29[248] & 0x20000000) == 0 )
    v40 = 0;
  if ( (int)v29[232] > 1 )
  {
    if ( !v40 )
    {
      v42 = (char *)sub_5FD658;
      goto LABEL_47;
    }
    v41 = v40[204];
    goto LABEL_45;
  }
  if ( v40 )
  {
    v41 = v40[203];
LABEL_45:
    v42 = (char *)v40 + (v41 | 1);
    goto LABEL_47;
  }
  v42 = (char *)sub_5FD2A0;
LABEL_47:
  v29[270] = v42;
  if ( (v29[248] & 8) != 0 )
  {
    v43 = v29[249];
    if ( (v43 & 4) == 0 )
    {
      v44 = v29[199];
      v45 = v29[262];
      v46 = v29[206];
      v2708 = (v29[249] & 1) != 0;
      v2870 = v29[269];
      if ( (v43 & 1) != 0 )
        v45 = v29[182];
      v2810 = (void (__fastcall *)(_DWORD, _DWORD, _DWORD))v29[67];
      jj = v29[143];
      v2842 = v29[104];
      v2855 = v29[119];
      v47 = __mrc(15, 0, 9, 13, 0);
      v48 = v47 << 29;
      v49 = v47 ^ (v47 >> 3);
      v50 = 67117057i64 * (unsigned int)v49;
      v51 = 1880096896i64 * (unsigned int)v49 + 67117057i64 * v48;
      v52 = (1880096896i64 * v48 + (unsigned __int64)HIDWORD(v51)) >> 32;
      v53 = 1880096896 * v48 + HIDWORD(v51);
      if ( (unsigned int)(v51 + HIDWORD(v50)) < HIDWORD(v50) )
        v52 = (__PAIR64__(v52, v53++) + 1) >> 32;
      LODWORD(v54) = v50 ^ v53;
      HIDWORD(v54) = (v51 + HIDWORD(v50)) ^ v52;
      v2902 = -6000000000i64 - FsRtlRemovePerStreamContextEx(100000000i64, v54);
      if ( (*(_DWORD *)(v2858 + 992) & 0x4000000) != 0 )
      {
        v55 = __mrc(15, 0, 9, 13, 0);
        v56 = v55 << 29;
        v57 = v55 ^ (v55 >> 3);
        v58 = 67117057i64 * (unsigned int)v57;
        v59 = 1880096896i64 * (unsigned int)v57 + 67117057i64 * v56;
        v60 = (1880096896i64 * v56 + (unsigned __int64)HIDWORD(v59)) >> 32;
        v61 = 1880096896 * v56 + HIDWORD(v59);
        if ( (unsigned int)(v59 + HIDWORD(v58)) < HIDWORD(v58) )
          v60 = (__PAIR64__(v60, v61++) + 1) >> 32;
        LODWORD(v62) = v58 ^ v61;
        HIDWORD(v62) = (v59 + HIDWORD(v58)) ^ v60;
        if ( (unsigned __int64)FsRtlRemovePerStreamContextEx(10i64, v62) < 2 )
        {
          v63 = __mrc(15, 0, 9, 13, 0);
          v64 = v63 << 29;
          v65 = v63 ^ (v63 >> 3);
          v66 = 67117057i64 * (unsigned int)v65;
          v67 = 1880096896i64 * (unsigned int)v65 + 67117057i64 * v64;
          v68 = (1880096896i64 * v64 + (unsigned __int64)HIDWORD(v67)) >> 32;
          v69 = 1880096896 * v64 + HIDWORD(v67);
          if ( (unsigned int)(v67 + HIDWORD(v66)) < HIDWORD(v66) )
            v68 = (__PAIR64__(v68, v69++) + 1) >> 32;
          LODWORD(v70) = v66 ^ v69;
          HIDWORD(v70) = (v67 + HIDWORD(v66)) ^ v68;
          v71 = FsRtlRemovePerStreamContextEx(10i64, v70);
          HIDWORD(v71) = ((unsigned __int64)(v71 + 1) >> 32) * v2902 + (v71 + 1) * HIDWORD(v2902);
          v72 = (unsigned int)(v71 + 1) * (unsigned __int64)(unsigned int)v2902;
          LODWORD(v2902) = (v71 + 1) * v2902;
          HIDWORD(v2902) = HIDWORD(v71) + HIDWORD(v72);
        }
      }
      v73 = 0;
      v74 = 0;
      v75 = *(_DWORD *)(v2858 + 992);
      v76 = 0;
      v77 = 0;
      if ( (v75 & 2) == 0 )
        v44 = v46;
      v2869 = (*(_DWORD *)(v2858 + 992) & 0x80) != 0;
      if ( ((v75 & v2863) == 0 || (v75 & 0x100000) == 0) && (v75 & 0x10) != 0 )
      {
        (*(void (__fastcall **)(char *, _DWORD))(v2858 + 300))(v2965, *(_DWORD *)(v2858 + 924));
        v78 = (*(int (__fastcall **)(char *, _DWORD))(v2858 + 304))(v2965, 0);
        __disable_irq();
        v79 = __mrc(14, 0, 0, 2, 2);
        if ( (*(_DWORD *)(v2858 + 992) & 0x20) != 0 )
          v79 |= 0x8000u;
        __mcr(14, 0, v79, 0, 2, 2);
        __enable_irq();
        (*(void (__fastcall **)(int))(v2858 + 296))(v78);
        v80 = v2858;
        *(_DWORD *)(v2858 + 992) &= 0xFFFFFFDF;
        *(_DWORD *)(v80 + 924) = -1;
      }
      if ( v2869 )
      {
        v81 = __mrc(15, 0, 9, 13, 0);
        v82 = v81 << 29;
        v83 = v81 ^ (v81 >> 3);
        v84 = 67117057i64 * (unsigned int)v83;
        v85 = 1880096896 * v83 + 67117057 * v82;
        v86 = (1880096896i64 * v82 + ((1880096896i64 * (unsigned int)v83 + 67117057 * (unsigned __int64)v82) >> 32)) >> 32;
        v87 = 1880096896 * v82 + ((1880096896i64 * (unsigned int)v83 + 67117057 * (unsigned __int64)v82) >> 32);
        v88 = v85 + HIDWORD(v84);
        if ( (unsigned int)(v85 + HIDWORD(v84)) < HIDWORD(v84) )
          v86 = (__PAIR64__(v86, v87++) + 1) >> 32;
        v73 = v84 ^ v87;
        v74 = v88 ^ v86;
        v89 = v84 ^ v87;
        v90 = v2858 + 1104;
        v91 = (int *)(v2858 + 1104);
        v76 = v2858 ^ v84 ^ v87;
        v77 = v74;
        v92 = 276;
        do
        {
          v93 = *--v91;
          v94 = v93 ^ v89;
          v89 = __ROR4__(v89, v92);
          *v91 = v94;
          --v92;
        }
        while ( v92 );
        v95 = (unsigned int)(v46 - 1104) >> 2;
        if ( v95 )
        {
          v96 = v90 + 4 * v95;
          do
          {
            v97 = *(_DWORD *)(v96 - 4);
            v96 -= 4;
            v77 = (v76 >> 31) | (2 * v77);
            v76 = __ROR4__(v97, v95--) ^ (2 * v76);
          }
          while ( v95 );
        }
        v98 = (unsigned int)(v44 - v46) >> 2;
        if ( v98 )
        {
          v99 = (int *)(v46 + v2858 + 4 * v98);
          do
          {
            v100 = *--v99;
            v101 = v100 ^ v89;
            v89 = __ROR4__(v89, v98);
            *v99 = v101;
            --v98;
          }
          while ( v98 );
        }
      }
      if ( v2870 )
      {
        v102 = v2858;
        ((void (__fastcall *)(int, int, __int64 *, void (__fastcall *)(_DWORD, _DWORD, __int64 *), unsigned int))v2855)(
          v2858,
          v44,
          &v2902,
          (void (__fastcall *)(_DWORD, _DWORD, __int64 *))v2810,
          v2870);
      }
      else
      {
        if ( v45 )
        {
          if ( !((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD, __int64 *))v2842)(v45, 0, 0, 0, &v2902) && v2708 )
            ((void (__fastcall *)(int, _DWORD, _DWORD))jj)(v45, 0, 0);
        }
        else
        {
          v2810(0, 0, &v2902);
        }
        v102 = v2858;
      }
      if ( v2869 )
      {
        v103 = (int *)(v102 + 1104);
        v104 = v102 ^ v73;
        v105 = 276;
        do
        {
          v106 = *--v103;
          v107 = v106 ^ v73;
          v73 = __ROR4__(v73, v105);
          *v103 = v107;
          --v105;
        }
        while ( v105 );
        v108 = (unsigned int)(v46 - 1104) >> 2;
        if ( v108 )
        {
          v109 = v102 + 1104 + 4 * v108;
          do
          {
            v110 = *(_DWORD *)(v109 - 4);
            v109 -= 4;
            v74 = (v104 >> 31) | (2 * v74);
            v104 = __ROR4__(v110, v108--) ^ (2 * v104);
          }
          while ( v108 );
        }
        v29 = (_DWORD *)v2858;
        v111 = (unsigned int)(v44 - v46) >> 2;
        if ( v111 )
        {
          v112 = (int *)(v46 + v2858 + 4 * v111);
          do
          {
            v113 = *--v112;
            v114 = v113 ^ v73;
            v73 = __ROR4__(v73, v111);
            *v112 = v114;
            --v111;
          }
          while ( v111 );
        }
        if ( v104 != v76 || v74 != v77 )
        {
          v115 = (_DWORD *)v29[172];
          v116 = v29[199];
          *v115 = v29;
          v115[2] = v116;
          if ( !v29[220] )
          {
            v117 = v29[172];
            *(_DWORD *)(v117 + 16) = v104 ^ v76;
            *(_DWORD *)(v117 + 20) = v74 ^ v77;
          }
          if ( !v29[220] )
          {
            *((_QWORD *)v29 + 111) = (unsigned int)(v29 - 462279366);
            v29[224] = 0;
            v29[225] = 0;
            *((_QWORD *)v29 + 113) = 270i64;
            v29[228] = v104;
            v29[229] = 0;
            v29[220] = 1;
          }
        }
      }
      else
      {
        v29 = (_DWORD *)v2858;
      }
      v118 = v29[248];
      if ( ((v118 & v2863) == 0 || (v118 & 0x100000) == 0) && (v118 & 0x10) != 0 )
      {
        __disable_irq();
        v119 = __mrc(14, 0, 0, 2, 2);
        if ( v29[231] == -1
          && (v29[248] ^= ((unsigned __int8)v29[248] ^ (unsigned __int8)(32 * ((v119 & 0x8000) != 0))) & 0x20,
              v29[231] == -1)
          || *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) == v29[231] )
        {
          __mcr(14, 0, v119 & 0xFFFF7FFF, 0, 2, 2);
          __isb(0xFu);
        }
        if ( v29[231] == -1 )
          v29[231] = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        __enable_irq();
      }
    }
  }
  v120 = v2858;
  v2870 = v29[49];
  v121 = v2858 + 736;
  v29[49] = 0;
  v122 = (char *)v120;
  if ( v120 < v121 )
  {
    do
    {
      __pld(v122);
      v122 += 128;
    }
    while ( (unsigned int)v122 < v121 );
  }
  v123 = *(_QWORD *)(v120 + 840);
  v124 = 736;
  v125 = *(_QWORD *)(v120 + 836) & 0x3F;
  v126 = 64 - v125;
  v127 = 32 - v125;
  v128 = 92;
  do
  {
    v124 -= 8;
    v129 = *v29 ^ v123;
    v130 = v29[1];
    v29 += 2;
    v131 = HIDWORD(v123) ^ v130;
    v132 = (v129 >> v126) | (v131 << (v125 - 32)) | (v131 >> v127);
    HIDWORD(v123) = (v131 >> v126) | (__PAIR64__(v131, v129) << v125 >> 32);
    LODWORD(v123) = v132 | (v129 << v125);
    v127 = 32 - v125;
    --v128;
  }
  while ( v128 );
  for ( ; v124; --v124 )
  {
    v133 = *(unsigned __int8 *)v29;
    v29 = (_DWORD *)((char *)v29 + 1);
    v134 = (v123 ^ v133) << v125;
    LODWORD(v123) = ((v133 ^ (unsigned int)v123) >> (64 - v125)) | (HIDWORD(v123) << (v125 - 32)) | (HIDWORD(v123) >> (32 - v125)) | ((v133 ^ (unsigned int)v123) << v125);
    HIDWORD(v123) = (HIDWORD(v123) >> v126) | HIDWORD(v134);
  }
  v135 = v2858;
  *(_DWORD *)(v2858 + 856) += 736;
  *(_DWORD *)(v135 + 196) = v2870;
  v136 = *(_DWORD *)(v135 + 1068);
  if ( *(_QWORD *)(v135 + 1064) != v123 )
  {
    v137 = *(int **)(v135 + 688);
    v138 = *(_DWORD *)(v135 + 796);
    *v137 = v135;
    v137[2] = v138;
    v136 = *(_DWORD *)(v135 + 1064);
    if ( !*(_DWORD *)(v135 + 880) )
    {
      v139 = *(_DWORD *)(v135 + 688);
      v136 ^= v123;
      HIDWORD(v123) ^= *(_DWORD *)(v135 + 1068);
      *(_DWORD *)(v139 + 16) = v136;
      *(_DWORD *)(v139 + 20) = HIDWORD(v123);
    }
    if ( !*(_DWORD *)(v135 + 880) )
    {
      *(_DWORD *)(v135 + 888) = v135 - 1849117464;
      *(_DWORD *)(v135 + 892) = 0;
      *(_DWORD *)(v135 + 896) = 0;
      *(_DWORD *)(v135 + 900) = 0;
      *(_DWORD *)(v135 + 904) = 265;
      *(_DWORD *)(v135 + 908) = 0;
      *(_DWORD *)(v135 + 912) = v123;
      *(_DWORD *)(v135 + 916) = 0;
      *(_DWORD *)(v135 + 880) = 1;
    }
  }
  LODWORD(v123) = *(_DWORD *)(v135 + 976);
  v140 = v135;
  v2734 = (_BYTE *)v135;
  v2842 = 0;
  if ( (_DWORD)v123 != -1 )
  {
    v141 = (*(int (__fastcall **)(_DWORD, _DWORD, int))(v135 + 384))(v123, HIDWORD(v123), v136);
    if ( v141 || (v141 = (*(int (__fastcall **)(_DWORD))(v135 + 388))(0)) != 0 )
    {
      v142 = (*(int (__fastcall **)(int, char *))(v135 + 396))(v141, v2954);
      if ( v142 >= 0 )
      {
        v143 = v2863;
        *(_DWORD *)(v135 + 988) = v141;
        *(_DWORD *)(v135 + 856) += v143;
        v142 = 0;
      }
      else
      {
        (*(void (__fastcall **)(int))(v135 + 392))(v141);
      }
      if ( v142 >= 0 )
        v2842 = 1;
    }
  }
  v144 = 12;
  v145 = &v2838;
  v146 = 3;
  do
  {
    v144 -= 4;
    --v146;
    *v145++ = 0;
  }
  while ( v146 );
  for ( ; v144; --v144 )
  {
    *(_BYTE *)v145 = 0;
    v145 = (int *)((char *)v145 + 1);
  }
  v147 = *(_DWORD *)(v135 + 848);
  v2855 = -1073741275;
  v2871 = 0x2000000;
  v2873 = 0x10000000;
  v148 = *(_QWORD *)(v135 + 856);
  v2862 = -1073741670;
  v2870 = 15728640;
  v2857 = v147;
  if ( (int)v148 < SHIDWORD(v148) )
  {
    v149 = v2839;
    v150 = v2840;
    v151 = v2838;
    v2853 = v2912;
    v2811 = v2912;
    while ( 2 )
    {
      v152 = *(_DWORD *)(v140 + 992);
      if ( ((v152 & v2863) == 0 || (v152 & 0x100000) == 0) && (v152 & 0x10) != 0 )
      {
        __disable_irq();
        v153 = __mrc(14, 0, 0, 2, 2);
        if ( *(_DWORD *)(v140 + 924) == -1
          && (*(_DWORD *)(v140 + 992) ^= ((unsigned __int8)*(_DWORD *)(v140 + 992) ^ (unsigned __int8)(32 * ((v153 & 0x8000) != 0))) & 0x20,
              *(_DWORD *)(v140 + 924) == -1)
          || *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) == *(_DWORD *)(v140 + 924) )
        {
          __mcr(14, 0, v153 & 0xFFFF7FFF, 0, 2, 2);
          __isb(0xFu);
        }
        if ( *(_DWORD *)(v140 + 924) == -1 )
          *(_DWORD *)(v140 + 924) = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        __enable_irq();
        v149 = v2839;
        v150 = v2840;
        v151 = v2838;
      }
      if ( v147 == *(_DWORD *)(v140 + 828) )
      {
        v154 = *(_DWORD *)(v140 + 864);
        v147 = 0;
        v2857 = 0;
        *(_DWORD *)(v140 + 864) = v154 + 1;
        if ( *(_DWORD *)(v140 + 952) == 6 )
        {
          if ( *(_DWORD *)(v140 + 976) == -1 )
            *(_DWORD *)(v140 + 976) = 0;
          else
            *(_DWORD *)(v140 + 992) |= 1u;
        }
        v149 = v2839;
        v150 = v2840;
        v151 = v2838;
      }
      v155 = v140;
      if ( *(_DWORD *)(v140 + 1084) )
        v155 = *(_DWORD *)(v140 + 1084);
      v156 = 0;
      v157 = (int *)(v155 + *(_DWORD *)(v155 + 824));
      v2822 = v157;
      if ( v151 && v149 <= v147 )
      {
        v157 = (int *)(v150 + v155);
        v2822 = (int *)(v150 + v155);
        v156 = v149;
      }
      if ( v156 != v147 )
      {
        v158 = v147 - v156;
        v156 = v147;
        while ( 1 )
        {
          v159 = *v157;
          if ( *v157 > 17 )
          {
            switch ( v159 )
            {
              case 19:
LABEL_183:
                v160 = 44;
                goto LABEL_184;
              case 28:
                v162 = *((unsigned __int16 *)v157 + 12);
                goto LABEL_171;
              case 30:
                v161 = ((((unsigned int)(v157[6] - 1) >> 3) + 7) & 0xFFFFFFF8) + 24 * *((unsigned __int16 *)v157 + 14);
                goto LABEL_173;
            }
            if ( (unsigned int)(v159 - 33) <= 1 )
            {
              v163 = 5 * (((v157[6] + (v157[5] & 0xFFFu) + 4095) >> 12) + 2);
              goto LABEL_180;
            }
          }
          else
          {
            if ( *v157 == 17 )
              goto LABEL_183;
            switch ( v159 )
            {
              case 1:
LABEL_174:
                v163 = ((unsigned int)v157[2] >> 3) + 10;
LABEL_180:
                v160 = 4 * v163;
                goto LABEL_184;
              case 7:
                v161 = 24 * v157[4];
                goto LABEL_173;
              case 8:
                v162 = *((unsigned __int16 *)v157 + 10);
LABEL_171:
                v160 = (v162 + 47) & 0xFFFFFFF8;
                goto LABEL_184;
              case 10:
                v161 = 12 * v157[5];
LABEL_173:
                v160 = v161 + 40;
                goto LABEL_184;
              case 12:
                goto LABEL_174;
            }
          }
          v160 = 40;
LABEL_184:
          v157 = (int *)((char *)v157 + v160);
          if ( !--v158 )
          {
            v2822 = v157;
            break;
          }
        }
      }
      v151 = 1;
      v150 = (int)v157 - v155;
      v2838 = 1;
      v2839 = v156;
      v2840 = (int)v157 - v155;
      v164 = *v157;
      v149 = v156;
      switch ( *v157 )
      {
        case 0:
        case 11:
          if ( v164 == 11 && !*(_DWORD *)(v140 + 988) )
            goto LABEL_1565;
          v165 = (_DWORD *)v157[1];
          jj = v157[2];
          v166 = (char *)v165;
          if ( v165 < (_DWORD *)((char *)v165 + jj) )
          {
            do
            {
              __pld(v166);
              v166 += 128;
            }
            while ( v166 < (char *)v165 + jj );
          }
          v167 = *(_DWORD *)(v140 + 844);
          v168 = *(_DWORD *)(v140 + 840);
          v169 = jj;
          v2680 = v167;
          if ( jj >= 8 )
          {
            v170 = jj >> 3;
            v171 = *(_DWORD *)(v140 + 836) & 0x3F;
            v172 = 64 - v171;
            v173 = 32 - v171;
            do
            {
              v169 -= 8;
              v174 = v168 ^ *v165;
              v175 = v165[1];
              v165 += 2;
              v176 = (v174 >> v172) | ((v175 ^ v167) << (v171 - 32)) | ((v175 ^ v167) >> v173);
              v167 = ((v175 ^ v167) >> v172) | (__PAIR64__(v175 ^ v167, v174) << v171 >> 32);
              v168 = v176 | (v174 << v171);
              --v170;
              v173 = 32 - v171;
            }
            while ( v170 );
            v140 = (unsigned int)v2734;
            v2680 = v167;
          }
          if ( v169 )
          {
            v177 = *(_DWORD *)(v140 + 836) & 0x3F;
            v178 = 64 - v177;
            v179 = 32 - v177;
            do
            {
              v180 = *(unsigned __int8 *)v165;
              v165 = (_DWORD *)((char *)v165 + 1);
              v181 = v168 ^ v180;
              v182 = (v181 >> v178) | (v167 << (v177 - 32)) | (v167 >> (32 - v177));
              v167 = (v167 >> v178) | (v181 << (v177 - 32)) | (v2680 << v177) | (v181 >> v179);
              v2680 = v167;
              v168 = v182 | (v181 << v177);
              --v169;
              v179 = 32 - v177;
            }
            while ( v169 );
            v140 = (unsigned int)v2734;
          }
          v183 = __PAIR64__(v167, v168);
          *(_DWORD *)(v140 + 856) += jj;
          while ( 1 )
          {
            LODWORD(v183) = FsRtlPrivateResetHighestLockOffset(v183, HIDWORD(v183), 31);
            if ( !v183 )
              break;
            v168 ^= v183;
          }
          v184 = v2822[3];
          if ( (v168 & 0x7FFFFFFF) == v184 )
            goto LABEL_1564;
          if ( !*(_DWORD *)(v140 + 880) )
          {
            v185 = *(_DWORD *)(v140 + 688);
            *(_DWORD *)(v185 + 16) = v168 & 0x7FFFFFFF ^ v184;
            *(_DWORD *)(v185 + 20) = 0;
          }
          v186 = v2822[1];
          if ( *(_DWORD *)(v140 + 880) )
            goto LABEL_1564;
          *(_DWORD *)(v140 + 888) = v140 - 1849117464;
          *(_DWORD *)(v140 + 892) = 0;
          *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
          *(_DWORD *)(v140 + 900) = 0;
          v187 = *v2822;
          goto LABEL_207;
        case 1:
        case 12:
          if ( v164 == 12 && !*(_DWORD *)(v140 + 988) )
            goto LABEL_210;
          if ( !*(_DWORD *)(v140 + 852) && (v164 != 11 || *(_DWORD *)(v140 + 988)) )
          {
            v188 = (_DWORD *)v157[1];
            jj = v157[2];
            v189 = (char *)v188;
            if ( v188 < (_DWORD *)((char *)v188 + jj) )
            {
              do
              {
                __pld(v189);
                v189 += 128;
              }
              while ( v189 < (char *)v188 + jj );
            }
            v190 = *(_DWORD *)(v140 + 844);
            v191 = *(_DWORD *)(v140 + 840);
            v192 = jj;
            v2681 = v190;
            if ( jj >= 8 )
            {
              v193 = jj >> 3;
              v194 = *(_DWORD *)(v140 + 836) & 0x3F;
              v195 = 64 - v194;
              v196 = 32 - v194;
              do
              {
                v192 -= 8;
                v197 = v191 ^ *v188;
                v198 = v188[1];
                v188 += 2;
                v199 = (v197 >> v195) | ((v190 ^ v198) << (v194 - 32)) | ((v190 ^ v198) >> v196);
                v190 = ((v190 ^ v198) >> v195) | (__PAIR64__(v190 ^ v198, v197) << v194 >> 32);
                v191 = v199 | (v197 << v194);
                --v193;
                v196 = 32 - v194;
              }
              while ( v193 );
              v140 = (unsigned int)v2734;
              v2681 = v190;
            }
            if ( v192 )
            {
              v200 = *(_DWORD *)(v140 + 836) & 0x3F;
              v201 = 64 - v200;
              v202 = 32 - v200;
              do
              {
                v203 = *(unsigned __int8 *)v188;
                v188 = (_DWORD *)((char *)v188 + 1);
                v204 = v191 ^ v203;
                v205 = (v204 >> v201) | (v190 << (v200 - 32)) | (v190 >> (32 - v200));
                v190 = (v190 >> v201) | (v204 << (v200 - 32)) | (v2681 << v200) | (v204 >> v202);
                v2681 = v190;
                v191 = v205 | (v204 << v200);
                --v192;
                v202 = 32 - v200;
              }
              while ( v192 );
              v140 = (unsigned int)v2734;
            }
            v206 = __PAIR64__(v190, v191);
            *(_DWORD *)(v140 + 856) += jj;
            while ( 1 )
            {
              LODWORD(v206) = FsRtlPrivateResetHighestLockOffset(v206, HIDWORD(v206), 31);
              if ( !v206 )
                break;
              v191 ^= v206;
            }
            v157 = v2822;
            v207 = v2822[3];
            if ( (v191 & 0x7FFFFFFF) != v207 )
            {
              if ( !*(_DWORD *)(v140 + 880) )
              {
                v208 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v208 + 16) = v191 & 0x7FFFFFFF ^ v207;
                *(_DWORD *)(v208 + 20) = 0;
              }
              v209 = v2822[1];
              if ( !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v2822;
                *(_DWORD *)(v140 + 912) = v209;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
            }
          }
          v210 = v157[1];
          v211 = *(_DWORD *)(v140 + 852);
          v212 = v210 + 8 * ((unsigned int)v157[2] >> 3);
          v213 = &v157[v211 + 10];
          v214 = (int *)(v210 + 8 * v211);
          v2861 = (unsigned int)v213;
          v2709 = v210;
          v2851 = v214;
          v2847 = v212;
          while ( 1 )
          {
            if ( (*v213 & 0x80000000) != 0 )
            {
              v231 = v2861;
              goto LABEL_256;
            }
            v215 = *(_QWORD *)v214;
            v216 = *v214 & 0xFFFFFFFE;
            v2845 = v216 + v157[5];
            v217 = ((v215 + 2 * HIDWORD(v215)) & 0xFFFFFFFE) - v216;
            v218 = (_DWORD *)v2845;
            jj = v217;
            v2828 = v2845;
            v219 = (char *)v2845;
            if ( v218 < (_DWORD *)((char *)v218 + v217) )
            {
              do
              {
                __pld(v219);
                v219 += 128;
              }
              while ( (unsigned int)v219 < v217 + v2845 );
            }
            v220 = v217;
            HIDWORD(v221) = *(_DWORD *)(v140 + 844);
            v222 = *(_DWORD *)(v140 + 840);
            v2746 = v217;
            if ( v217 >= 8 )
            {
              v223 = v217 >> 3;
              v224 = *(_DWORD *)(v140 + 836) & 0x3F;
              v225 = 64 - v224;
              do
              {
                v226 = v222 ^ *v218;
                v227 = HIDWORD(v221) ^ v218[1];
                LODWORD(v221) = (v226 >> v225) | (v227 << (v224 - 32)) | (v227 >> (32 - v224));
                HIDWORD(v221) = (v227 >> v225) | (v226 << (v224 - 32)) | (v227 << v224) | (v226 >> (32 - v224));
                v218 = (_DWORD *)(v2828 + 8);
                v220 = v2746 - 8;
                v2828 += 8;
                v2746 -= 8;
                v222 = v221 | (v226 << v224);
                --v223;
              }
              while ( v223 );
              v140 = (unsigned int)v2734;
            }
            if ( v220 )
            {
              v228 = *(_DWORD *)(v140 + 836) & 0x3F;
              v229 = 64 - v228;
              do
              {
                v230 = v222 ^ *(unsigned __int8 *)v218;
                LODWORD(v221) = (v230 >> v229) | (HIDWORD(v221) << (v228 - 32)) | (HIDWORD(v221) >> (32 - v228));
                HIDWORD(v221) = (HIDWORD(v221) >> v229) | (v230 << (v228 - 32)) | (HIDWORD(v221) << v228) | (v230 >> (32 - v228));
                v218 = (_DWORD *)((char *)v218 + 1);
                _ZF = v2746-- == 1;
                v222 = v221 | (v230 << v228);
              }
              while ( !_ZF );
              v140 = (unsigned int)v2734;
            }
            LODWORD(v221) = v222;
            *(_DWORD *)(v140 + 856) += jj;
            while ( 1 )
            {
              LODWORD(v221) = FsRtlPrivateResetHighestLockOffset(v221, HIDWORD(v221), 31);
              if ( !v221 )
                break;
              v222 ^= v221;
            }
            v231 = v2861;
            v232 = *(_DWORD *)v2861 & 0x7FFFFFFF;
            if ( (v222 & 0x7FFFFFFF) == v232 )
              break;
            if ( !*(_DWORD *)(v140 + 880) )
            {
              v233 = *(_DWORD *)(v140 + 688);
              *(_DWORD *)(v233 + 16) = v222 & 0x7FFFFFFF ^ v232;
              *(_DWORD *)(v233 + 20) = 0;
            }
            v157 = v2822;
            if ( *(_DWORD *)(v140 + 880) )
              goto LABEL_254;
            *(_QWORD *)(v140 + 888) = v140 - 1849117464;
            *(_QWORD *)(v140 + 896) = (unsigned int)v2822 - 465226731;
            *(_QWORD *)(v140 + 904) = *v2822;
            *(_QWORD *)(v140 + 912) = v2845;
            v214 = v2851;
            *(_DWORD *)(v140 + 880) = 1;
LABEL_256:
            v2861 = v231 + 4;
            v214 += 2;
            v2851 = v214;
            _ZF = v214 == (int *)v2847;
            if ( (unsigned int)v214 >= v2847 )
              goto LABEL_259;
            v213 = (int *)v2861;
            if ( *(_DWORD *)(v140 + 856) >= *(_DWORD *)(v140 + 860) )
            {
              _ZF = v214 == (int *)v2847;
LABEL_259:
              if ( !_ZF )
              {
                v251 = ((int)v214 - v2709) >> 3;
                goto LABEL_281;
              }
              v235 = *(_DWORD *)(v140 + 652);
              v236 = *(_DWORD *)(v140 + 640) + 16;
              v237 = (*(int (__fastcall **)(int))(v140 + 356))(12);
              (*(void (__fastcall **)(int))(v140 + 260))(v235);
              v238 = *(_DWORD *)(v140 + 640);
              v239 = *(_BYTE *)(v238 + 12) != 0;
              v240 = v236 + 16 * *(_DWORD *)v238;
              do
              {
                v241 = 16;
                v242 = v157 + 4;
                v243 = (int *)v236;
                while ( 1 )
                {
                  v245 = *v243++;
                  v244 = v245;
                  v246 = *v242++;
                  if ( v244 != v246 )
                    break;
                  v241 -= 4;
                  if ( v241 < 4 )
                  {
                    if ( !v241 )
                      goto LABEL_270;
                    while ( 1 )
                    {
                      v248 = *(unsigned __int8 *)v243;
                      v243 = (int *)((char *)v243 + 1);
                      v247 = v248;
                      v249 = *(unsigned __int8 *)v242;
                      v242 = (int *)((char *)v242 + 1);
                      if ( v247 != v249 )
                        goto LABEL_269;
                      if ( !--v241 )
                        goto LABEL_270;
                    }
                  }
                }
LABEL_269:
                v236 += 16;
              }
              while ( v236 < v240 );
LABEL_270:
              (*(void (__fastcall **)(_DWORD))(v140 + 292))(*(_DWORD *)(v140 + 652));
              (*(void (__fastcall **)(int))(v140 + 360))(v237);
              if ( (!v239 || v157[4] != 1) && v236 == v240 && !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v157;
                *(_DWORD *)(v140 + 912) = v236;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
              *(_DWORD *)(v140 + 852) = 0;
LABEL_276:
              v149 = v2839;
              v150 = v2840;
              v151 = v2838;
LABEL_277:
              v147 = v2857;
              goto LABEL_278;
            }
          }
          v157 = v2822;
LABEL_254:
          v214 = v2851;
          goto LABEL_256;
        case 4:
          if ( (*(_DWORD *)(v140 + 864) & 1) != 0 )
            goto LABEL_1565;
          v261 = 0;
          v262 = *(_DWORD *)(v140 + 656);
          v2710 = 0;
          (*(void (**)(void))(v140 + 280))();
          (*(void (__fastcall **)(int, _DWORD))(v140 + 240))(v262, 0);
          v263 = *(_DWORD ***)(v140 + 636);
          v264 = *v263;
          if ( *v263 != v263 )
          {
            do
            {
              *((_BYTE *)v264 - 74) = 1;
              v264 = (_DWORD *)*v264;
              ++v261;
            }
            while ( v264 != v263 );
            v2710 = v261;
          }
          v265 = *(_DWORD *)(v140 + 624);
          v266 = (*(int (__fastcall **)(int))(v140 + 356))(12);
          v267 = *(void (__fastcall **)(_DWORD, _DWORD))(v140 + 256);
          v268 = v266;
          jj = v266;
          v267(v265, v2968);
          v269 = *(_DWORD ***)(v140 + 620);
          v270 = *v269;
          if ( *v269 != v269 )
          {
            do
            {
              if ( !*((_BYTE *)v270 - 14) && !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v2822;
                *(_DWORD *)(v140 + 912) = v270 - 30;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
              *((_BYTE *)v270 - 14) = 0;
              v270 = (_DWORD *)*v270;
            }
            while ( v270 != v269 );
            v261 = v2710;
            v268 = jj;
          }
          (*(void (__fastcall **)(char *))(v140 + 288))(v2968);
          (*(void (__fastcall **)(unsigned int))(v140 + 360))(v268);
          goto LABEL_306;
        case 5:
          if ( (*(_DWORD *)(v140 + 864) & 1) == 0 )
            goto LABEL_1565;
          v2711 = (*(_DWORD *)(v140 + 864) & 3) == 3;
          v272 = 0;
          v273 = *(_DWORD *)(v140 + 656);
          v2682 = 0;
          (*(void (**)(void))(v140 + 280))();
          (*(void (__fastcall **)(int, _DWORD))(v140 + 240))(v273, 0);
          v274 = *(_DWORD ***)(v140 + 636);
          v275 = *v274;
          if ( *v274 != v274 )
          {
            do
            {
              *((_BYTE *)v275 - 74) = 1;
              v275 = (_DWORD *)*v275;
              ++v272;
            }
            while ( v275 != v274 );
            v2682 = v272;
          }
          v276 = **(unsigned int ***)(v140 + 660);
          v277 = *v276;
          v278 = 4;
          do
          {
            v279 = (_DWORD *)(*(int (__fastcall **)(unsigned int *, unsigned int))(v140 + 224))(v276, v278);
            if ( v279 )
            {
              v280 = *v279 & 0xFFFFFFF8;
              v281 = *(_BYTE *)v280;
              __dmb(0xBu);
              v282 = v281 & 0x7F;
              if ( v282 == 3 )
              {
                if ( !*(_BYTE *)(v280 + 106) && (*(_DWORD *)(v280 + 192) & 0x4000000) != 0 && !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = v280;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
                *(_BYTE *)(v280 + 106) = 0;
              }
              else if ( v282 == 6 && v2711 )
              {
                if ( (v283 = *(_DWORD *)(v280 + 420), v283 != *(_DWORD *)(v140 + 460))
                  && v283 != *(_DWORD *)(v140 + 464)
                  || *(_DWORD *)(v280 + 428) != *(_DWORD *)(v140 + 468)
                  || *(_DWORD *)(v280 + 424) != *(_DWORD *)(v140 + 472) )
                {
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_QWORD *)(v140 + 904) = *v2822;
                    *(_DWORD *)(v140 + 912) = v280;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
              }
              (*(void (__fastcall **)(unsigned int *, _DWORD *))(v140 + 236))(v276, v279);
            }
            v278 += 4;
          }
          while ( v278 < v277 );
          v284 = (*(int (__fastcall **)(_DWORD, _DWORD))(v140 + 244))(*(_DWORD *)(v140 + 656), 0);
          (*(void (__fastcall **)(int))(v140 + 284))(v284);
          v260 = *(_DWORD *)(v140 + 856) + ((v2682 + (v277 >> 2)) << 8);
          goto LABEL_294;
        case 6:
          v290 = *(_DWORD *)v157[6];
          if ( !v290 || v290 == v157[4] || v290 == v157[5] || *(_DWORD *)(v140 + 880) )
            goto LABEL_1565;
          *(_DWORD *)(v140 + 888) = v140 - 1849117464;
          *(_DWORD *)(v140 + 892) = 0;
          *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
          *(_DWORD *)(v140 + 900) = 0;
          *(_QWORD *)(v140 + 904) = *v157;
          *(_DWORD *)(v140 + 912) = v290;
          goto LABEL_349;
        case 7:
          (*(void (__fastcall **)(char *, int))(v140 + 300))(v2967, v157[5]);
          v252 = (*(int (__fastcall **)(char *, _DWORD))(v140 + 304))(v2967, 0);
          v253 = 0;
          if ( v157[4] )
          {
            v254 = v157 + 10;
            do
            {
              if ( v254[4] )
                v255 = __mrc(15, 0, 12, 0, 0);
              else
                v255 = __mrc(15, 0, 1, 0, 0);
              v256 = *((_QWORD *)v254 + 1);
              v252 = HIDWORD(v256);
              v257 = v255 & *v254;
              if ( v256 != v257 )
              {
                v258 = v254[4];
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  v259 = *(_DWORD *)(v140 + 688);
                  *(_DWORD *)(v259 + 16) = v257 ^ v256;
                  *(_DWORD *)(v259 + 20) = HIDWORD(v256);
                }
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  v252 = 0;
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v157;
                  *(_DWORD *)(v140 + 912) = v258;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
              ++v253;
              v254 += 6;
            }
            while ( v253 < v157[4] );
          }
          (*(void (__fastcall **)(int))(v140 + 296))(v252);
          v260 = *(_DWORD *)(v140 + 856) + (v157[4] << 15);
          goto LABEL_294;
        case 8:
          v291 = v157[4];
          if ( *(unsigned __int8 *)(v291 + 42) != *((unsigned __int8 *)v157 + 22) && !*(_DWORD *)(v140 + 880) )
          {
            *(_DWORD *)(v140 + 888) = v140 - 1849117464;
            *(_DWORD *)(v140 + 892) = 0;
            *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
            *(_DWORD *)(v140 + 900) = 0;
            *(_QWORD *)(v140 + 904) = *v157;
            *(_DWORD *)(v140 + 912) = v291;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
          if ( (*((_BYTE *)v157 + 22) & 0x40) == 0 && *(_DWORD *)(v291 + 136) != v291 + 136 && !*(_DWORD *)(v140 + 880) )
          {
            *(_DWORD *)(v140 + 888) = v140 - 1849117464;
            *(_DWORD *)(v140 + 892) = 0;
            *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
            *(_DWORD *)(v140 + 900) = 0;
            *(_QWORD *)(v140 + 904) = *v157;
            *(_DWORD *)(v140 + 912) = v291;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
          if ( *v157 != 11 || *(_DWORD *)(v140 + 988) )
          {
            v292 = (_DWORD *)v157[1];
            jj = v157[2];
            v293 = (char *)v292;
            if ( v292 < (_DWORD *)((char *)v292 + jj) )
            {
              do
              {
                __pld(v293);
                v293 += 128;
              }
              while ( v293 < (char *)v292 + jj );
            }
            v294 = *(_DWORD *)(v140 + 844);
            v295 = *(_DWORD *)(v140 + 840);
            v296 = jj;
            v2683 = v294;
            if ( jj >= 8 )
            {
              v297 = jj >> 3;
              v298 = *(_DWORD *)(v140 + 836) & 0x3F;
              v299 = 64 - v298;
              v300 = 32 - v298;
              do
              {
                v296 -= 8;
                v301 = v295 ^ *v292;
                v302 = v292[1];
                v292 += 2;
                v303 = (v301 >> v299) | ((v294 ^ v302) << (v298 - 32)) | ((v294 ^ v302) >> v300);
                v294 = ((v294 ^ v302) >> v299) | (__PAIR64__(v294 ^ v302, v301) << v298 >> 32);
                v295 = v303 | (v301 << v298);
                --v297;
                v300 = 32 - v298;
              }
              while ( v297 );
              v140 = (unsigned int)v2734;
              v2683 = v294;
            }
            if ( v296 )
            {
              v304 = *(_DWORD *)(v140 + 836) & 0x3F;
              v305 = 64 - v304;
              v306 = 32 - v304;
              do
              {
                v307 = *(unsigned __int8 *)v292;
                v292 = (_DWORD *)((char *)v292 + 1);
                v308 = v295 ^ v307;
                v309 = (v308 >> v305) | (v294 << (v304 - 32)) | (v294 >> (32 - v304));
                v294 = (v294 >> v305) | (v308 << (v304 - 32)) | (v2683 << v304) | (v308 >> v306);
                v2683 = v294;
                v295 = v309 | (v308 << v304);
                --v296;
                v306 = 32 - v304;
              }
              while ( v296 );
              v140 = (unsigned int)v2734;
            }
            v310 = __PAIR64__(v294, v295);
            *(_DWORD *)(v140 + 856) += jj;
            while ( 1 )
            {
              LODWORD(v310) = FsRtlPrivateResetHighestLockOffset(v310, HIDWORD(v310), 31);
              if ( !v310 )
                break;
              v295 ^= v310;
            }
            v157 = v2822;
            v311 = v2822[3];
            if ( (v295 & 0x7FFFFFFF) != v311 )
            {
              if ( !*(_DWORD *)(v140 + 880) )
              {
                v312 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v312 + 16) = v295 & 0x7FFFFFFF ^ v311;
                *(_DWORD *)(v312 + 20) = 0;
              }
              v313 = v2822[1];
              if ( !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v2822;
                *(_DWORD *)(v140 + 912) = v313;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
            }
          }
          v2943 = v157 + 10;
          v2942[0] = *((_WORD *)v157 + 10);
          v2942[1] = v2942[0];
          if ( (*(int (__fastcall **)(__int16 *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int *))(v140 + 316))(
                 v2942,
                 0,
                 0,
                 0,
                 *(_DWORD *)(v140 + 628),
                 0,
                 0,
                 &v2928) < 0 )
            goto LABEL_1564;
          v314 = v2928;
          if ( v2928 != v157[4] && !*(_DWORD *)(v140 + 880) )
          {
            *(_DWORD *)(v140 + 888) = v140 - 1849117464;
            *(_DWORD *)(v140 + 892) = 0;
            *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
            *(_DWORD *)(v140 + 900) = 0;
            *(_QWORD *)(v140 + 904) = *v157;
            *(_DWORD *)(v140 + 912) = v314;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
          goto LABEL_381;
        case 10:
          if ( v157[4] && !*(_DWORD *)(v140 + 988) )
            goto LABEL_210;
          v316 = (unsigned int)&v157[3 * *(_DWORD *)(v140 + 852) + 10];
          v2747 = (_DWORD *)v316;
          v2851 = &v157[3 * v157[5] + 10];
          v317 = v2851;
          while ( 1 )
          {
            if ( *(int *)v316 >= 0 )
            {
              v318 = *(_QWORD *)(v316 + 4);
              v319 = *(_DWORD **)(v316 + 8);
              v2829 = v319;
              v2845 = (unsigned int)v319;
              v320 = (char *)HIDWORD(v318);
              jj = v318;
              if ( HIDWORD(v318) < (unsigned int)(v318 + HIDWORD(v318)) )
              {
                do
                {
                  __pld(v320);
                  v320 += 128;
                }
                while ( (unsigned int)v320 < (int)v318 + HIDWORD(v318) );
              }
              HIDWORD(v321) = *(_DWORD *)(v140 + 844);
              v322 = *(_DWORD *)(v140 + 840);
              v323 = v318;
              v2684 = v318;
              if ( (unsigned int)v318 >= 8 )
              {
                v324 = (unsigned int)v318 >> 3;
                v325 = *(_DWORD *)(v140 + 836) & 0x3F;
                v326 = 64 - v325;
                do
                {
                  v323 -= 8;
                  v327 = v322 ^ *v319;
                  v328 = HIDWORD(v321) ^ v319[1];
                  LODWORD(v321) = (v327 >> v326) | (v328 << (v325 - 32)) | (v328 >> (32 - v325));
                  HIDWORD(v321) = (v328 >> v326) | (__PAIR64__(v328, v327) << v325 >> 32);
                  v322 = v321 | (v327 << v325);
                  v319 = v2829 + 2;
                  v2829 += 2;
                  --v324;
                }
                while ( v324 );
                v140 = (unsigned int)v2734;
                v2684 = v323;
              }
              if ( v323 )
              {
                v329 = *(_DWORD *)(v140 + 836) & 0x3F;
                v330 = 64 - v329;
                do
                {
                  v331 = v322 ^ *(unsigned __int8 *)v319;
                  LODWORD(v321) = (v331 >> v330) | (HIDWORD(v321) << (v329 - 32)) | (HIDWORD(v321) >> (32 - v329));
                  HIDWORD(v321) = (HIDWORD(v321) >> v330) | (v331 << (v329 - 32)) | (HIDWORD(v321) << v329) | (v331 >> (32 - v329));
                  v319 = (_DWORD *)((char *)v319 + 1);
                  _ZF = v2684-- == 1;
                  v322 = v321 | (v331 << v329);
                }
                while ( !_ZF );
                v140 = (unsigned int)v2734;
              }
              LODWORD(v321) = v322;
              *(_DWORD *)(v140 + 856) += jj;
              while ( 1 )
              {
                LODWORD(v321) = FsRtlPrivateResetHighestLockOffset(v321, HIDWORD(v321), 31);
                if ( !v321 )
                  break;
                v322 ^= v321;
              }
              v332 = *v2747 & 0x7FFFFFFF;
              if ( (v322 & 0x7FFFFFFF) == v332 )
              {
                v316 = (unsigned int)v2747;
                v317 = v2851;
                v157 = v2822;
              }
              else
              {
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  v333 = *(_DWORD *)(v140 + 688);
                  *(_DWORD *)(v333 + 16) = v322 & 0x7FFFFFFF ^ v332;
                  *(_DWORD *)(v333 + 20) = 0;
                }
                v157 = v2822;
                v316 = (unsigned int)v2747;
                v317 = v2851;
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = v2845;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
            }
            v316 += 12;
            v2747 = (_DWORD *)v316;
            v334 = v316 == (_DWORD)v317;
            if ( v316 >= (unsigned int)v317 )
              break;
            if ( *(_DWORD *)(v140 + 856) >= *(_DWORD *)(v140 + 860) )
            {
              v334 = v316 == (_DWORD)v317;
              break;
            }
          }
          if ( v334 )
          {
            *(_DWORD *)(v140 + 852) = 0;
            goto LABEL_276;
          }
          v251 = (int)(v316 - (_DWORD)(v157 + 10)) / 12;
LABEL_281:
          *(_DWORD *)(v140 + 852) = v251;
          goto LABEL_1564;
        case 13:
        case 14:
          if ( v164 == 14 && !*(_DWORD *)(v140 + 988) )
            goto LABEL_1565;
          v335 = (_DWORD *)v157[1];
          jj = v157[2];
          v336 = (char *)v335;
          if ( v335 < (_DWORD *)((char *)v335 + jj) )
          {
            do
            {
              __pld(v336);
              v336 += 128;
            }
            while ( v336 < (char *)v335 + jj );
          }
          v337 = *(_DWORD *)(v140 + 844);
          v338 = *(_DWORD *)(v140 + 840);
          v339 = jj;
          v2685 = v337;
          if ( jj >= 8 )
          {
            v340 = jj >> 3;
            v341 = *(_DWORD *)(v140 + 836) & 0x3F;
            v342 = 64 - v341;
            v343 = 32 - v341;
            do
            {
              v339 -= 8;
              v344 = v338 ^ *v335;
              v345 = v335[1];
              v335 += 2;
              v346 = (v344 >> v342) | ((v345 ^ v337) << (v341 - 32)) | ((v345 ^ v337) >> v343);
              v337 = ((v345 ^ v337) >> v342) | (__PAIR64__(v345 ^ v337, v344) << v341 >> 32);
              v338 = v346 | (v344 << v341);
              --v340;
              v343 = 32 - v341;
            }
            while ( v340 );
            v140 = (unsigned int)v2734;
            v2685 = v337;
          }
          if ( v339 )
          {
            v347 = *(_DWORD *)(v140 + 836) & 0x3F;
            v348 = 64 - v347;
            v349 = 32 - v347;
            do
            {
              v350 = *(unsigned __int8 *)v335;
              v335 = (_DWORD *)((char *)v335 + 1);
              v351 = v338 ^ v350;
              v352 = (v351 >> v348) | (v337 << (v347 - 32)) | (v337 >> (32 - v347));
              v337 = (v337 >> v348) | (v351 << (v347 - 32)) | (v2685 << v347) | (v351 >> v349);
              v2685 = v337;
              v338 = v352 | (v351 << v347);
              --v339;
              v349 = 32 - v347;
            }
            while ( v339 );
            v140 = (unsigned int)v2734;
          }
          v353 = __PAIR64__(v337, v338);
          *(_DWORD *)(v140 + 856) += jj;
          while ( 1 )
          {
            LODWORD(v353) = FsRtlPrivateResetHighestLockOffset(v353, HIDWORD(v353), 31);
            if ( !v353 )
              break;
            v338 ^= v353;
          }
          if ( (v338 & 0x7FFFFFFF) != v2822[3] )
          {
            __dmb(0xFu);
            if ( (v2822[4] & 1) == 0 || (v354 = **(unsigned __int8 **)(v140 + 680), __dmb(0xBu), !v354) )
            {
              if ( !*(_DWORD *)(v140 + 880) )
              {
                v355 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v355 + 16) = v338 & 0x7FFFFFFF ^ v2822[3];
                *(_DWORD *)(v355 + 20) = 0;
              }
              v186 = v2822[1];
              if ( !*(_DWORD *)(v140 + 880) )
                goto LABEL_434;
            }
          }
          goto LABEL_1564;
        case 15:
          if ( *(_DWORD *)(v140 + 952) != 6 )
            goto LABEL_1565;
          *(_DWORD *)(v140 + 856) += 256;
          v285 = *(_DWORD *)(v140 + 684);
          v286 = (*(int (__fastcall **)(int))(v140 + 424))(v285);
          if ( v286 )
          {
            v287 = (*(int (**)(void))(v140 + 428))();
            v288 = v157[4];
            if ( v288 )
            {
              if ( v288 != v287 && !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v157;
                *(_DWORD *)(v140 + 912) = v287;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
            }
            else
            {
              v289 = *(_QWORD *)(v140 + 980);
              if ( (!(_DWORD)v289 || v287 < HIDWORD(v289) || v287 > (int)v289 + HIDWORD(v289) - 1)
                && !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v157;
                *(_DWORD *)(v140 + 912) = v287;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
              v157[4] = v287;
            }
            (*(void (__fastcall **)(int, int))(v140 + 432))(v285, v286);
          }
          goto LABEL_1564;
        case 16:
          v356 = *(_DWORD *)v157[5];
          if ( !v356 )
            goto LABEL_1565;
          v357 = v157[4];
          goto LABEL_437;
        case 17:
          v356 = *(_DWORD *)v157[10];
          if ( !v356 || v356 == v157[4] || v356 == v157[5] )
            goto LABEL_1565;
          v357 = v157[6];
          goto LABEL_437;
        case 18:
        case 20:
          v356 = *(_DWORD *)v157[6];
          if ( !v356 || v356 == v157[4] )
            goto LABEL_1565;
          v357 = v157[5];
          goto LABEL_437;
        case 19:
          v356 = *(_DWORD *)v157[6];
          if ( !v356 || v356 == v157[4] || v356 == v157[5] )
            goto LABEL_1565;
          v357 = v157[10];
LABEL_437:
          if ( v356 != v357 && !*(_DWORD *)(v140 + 880) )
            goto LABEL_439;
          goto LABEL_1565;
        case 24:
          v2734 = (_BYTE *)v140;
          while ( 2 )
          {
            v358 = *(_DWORD *)(v140 + 852);
            switch ( v358 )
            {
              case 0:
                v2920 = 0;
                v359 = 0;
                for ( i = (*(int (__fastcall **)(int *))(v140 + 444))(&v2920);
                      i;
                      i = (*(int (__fastcall **)(int *))(v140 + 444))(&v2920) )
                {
                  ++v359;
                  (*(void (__fastcall **)(int, int *, char *))(v140 + 328))(i, &v2919, v2949);
                  if ( !v2919 && !(*(int (__fastcall **)(int, int *))(v140 + 332))(i, &v2919) )
                  {
                    v2822[4] = i;
                    v783 = *(int ***)(v140 + 688);
                    *v783 = v2822;
                    v783[2] = (int *)40;
                    v784 = *(_DWORD *)(v140 + 688);
                    *(_DWORD *)(v784 + 4) = i;
                    *(_DWORD *)(v784 + 12) = 4096;
                    if ( !*(_DWORD *)(v140 + 880) )
                    {
                      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                      *(_DWORD *)(v140 + 892) = 0;
                      *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                      *(_DWORD *)(v140 + 900) = 0;
                      *(_QWORD *)(v140 + 904) = *v2822;
                      *(_DWORD *)(v140 + 912) = 3;
                      *(_DWORD *)(v140 + 916) = 0;
                      *(_DWORD *)(v140 + 880) = 1;
                    }
                  }
                }
                goto LABEL_1066;
              case 1:
                v2925 = 0;
                v359 = 0;
                v778 = (*(int (__fastcall **)(int))(v140 + 356))(12);
                for ( j = (*(int (__fastcall **)(int *))(v140 + 448))(&v2925);
                      j;
                      j = (*(int (__fastcall **)(int *))(v140 + 448))(&v2925) )
                {
                  ++v359;
                  (*(void (__fastcall **)(int, int *, char *))(v140 + 328))(j, &v2921, v2958);
                  if ( !v2921 && !(*(int (__fastcall **)(int, int *))(v140 + 332))(j, &v2921) )
                  {
                    v2822[4] = j;
                    v780 = *(int ***)(v140 + 688);
                    *v780 = v2822;
                    v780[2] = (int *)40;
                    v781 = *(_DWORD *)(v140 + 688);
                    *(_DWORD *)(v781 + 4) = j;
                    *(_DWORD *)(v781 + 12) = 4096;
                    if ( !*(_DWORD *)(v140 + 880) )
                    {
                      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                      *(_DWORD *)(v140 + 892) = 0;
                      *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                      *(_DWORD *)(v140 + 900) = 0;
                      *(_QWORD *)(v140 + 904) = *v2822;
                      *(_DWORD *)(v140 + 912) = 4;
                      *(_DWORD *)(v140 + 916) = 0;
                      *(_DWORD *)(v140 + 880) = 1;
                    }
                  }
                }
                (*(void (__fastcall **)(int))(v140 + 360))(v778);
                goto LABEL_1066;
              case 2:
                v359 = 0;
                v773 = 0;
                while ( 1 )
                {
                  v2924 = 0;
                  while ( 1 )
                  {
                    do
                    {
                      if ( !(*(int (__fastcall **)(int, int *, int *))(v140 + 440))(v773, &v2924, &v2910) )
                        goto LABEL_1051;
                      v774 = (*(int (__fastcall **)(int))(v140 + 424))(v2910);
                    }
                    while ( !v774 );
                    ++v359;
                    v775 = (*(int (**)(void))(v140 + 428))();
                    (*(void (__fastcall **)(int, int *, char *))(v140 + 328))(v775, &v2923, v2953);
                    if ( !v2923 && !(*(int (__fastcall **)(int, int *))(v140 + 332))(v775, &v2923) )
                      break;
                    (*(void (__fastcall **)(int, int))(v140 + 432))(v2910, v774);
                  }
                  v2822[4] = v775;
                  v776 = *(int ***)(v140 + 688);
                  *v776 = v2822;
                  v776[2] = (int *)40;
                  v777 = *(_DWORD *)(v140 + 688);
                  *(_DWORD *)(v777 + 4) = v775;
                  *(_DWORD *)(v777 + 12) = 4096;
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_QWORD *)(v140 + 904) = *v2822;
                    *(_DWORD *)(v140 + 912) = v773;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
LABEL_1051:
                  if ( (unsigned int)++v773 >= 3 )
                    goto LABEL_1066;
                }
            }
            if ( v358 != 3 )
            {
              if ( v358 != 4 )
              {
                v251 = 0;
                goto LABEL_281;
              }
              v359 = 0;
              v2823 = 0;
              for ( HIDWORD(v360) = (*(int (__fastcall **)(_DWORD))(v140 + 456))(0);
                    HIDWORD(v360);
                    HIDWORD(v360) = (*(int (__fastcall **)(_DWORD))(v140 + 456))(HIDWORD(v360)) )
              {
                v2918 = 0;
                v361 = 1;
                LODWORD(v360) = (*(int (__fastcall **)(_DWORD, int *))(v140 + 452))(HIDWORD(v360), &v2918);
                if ( (_DWORD)v360 )
                {
                  do
                  {
                    ++v361;
                    (*(void (__fastcall **)(_DWORD, int *, char *))(v140 + 328))(v360, &v2927, v2956);
                    if ( !v2927 && !(*(int (__fastcall **)(_DWORD, int *))(v140 + 332))(v360, &v2927) )
                    {
                      *((_QWORD *)v2822 + 2) = v360;
                      v362 = *(int ***)(v140 + 688);
                      *v362 = v2822;
                      v362[2] = (int *)40;
                      v363 = *(_DWORD *)(v140 + 688);
                      *(_DWORD *)(v363 + 4) = v360;
                      *(_DWORD *)(v363 + 12) = 4096;
                      if ( !*(_DWORD *)(v140 + 880) )
                      {
                        *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                        *(_DWORD *)(v140 + 892) = 0;
                        *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                        *(_DWORD *)(v140 + 900) = 0;
                        *(_QWORD *)(v140 + 904) = *v2822;
                        *(_DWORD *)(v140 + 912) = 6;
                        *(_DWORD *)(v140 + 916) = 0;
                        *(_DWORD *)(v140 + 880) = 1;
                      }
                    }
                    LODWORD(v360) = (*(int (__fastcall **)(_DWORD, int *))(v140 + 452))(HIDWORD(v360), &v2918);
                  }
                  while ( (_DWORD)v360 );
                  v359 = v2823;
                }
                v359 += v361;
                v2823 = v359;
              }
              goto LABEL_1066;
            }
            v364 = v157;
            v365 = **(_DWORD **)(v140 + 616);
            v366 = v2822[6];
            v2843 = (unsigned int *)v140;
            v359 = 0;
            jj = v365;
            if ( v366 )
            {
              v359 = 1;
              if ( v365 != v366 )
              {
                v2822[4] = v365;
                v367 = *(int ***)(v140 + 688);
                *v367 = v2822;
                v367[2] = (int *)40;
                v368 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v368 + 4) = v365;
                *(_DWORD *)(v368 + 12) = 4096;
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = 5;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
              goto LABEL_1066;
            }
            if ( !v365 )
              goto LABEL_1066;
            v359 = 1;
            if ( MEMORY[0xFFFF92E8] <= 0x28000u )
            {
              v369 = 0;
              goto LABEL_1038;
            }
            v2850 = (_DWORD *)(*(int (**)(void))(v140 + 328))();
            if ( !v2850 )
            {
              v369 = -1073741701;
              goto LABEL_1035;
            }
            v370 = v2872;
            v371 = v2865;
            v372 = 12;
            v373 = &v2929;
            v374 = 3;
            v2845 = (unsigned int)v2872;
            do
            {
              v372 -= 4;
              --v374;
              *v373++ = 0;
            }
            while ( v374 );
            for ( ; v372; --v372 )
            {
              *(_BYTE *)v373 = 0;
              v373 = (int *)((char *)v373 + 1);
            }
            v375 = 0;
            if ( *(_DWORD *)(v140 + 828) )
            {
              v376 = v2930;
              v377 = v2931;
              v378 = v2929;
              while ( 1 )
              {
                v379 = v140;
                if ( *(_DWORD *)(v140 + 1084) )
                  v379 = *(_DWORD *)(v140 + 1084);
                v380 = 0;
                v381 = v379 + *(_DWORD *)(v379 + 824);
                if ( v378 && v376 <= v375 )
                {
                  v380 = v376;
                  v381 = v379 + v377;
                }
                if ( v380 != v375 )
                  break;
LABEL_514:
                v378 = 1;
                v377 = v381 - v379;
                v2929 = 1;
                v2930 = v380;
                v2931 = v381 - v379;
                v373 = *(int **)v381;
                v376 = v380;
                if ( (*(_DWORD *)v381 == 1 || v373 == (int *)12)
                  && *(_DWORD **)(v381 + 4) == v2850
                  && *(_DWORD *)(v381 + 8) == v371
                  || (v373 == (int *)33 || v373 == (int *)34) && *(_DWORD **)(v381 + 20) == v370 )
                {
                  goto LABEL_523;
                }
                if ( ++v375 >= *(_DWORD *)(v140 + 828) )
                  goto LABEL_522;
              }
              v382 = v375 - v380;
              v380 = v375;
              while ( 2 )
              {
                v383 = *(int **)v381;
                if ( *(int *)v381 > 17 )
                {
                  if ( v383 != (int *)19 )
                  {
                    if ( v383 != (int *)28 )
                    {
                      if ( v383 != (int *)30 )
                      {
                        if ( (unsigned int)v383 - 33 <= 1 )
                        {
                          v387 = 5 * (((*(_DWORD *)(v381 + 24) + (*(_DWORD *)(v381 + 20) & 0xFFFu) + 4095) >> 12) + 2);
                          goto LABEL_508;
                        }
LABEL_496:
                        v384 = 40;
LABEL_512:
                        v381 += v384;
                        if ( !--v382 )
                        {
                          v140 = (unsigned int)v2734;
                          v370 = (_DWORD *)v2845;
                          goto LABEL_514;
                        }
                        continue;
                      }
                      v385 = ((((unsigned int)(*(_DWORD *)(v381 + 24) - 1) >> 3) + 7) & 0xFFFFFFF8)
                           + 24 * *(unsigned __int16 *)(v381 + 28);
LABEL_501:
                      v384 = v385 + 40;
                      goto LABEL_512;
                    }
                    v386 = *(unsigned __int16 *)(v381 + 24);
LABEL_499:
                    v384 = (v386 + 47) & 0xFFFFFFF8;
                    goto LABEL_512;
                  }
                }
                else if ( *(_DWORD *)v381 != 17 )
                {
                  if ( v383 == (int *)1 )
                    goto LABEL_502;
                  if ( v383 == (int *)7 )
                  {
                    v385 = 24 * *(_DWORD *)(v381 + 16);
                    goto LABEL_501;
                  }
                  if ( v383 != (int *)8 )
                  {
                    if ( v383 != (int *)10 )
                    {
                      if ( v383 != (int *)12 )
                        goto LABEL_496;
LABEL_502:
                      v387 = (*(_DWORD *)(v381 + 8) >> 3) + 10;
LABEL_508:
                      v384 = 4 * v387;
                      goto LABEL_512;
                    }
                    v385 = 12 * *(_DWORD *)(v381 + 20);
                    goto LABEL_501;
                  }
                  v386 = *(unsigned __int16 *)(v381 + 20);
                  goto LABEL_499;
                }
                break;
              }
              v384 = 44;
              goto LABEL_512;
            }
LABEL_522:
            v381 = 0;
LABEL_523:
            if ( v381 )
            {
              v369 = -1073741554;
              goto LABEL_1034;
            }
            v388 = (*(int (__fastcall **)(unsigned int, _DWORD, int *))(v140 + 408))(jj, 0, v373);
            v389 = v2865;
            v390 = v388;
            v2854 = v2872;
            v391 = *(int (__fastcall **)(_DWORD))(v140 + 324);
            v2841 = v388;
            v2861 = v2865;
            v2712 = v391(v2872);
            if ( !v2712 )
              goto LABEL_526;
            v392 = v389 >> 3;
            v2847 = 4 * (v389 >> 3);
            if ( v390 )
              v393 = 12;
            else
              v393 = 1;
            v394 = *(_DWORD *)(v140 + 796);
            v395 = *(_DWORD *)(v140 + 992);
            v396 = *(_DWORD *)(v140 + 928);
            v397 = v140;
            if ( (v395 & 0x20000000) == 0 )
              v397 = 0;
            v2845 = *(_DWORD *)(v140 + 796);
            if ( v396 > 1 )
            {
              if ( !v397 )
              {
                v399 = sub_5FD658;
                goto LABEL_540;
              }
              v398 = *(_DWORD *)(v397 + 816);
              goto LABEL_538;
            }
            if ( v397 )
            {
              v398 = *(_DWORD *)(v397 + 812);
LABEL_538:
              v399 = (_DWORD *(__fastcall *)(int, int))((v398 | 1) + v397);
              goto LABEL_540;
            }
            v399 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
LABEL_540:
            if ( (v395 & 4) == 0 )
              v399 = *(_DWORD *(__fastcall **)(int, int))(v140 + 1080);
            v400 = v399(v140, v394 + 4 * (v389 >> 3) + 40);
            v2852 = (unsigned int)v400;
            if ( !v400 )
            {
LABEL_1033:
              v369 = -1073741670;
              goto LABEL_1034;
            }
            v401 = *(_DWORD *)(v140 + 992);
            if ( (v401 & 4) == 0 )
            {
              v402 = *(_DWORD *)(v140 + 796);
              v403 = *(_DWORD *)(v140 + 928);
              v404 = *(_DWORD *)(v140 + 780);
              if ( (v401 & 0x20000000) == 0 )
                v403 = 0;
              v405 = (_DWORD *)v140;
              if ( v402 >= 4 )
              {
                v401 = v402 >> 2;
                do
                {
                  v402 -= 4;
                  --v401;
                  *v405++ = 0;
                }
                while ( v401 );
              }
              for ( ; v402; --v402 )
              {
                *(_BYTE *)v405 = 0;
                v405 = (_DWORD *)((char *)v405 + 1);
              }
              v406 = v400[232];
              v400[232] = v403;
              if ( v403 == 3 )
              {
                v407 = (void (__fastcall *)(_DWORD, _DWORD, _DWORD))v400[124];
              }
              else
              {
                v407 = (void (__fastcall *)(_DWORD, _DWORD, _DWORD))v400[55];
                v401 = v400[87];
                if ( v403 && v403 == 1 )
                {
                  ((void (__fastcall *)(int, _DWORD))v401)(v404 - 4, *(_DWORD *)(v404 - 4));
LABEL_557:
                  v400[232] = v406;
                  v389 = v2861;
                  goto LABEL_558;
                }
              }
              v407(v404, v405, v401);
              goto LABEL_557;
            }
LABEL_558:
            v408 = (_DWORD *)((char *)v400 + v394);
            v409 = 10;
            v400[248] &= 0xFFFFFFFB;
            v410 = (_DWORD *)((char *)v400 + v394);
            ++v400[207];
            v411 = 40;
            do
            {
              v411 -= 4;
              --v409;
              *v410++ = 0;
            }
            while ( v409 );
            for ( ; v411; --v411 )
            {
              *(_BYTE *)v410 = 0;
              v410 = (_DWORD *)((char *)v410 + 1);
            }
            HIDWORD(v412) = v2850;
            *v408 = v393;
            v408[1] = HIDWORD(v412);
            v408[2] = v389;
            LODWORD(v412) = HIDWORD(v412);
            v2830 = HIDWORD(v412);
            v413 = (char *)HIDWORD(v412);
            if ( HIDWORD(v412) < v389 + HIDWORD(v412) )
            {
              do
              {
                __pld(v413);
                v413 += 128;
              }
              while ( (unsigned int)v413 < v389 + HIDWORD(v412) );
            }
            v414 = v389;
            HIDWORD(v412) = v400[211];
            v415 = v400[210];
            v2748 = v414;
            if ( v2861 >= 8 )
            {
              v416 = v392;
              v417 = v400[209] & 0x3F;
              v418 = 64 - v417;
              do
              {
                v419 = v415 ^ *(_DWORD *)v412;
                v420 = HIDWORD(v412) ^ *(_DWORD *)(v412 + 4);
                v421 = (v419 >> v418) | (v420 << (v417 - 32)) | (v420 >> (32 - v417));
                HIDWORD(v412) = (v420 >> v418) | (v419 << (v417 - 32)) | (v420 << v417) | (v419 >> (32 - v417));
                v415 = v421 | (v419 << v417);
                v414 = v2748 - 8;
                v2748 -= 8;
                LODWORD(v412) = v2830 + 8;
                v2830 += 8;
                --v416;
              }
              while ( v416 );
              v140 = (unsigned int)v2734;
              v400 = (_DWORD *)v2852;
            }
            if ( v414 )
            {
              v422 = v400[209] & 0x3F;
              v423 = 64 - v422;
              do
              {
                v424 = v415 ^ *(unsigned __int8 *)v412;
                v2831 = v412 + 1;
                LODWORD(v412) = (v424 >> v423) | (HIDWORD(v412) << (v422 - 32)) | (HIDWORD(v412) >> (32 - v422));
                HIDWORD(v412) = (HIDWORD(v412) >> v423) | (v424 << (v422 - 32)) | (HIDWORD(v412) << v422) | (v424 >> (32 - v422));
                v415 = v412 | (v424 << v422);
                _ZF = v2748 == 1;
                LODWORD(v412) = v2831;
                --v2748;
              }
              while ( !_ZF );
              v140 = (unsigned int)v2734;
            }
            v425 = v2852;
            v426 = v2861;
            LODWORD(v412) = v415;
            *(_DWORD *)(v2852 + 856) += v2861;
            while ( 1 )
            {
              LODWORD(v412) = FsRtlPrivateResetHighestLockOffset(v412, HIDWORD(v412), 31);
              if ( !v412 )
                break;
              v415 ^= v412;
            }
            v427 = -1073741275;
            v428 = (_DWORD *)(v2845 + v425);
            v428[3] = v415 & 0x7FFFFFFF;
            v429 = v428 + 4;
            *(_DWORD *)(v425 + 856) += v426;
            v430 = *(_DWORD *)(v425 + 652);
            v431 = (_DWORD *)(*(_DWORD *)(v425 + 640) + 16);
            v432 = (*(int (__fastcall **)(int))(v425 + 356))(12);
            v433 = v430;
            v434 = v2852;
            (*(void (__fastcall **)(int))(v2852 + 260))(v433);
            v435 = v2854;
            v436 = &v431[4 * **(_DWORD **)(v434 + 640)];
            while ( (_DWORD *)v431[1] != v2854 )
            {
              v431 += 4;
              if ( v431 >= v436 )
                goto LABEL_581;
            }
            v435 = (_DWORD *)v431[1];
            v437 = v431[2];
            v438 = v431[3];
            *v429 = *v431;
            v428[5] = v435;
            v428[6] = v437;
            v428[7] = v438;
            v427 = 0;
LABEL_581:
            (*(void (__fastcall **)(_DWORD, _DWORD *))(v434 + 292))(*(_DWORD *)(v434 + 652), v435);
            (*(void (__fastcall **)(int))(v434 + 360))(v432);
            if ( v427 < 0 )
            {
              v439 = 16;
              v440 = 4;
              do
              {
                v439 -= 4;
                --v440;
                *v429++ = 0;
              }
              while ( v440 );
              for ( ; v439; --v439 )
              {
                *(_BYTE *)v429 = 0;
                v429 = (_DWORD *)((char *)v429 + 1);
              }
              v428[4] = 1;
            }
            v441 = v2847;
            v2795 = v428 + 10;
            v442 = v428 + 10;
            if ( v2847 >= 8 )
            {
              v443 = v2847 >> 3;
              do
              {
                v441 -= 8;
                --v443;
                *v442 = -1;
                v442[1] = -1;
                v442 += 2;
              }
              while ( v443 );
            }
            for ( ; v441; --v441 )
            {
              *(_BYTE *)v442 = -1;
              v442 = (_DWORD *)((char *)v442 + 1);
            }
            v444 = (_BYTE *)v2852;
            v445 = *v2850;
            v2759 = &v2850[2 * (v2861 >> 3)];
            v446 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v2852 + 336);
            v447 = v2850;
            v448 = -1;
            v449 = 0;
            v2832 = v2850;
            v2738 = -1;
            v2851 = 0;
            v450 = (int *)v446(v2712, v2854, v445);
LABEL_672:
            v513 = v450;
            v2847 = (unsigned int)v450;
            if ( !v450 )
              goto LABEL_526;
            v451 = 0;
            v2749 = 0;
            if ( (v450[9] & v2871) != 0
              || *v450 == 1414090313 && v450[1] == 1195525195
              || *v450 == 1162297680
              && ((v452 = *((unsigned __int16 *)v450 + 2), v452 == 30839) || v452 == 29303 || v452 == 30583) )
            {
              v451 = 1;
              v2749 = 1;
            }
            else
            {
              v454 = (int *)*((_DWORD *)v444 + 235);
              v453 = (int *)*((_DWORD *)v444 + 234);
              v455 = *((_QWORD *)v444 + 118);
              v456 = 7;
              v457 = v513;
              while ( 1 )
              {
                v459 = *v457++;
                v458 = v459;
                v460 = *v453++;
                if ( v458 != v460 )
                  break;
                v456 -= 4;
                if ( v456 < 4 )
                {
                  if ( !v456 )
                  {
LABEL_627:
                    v451 = 1;
                    v2749 = 1;
                    goto LABEL_628;
                  }
                  while ( 1 )
                  {
                    v462 = *(unsigned __int8 *)v457;
                    v457 = (int *)((char *)v457 + 1);
                    v461 = v462;
                    v463 = *(unsigned __int8 *)v453;
                    v453 = (int *)((char *)v453 + 1);
                    if ( v461 != v463 )
                      goto LABEL_607;
                    if ( !--v456 )
                      goto LABEL_627;
                  }
                }
              }
LABEL_607:
              v464 = 8;
              v465 = v513;
              while ( 1 )
              {
                v467 = *v465++;
                v466 = v467;
                v468 = *v454++;
                if ( v466 != v468 )
                  break;
                v464 -= 4;
                if ( v464 < 4 )
                {
                  if ( !v464 )
                    goto LABEL_627;
                  while ( 1 )
                  {
                    v470 = *(unsigned __int8 *)v465;
                    v465 = (int *)((char *)v465 + 1);
                    v469 = v470;
                    v471 = *(unsigned __int8 *)v454;
                    v454 = (int *)((char *)v454 + 1);
                    if ( v469 != v471 )
                      goto LABEL_614;
                    if ( !--v464 )
                      goto LABEL_627;
                  }
                }
              }
LABEL_614:
              v472 = 4;
              v473 = v513;
              while ( 1 )
              {
                v475 = *v473++;
                v474 = v475;
                v476 = *(_DWORD *)v455;
                LODWORD(v455) = v455 + 4;
                if ( v474 != v476 )
                  break;
                v472 -= 4;
                if ( v472 < 4 )
                {
                  if ( !v472 )
                    goto LABEL_627;
                  while ( 1 )
                  {
                    v478 = *(unsigned __int8 *)v473;
                    v473 = (int *)((char *)v473 + 1);
                    v477 = v478;
                    v479 = *(unsigned __int8 *)v455;
                    LODWORD(v455) = v455 + 1;
                    if ( v477 != v479 )
                      goto LABEL_621;
                    if ( !--v472 )
                      goto LABEL_627;
                  }
                }
              }
LABEL_621:
              v480 = 6;
              v481 = v513;
              while ( 1 )
              {
                v483 = *v481++;
                v482 = v483;
                v484 = *(_DWORD *)HIDWORD(v455);
                HIDWORD(v455) += 4;
                if ( v482 != v484 )
                  break;
                v480 -= 4;
                if ( v480 < 4 )
                {
                  if ( !v480 )
                    goto LABEL_627;
                  while ( 1 )
                  {
                    v486 = *(unsigned __int8 *)v481;
                    v481 = (int *)((char *)v481 + 1);
                    v485 = v486;
                    v487 = (unsigned __int8)*(_BYTE *)HIDWORD(v455);
                    ++HIDWORD(v455);
                    if ( v485 != v487 )
                      goto LABEL_628;
                    if ( !--v480 )
                      goto LABEL_627;
                  }
                }
              }
LABEL_628:
              v447 = v2832;
              v448 = v2738;
              v449 = v2851;
            }
            if ( v513[9] < 0 )
            {
              v451 = 1;
              v2749 = 1;
            }
            if ( v451 && *v513 == 1414090313 && v513[1] == 1195525195 && (*((_DWORD *)v444 + 248) & v2873) != 0 )
            {
              v451 = 0;
              v2749 = 0;
            }
            v488 = v513[4];
            if ( v488 <= v513[2] )
              v488 = v513[2];
            v489 = v513[3] + v488;
            v2859 = v489;
            while ( 1 )
            {
              v490 = v447[1];
              if ( (v490 & 3) == 0 )
              {
                if ( v490 < v448 )
                  v2738 = v447[1];
                if ( v490 > (unsigned int)v449 )
                {
                  v449 = (int *)v447[1];
                  v2851 = v449;
                }
              }
              v492 = *v447;
              v447 += 2;
              v491 = v492;
              v493 = v2854;
              v140 = (unsigned int)v2734;
              v494 = v492 & 0xFFFFFFFE;
              v495 = (char *)v2854 + (v492 & 0xFFFFFFFE);
              v2846 = (unsigned int)v495;
              v2832 = v447;
              v496 = (v490 & 3) != 0 ? (v490 >> 2) & 0x7FF : *(_DWORD *)((char *)v2854 + v490) & 0x3FFFF;
              v497 = ((v491 + 2 * v496) & 0xFFFFFFFE) - v494;
              v2845 = v497;
              if ( v451 )
              {
                v498 = 0x80000000;
              }
              else
              {
                for ( k = v495; k < &v495[v497]; k += 128 )
                  __pld(k);
                v500 = *((_DWORD *)v444 + 211);
                v501 = *((_DWORD *)v444 + 210);
                v502 = (_DWORD *)v497;
                v2844 = (_DWORD *)v497;
                v2686 = v500;
                if ( v497 >= 8 )
                {
                  v503 = v497 >> 3;
                  v504 = *((_DWORD *)v444 + 209) & 0x3F;
                  v505 = 64 - v504;
                  do
                  {
                    v506 = v501 ^ *(_DWORD *)v495;
                    v507 = *((_DWORD *)v495 + 1) ^ v500;
                    v500 = (v507 >> v505) | (v506 << (v504 - 32)) | (v507 << v504) | (v506 >> (32 - v504));
                    v501 = (v506 >> v505) | (v507 << (v504 - 32)) | (v507 >> (32 - v504)) | (v506 << v504);
                    v502 = v2844 - 2;
                    v2844 -= 2;
                    v495 = (char *)(v2846 + 8);
                    v2846 += 8;
                    --v503;
                  }
                  while ( v503 );
                  v140 = (unsigned int)v2734;
                  v444 = (_BYTE *)v2852;
                  v2686 = v500;
                }
                if ( v502 )
                {
                  v508 = *((_DWORD *)v444 + 209) & 0x3F;
                  v509 = 64 - v508;
                  do
                  {
                    v510 = v501 ^ (unsigned __int8)*v495;
                    v2846 = (unsigned int)(v495 + 1);
                    v511 = (v510 >> v509) | (v500 << (v508 - 32)) | (v500 >> (32 - v508));
                    v500 = (v500 >> v509) | (v510 << (v508 - 32)) | (v2686 << v508) | (v510 >> (32 - v508));
                    v501 = v511 | (v510 << v508);
                    _ZF = v2844 == (_DWORD *)1;
                    v495 = (char *)v2846;
                    v2844 = (_DWORD *)((char *)v2844 - 1);
                    v2686 = v500;
                  }
                  while ( !_ZF );
                  v140 = (unsigned int)v2734;
                  v444 = (_BYTE *)v2852;
                }
                v512 = __PAIR64__(v500, v501);
                *((_DWORD *)v444 + 214) += v2845;
                while ( 1 )
                {
                  LODWORD(v512) = FsRtlPrivateResetHighestLockOffset(v512, HIDWORD(v512), 31);
                  if ( !v512 )
                    break;
                  v501 ^= v512;
                }
                v489 = v2859;
                v513 = (int *)v2847;
                v451 = v2749;
                v449 = v2851;
                v493 = v2854;
                v498 = v501 & 0x7FFFFFFF;
                v447 = v2832;
              }
              *v2795 = v498;
              if ( v447 == v2759 )
                break;
              ++v2795;
              if ( *v447 >= (unsigned int)v513[3] )
              {
                v514 = v447[1];
                v515 = (v514 & 3) != 0 ? (v514 >> 2) & 0x7FF : *(_DWORD *)((char *)v493 + v514) & 0x3FFFF;
                v516 = (char *)v493 + ((*v447 + 2 * v515) & 0xFFFFFFFE);
                v448 = v2738;
                if ( (unsigned int)v516 <= v489 )
                  continue;
              }
              v450 = (int *)(*((int (__fastcall **)(int, _DWORD *, _DWORD))v444 + 84))(v2712, v2854, *v447);
              v448 = v2738;
              goto LABEL_672;
            }
            v517 = v2738;
            if ( v2738 == -1 && !v449 )
              v517 = 0;
            v518 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))*((_DWORD *)v444 + 80);
            v2948[0] = (int)v2872 + v517;
            v2944[0] = (int)v449 - v517;
            v2843 = (unsigned int *)v444;
            v519 = v518(v2872, 1, 0, &v2865);
            if ( v519 )
            {
              v520 = v2865;
            }
            else
            {
              v520 = 0;
              v2865 = 0;
            }
            v521 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))*((_DWORD *)v444 + 80);
            v2948[1] = v519;
            v2944[1] = v520;
            v522 = v521(v2872, 1, 12, &v2865);
            v2739 = (char *)v522;
            if ( v522 )
            {
              v523 = v2865;
            }
            else
            {
              v523 = 0;
              v2865 = 0;
            }
            v2687 = v523;
            v2944[2] = v523;
            v524 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))*((_DWORD *)v444 + 80);
            v2948[2] = v522;
            v525 = v524(v2872, 1, 10, &v2865);
            if ( v525 )
            {
              v526 = v2865;
            }
            else
            {
              v526 = 0;
              v2865 = 0;
            }
            v2944[3] = v526;
            v2948[3] = v525;
            if ( v2841 )
              v527 = 11;
            else
              v527 = 0;
            v528 = *((_DWORD *)v444 + 248);
            v529 = *((_DWORD *)v444 + 199);
            v530 = v444;
            if ( (v528 & 0x20000000) == 0 )
              v530 = 0;
            v2833 = v527;
            if ( *((int *)v444 + 232) > 1 )
            {
              if ( !v530 )
              {
                v532 = sub_5FD658;
                goto LABEL_699;
              }
              v531 = *((_DWORD *)v530 + 204);
              goto LABEL_697;
            }
            if ( v530 )
            {
              v531 = *((_DWORD *)v530 + 203);
LABEL_697:
              v532 = (_DWORD *(__fastcall *)(int, int))&v530[v531 | 1];
              goto LABEL_699;
            }
            v532 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
LABEL_699:
            if ( (v528 & 4) == 0 )
              v532 = (_DWORD *(__fastcall *)(int, int))*((_DWORD *)v444 + 270);
            v533 = v532((int)v444, v529 + 160);
            v2847 = (unsigned int)v533;
            if ( !v533 )
              goto LABEL_1033;
            v534 = *((_DWORD *)v444 + 248);
            if ( (v534 & 4) == 0 )
            {
              v535 = *((_DWORD *)v444 + 199);
              v536 = *((_DWORD *)v444 + 232);
              v537 = *((_DWORD *)v444 + 195);
              if ( (v534 & 0x20000000) == 0 )
                v536 = 0;
              if ( v535 >= 4 )
              {
                v538 = v535 >> 2;
                do
                {
                  v535 -= 4;
                  --v538;
                  *(_DWORD *)v444 = 0;
                  v444 += 4;
                }
                while ( v538 );
              }
              for ( ; v535; --v535 )
                *v444++ = 0;
              v539 = *((_DWORD *)v533 + 232);
              *((_DWORD *)v533 + 232) = v536;
              if ( v536 == 3 )
              {
                v540 = (void (__fastcall *)(_DWORD))*((_DWORD *)v533 + 124);
              }
              else
              {
                v540 = (void (__fastcall *)(_DWORD))*((_DWORD *)v533 + 55);
                if ( v536 && v536 == 1 )
                {
                  (*((void (__fastcall **)(int, _DWORD))v533 + 87))(v537 - 4, *(_DWORD *)(v537 - 4));
LABEL_716:
                  *((_DWORD *)v533 + 232) = v539;
                  goto LABEL_717;
                }
              }
              v540(v537);
              goto LABEL_716;
            }
LABEL_717:
            v541 = (int *)&v533[v529];
            v2713 = v541;
            *((_DWORD *)v533 + 248) &= 0xFFFFFFFB;
            v542 = *((_DWORD *)v533 + 207);
            v2851 = v541;
            *((_DWORD *)v533 + 207) = v542 + 4;
            v543 = 0;
            v2796 = 0;
            do
            {
              v544 = *(int *)((char *)v2944 + v543);
              LODWORD(v546) = *(int *)((char *)v2948 + v543);
              v545 = 40;
              v2750 = v546;
              HIDWORD(v546) = v541;
              v547 = 10;
              do
              {
                v545 -= 4;
                --v547;
                *(_DWORD *)HIDWORD(v546) = 0;
                HIDWORD(v546) += 4;
              }
              while ( v547 );
              for ( ; v545; --v545 )
              {
                *(_BYTE *)HIDWORD(v546) = 0;
                ++HIDWORD(v546);
              }
              *v541 = v527;
              v541[1] = v546;
              v541[2] = v544;
              v548 = (char *)v546;
              if ( (unsigned int)v546 < (unsigned int)v546 + v544 )
              {
                do
                {
                  __pld(v548);
                  v548 += 128;
                }
                while ( (unsigned int)v548 < (unsigned int)v546 + v544 );
              }
              v549 = v544;
              HIDWORD(v546) = *((_DWORD *)v533 + 211);
              v550 = *((_DWORD *)v533 + 210);
              v2846 = v544;
              if ( v544 >= 8 )
              {
                v551 = v544 >> 3;
                v552 = *((_DWORD *)v533 + 209) & 0x3F;
                v553 = 64 - v552;
                do
                {
                  v554 = v550 ^ *(_DWORD *)v546;
                  v555 = HIDWORD(v546) ^ *(_DWORD *)(v546 + 4);
                  v556 = (v554 >> v553) | (v555 << (v552 - 32)) | (v555 >> (32 - v552));
                  HIDWORD(v546) = (v555 >> v553) | (v554 << (v552 - 32)) | (v555 << v552) | (v554 >> (32 - v552));
                  v550 = v556 | (v554 << v552);
                  v549 = v2846 - 8;
                  v2846 -= 8;
                  LODWORD(v546) = v2750 + 8;
                  v2750 += 8;
                  --v551;
                }
                while ( v551 );
                v533 = (_BYTE *)v2847;
              }
              if ( v549 )
              {
                v557 = *((_DWORD *)v533 + 209) & 0x3F;
                v558 = 64 - v557;
                do
                {
                  v559 = v550 ^ *(unsigned __int8 *)v546;
                  v2751 = v546 + 1;
                  LODWORD(v546) = (v559 >> v558) | (HIDWORD(v546) << (v557 - 32)) | (HIDWORD(v546) >> (32 - v557));
                  HIDWORD(v546) = (HIDWORD(v546) >> v558) | (v559 << (v557 - 32)) | (HIDWORD(v546) << v557) | (v559 >> (32 - v557));
                  v550 = v546 | (v559 << v557);
                  _ZF = v2846 == 1;
                  LODWORD(v546) = v2751;
                  --v2846;
                }
                while ( !_ZF );
                v533 = (_BYTE *)v2847;
              }
              LODWORD(v546) = v550;
              *((_DWORD *)v533 + 214) += v544;
              while ( 1 )
              {
                LODWORD(v546) = FsRtlPrivateResetHighestLockOffset(v546, HIDWORD(v546), 31);
                if ( !v546 )
                  break;
                v550 ^= v546;
              }
              v527 = v2833;
              v2713[3] = v550 & 0x7FFFFFFF;
              v541 = v2713 + 10;
              v2713 += 10;
              *((_DWORD *)v533 + 214) += v544;
              v543 = v2796 + 4;
              v2796 = v543;
            }
            while ( v543 < 0x10 );
            v560 = v2851;
            v561 = v2841;
            v140 = (unsigned int)v2734;
            v562 = v2851 + 20;
            v2843 = (unsigned int *)v533;
            if ( v2841 )
              v563 = 14;
            else
              v563 = 13;
            if ( v2851 == (int *)-80 )
            {
              v564 = *((_DWORD *)v533 + 248);
              v565 = *((_DWORD *)v533 + 199);
              v566 = v533;
              if ( (v564 & 0x20000000) == 0 )
                v566 = 0;
              if ( *((int *)v533 + 232) <= 1 )
              {
                if ( v566 )
                {
                  v567 = *((_DWORD *)v566 + 203);
LABEL_749:
                  v568 = (_DWORD *(__fastcall *)(int, int))&v566[v567 | 1];
                }
                else
                {
                  v568 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                }
              }
              else
              {
                if ( v566 )
                {
                  v567 = *((_DWORD *)v566 + 204);
                  goto LABEL_749;
                }
                v568 = sub_5FD658;
              }
              if ( (v564 & 4) == 0 )
                v568 = (_DWORD *(__fastcall *)(int, int))*((_DWORD *)v533 + 270);
              v569 = v568((int)v533, v565 + 40);
              v2852 = (unsigned int)v569;
              if ( !v569 )
                goto LABEL_1033;
              v570 = *((_DWORD *)v533 + 248);
              if ( (v570 & 4) == 0 )
              {
                v571 = *((_DWORD *)v533 + 199);
                v572 = *((_DWORD *)v533 + 232);
                v573 = *((_DWORD *)v533 + 195);
                if ( (v570 & 0x20000000) == 0 )
                  v572 = 0;
                if ( v571 >= 4 )
                {
                  v574 = v571 >> 2;
                  do
                  {
                    v571 -= 4;
                    --v574;
                    *(_DWORD *)v533 = 0;
                    v533 += 4;
                  }
                  while ( v574 );
                }
                for ( ; v571; --v571 )
                  *v533++ = 0;
                v575 = v569[232];
                v569[232] = v572;
                if ( v572 == 3 )
                {
                  v576 = (void (__fastcall *)(_DWORD))v569[124];
                }
                else
                {
                  v576 = (void (__fastcall *)(_DWORD))v569[55];
                  if ( v572 && v572 == 1 )
                  {
                    ((void (__fastcall *)(int, _DWORD))v569[87])(v573 - 4, *(_DWORD *)(v573 - 4));
                    goto LABEL_768;
                  }
                }
                v576(v573);
LABEL_768:
                v569[232] = v575;
              }
              v577 = (_DWORD *)((char *)v569 + v565);
              v578 = 10;
              v569[248] &= 0xFFFFFFFB;
              v2760 = (_DWORD *)((char *)v569 + v565);
              v579 = (_DWORD *)((char *)v569 + v565);
              ++v569[207];
              v580 = 40;
              do
              {
                v580 -= 4;
                --v578;
                *v579++ = 0;
              }
              while ( v578 );
              for ( ; v580; --v580 )
              {
                *(_BYTE *)v579 = 0;
                v579 = (_DWORD *)((char *)v579 + 1);
              }
              v581 = v2739;
              *v577 = v563;
              v577[1] = (int)v2739;
              v577[2] = v2687;
              LODWORD(v582) = v2739;
              if ( (unsigned int)v582 < v2687 + (unsigned int)v582 )
              {
                do
                {
                  __pld(v581);
                  v581 += 128;
                }
                while ( v581 < &v2739[v2687] );
              }
              v583 = v2687;
              HIDWORD(v582) = v569[211];
              v584 = v569[210];
              v2846 = v2687;
              if ( v2687 >= 8 )
              {
                v585 = v2687 >> 3;
                v586 = v569[209] & 0x3F;
                v587 = 64 - v586;
                do
                {
                  v588 = v584 ^ *(_DWORD *)v582;
                  v589 = HIDWORD(v582) ^ *(_DWORD *)(v582 + 4);
                  v590 = (v588 >> v587) | (v589 << (v586 - 32)) | (v589 >> (32 - v586));
                  HIDWORD(v582) = (v589 >> v587) | (v588 << (v586 - 32)) | (v589 << v586) | (v588 >> (32 - v586));
                  v584 = v590 | (v588 << v586);
                  v583 = v2846 - 8;
                  v2846 -= 8;
                  LODWORD(v582) = v2739 + 8;
                  v2739 += 8;
                  --v585;
                }
                while ( v585 );
                v140 = (unsigned int)v2734;
                v569 = (_DWORD *)v2852;
              }
              if ( v583 )
              {
                v591 = v569[209] & 0x3F;
                v592 = 64 - v591;
                do
                {
                  v593 = v584 ^ *(unsigned __int8 *)v582;
                  v2740 = v582 + 1;
                  LODWORD(v582) = (v593 >> v592) | (HIDWORD(v582) << (v591 - 32)) | (HIDWORD(v582) >> (32 - v591));
                  HIDWORD(v582) = (HIDWORD(v582) >> v592) | (v593 << (v591 - 32)) | (HIDWORD(v582) << v591) | (v593 >> (32 - v591));
                  v584 = v582 | (v593 << v591);
                  _ZF = v2846 == 1;
                  LODWORD(v582) = v2740;
                  --v2846;
                }
                while ( !_ZF );
                v140 = (unsigned int)v2734;
              }
              v533 = (_BYTE *)v2852;
              LODWORD(v582) = v584;
              *(_DWORD *)(v2852 + 856) += v2687;
              while ( 1 )
              {
                LODWORD(v582) = FsRtlPrivateResetHighestLockOffset(v582, HIDWORD(v582), 31);
                if ( !v582 )
                  break;
                v584 ^= v582;
              }
              v562 = v2760;
              v560 = v2851;
              v2760[3] = v584 & 0x7FFFFFFF;
              v561 = v2841;
              *((_DWORD *)v533 + 214) += v2687;
              goto LABEL_789;
            }
            v2852 = (unsigned int)v533;
            *v562 = v563;
LABEL_789:
            v562[4] = 1;
            if ( !v533 )
              goto LABEL_1033;
            v594 = v2872;
            v560[30] = 35;
            v2843 = (unsigned int *)v533;
            v560[36] = v560[36] & 0xFFFFFFFE | (v561 != 0);
            if ( (unsigned int)v560[32] >= 0x5C )
            {
              v595 = v560[31];
              v596 = (*((int (__fastcall **)(int *))v533 + 81))(v594);
              if ( !v596 )
                goto LABEL_1033;
              v597 = (char *)v594 + *(_DWORD *)(v596 + 80);
              v560[36] |= 2u;
              v598 = *(int **)(v595 + 72);
              if ( v598 >= v594 && v598 < (int *)v597 )
              {
                v560[34] = *v598;
                v560[36] |= 4u;
              }
              v599 = *(int **)(v595 + 76);
              if ( v599 >= v594 && v599 < (int *)v597 )
              {
                v560[35] = *v599;
                v560[36] |= 8u;
              }
            }
            v600 = v2872;
            v601 = *((_DWORD *)v533 + 248);
            v2843 = (unsigned int *)v533;
            v2844 = v2872;
            if ( (v601 & 0x400000) == 0 )
            {
LABEL_1032:
              v359 = 1;
              v369 = 0;
              goto LABEL_1036;
            }
            v602 = (*((int (__fastcall **)(_DWORD *))v533 + 81))(v2872);
            v603 = v602;
            if ( !v602 )
              goto LABEL_526;
            v604 = *(unsigned __int16 *)(v602 + 6);
            v2847 = v2861 >> 3;
            if ( !v604 )
            {
              if ( (*((_DWORD *)v533 + 248) & 0x200000) == 0 )
              {
                v1189 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                if ( v1189 )
                {
                  if ( v1189 == 1 )
                  {
                    v2884 = -2147483490;
                    v1190 = __ROR4__(-2147483490, 31);
                  }
                  else
                  {
                    v2884 = 634;
                    v1190 = __ROR4__(634, 1);
                  }
                }
                else
                {
                  v2884 = 154817;
                  v1190 = __ROR4__(162304, 9);
                }
                KeBugCheckEx(v1190, 10, (int)v600, 0, 0);
              }
              if ( *((_DWORD *)v533 + 220) )
                goto LABEL_526;
LABEL_803:
              *((_DWORD *)v533 + 222) = v533 - 1849117464;
              *((_DWORD *)v533 + 223) = 0;
              *((_DWORD *)v533 + 224) = 0;
              *((_DWORD *)v533 + 225) = 0;
              *((_DWORD *)v533 + 226) = 271;
              *((_DWORD *)v533 + 227) = 0;
              *((_DWORD *)v533 + 228) = v600;
              *((_DWORD *)v533 + 229) = 0;
              *((_DWORD *)v533 + 220) = 1;
              goto LABEL_526;
            }
            v605 = 0;
            v606 = (int)v2850;
            v607 = &v2850[2 * (v2861 >> 3)];
            v608 = *(unsigned __int16 *)(v602 + 20);
            v2854 = v607;
            v2714 = v608 + v602 + 24;
            v609 = (_DWORD *)v2714;
LABEL_805:
            v610 = v609[4];
            v611 = v609[3];
            if ( v610 <= v609[2] )
              v610 = v609[2];
            v612 = v611 + v610;
            if ( v605 && v612 < *(v609 - 7) )
            {
              v613 = (_DWORD *)v2852;
              if ( (*(_DWORD *)(v2852 + 992) & 0x200000) == 0 )
              {
                v1191 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                if ( v1191 )
                {
                  if ( v1191 == 1 )
                  {
                    v2891 = -2147483490;
                    v1192 = __ROR4__(-2147483490, 31);
                  }
                  else
                  {
                    v2891 = 634;
                    v1192 = __ROR4__(634, 1);
                  }
                }
                else
                {
                  v2891 = 154817;
                  v1192 = __ROR4__(162304, 9);
                }
                KeBugCheckEx(v1192, 10, (int)v2844, 1, 0);
              }
              if ( !*(_DWORD *)(v2852 + 880) )
              {
                v614 = v2844;
                *(_DWORD *)(v2852 + 888) = v2852 - 1849117464;
                v613[223] = 0;
                v613[224] = 0;
                v613[225] = 0;
                v613[226] = 271;
                v613[227] = 0;
                v613[228] = v614;
LABEL_812:
                v613[229] = 0;
                v613[220] = 1;
              }
              goto LABEL_526;
            }
            while ( 1 )
            {
              if ( (_DWORD *)v606 == v607 )
                goto LABEL_824;
              v615 = *(_QWORD *)v606;
              v616 = v2844;
              v617 = *(_DWORD *)v606 & 0xFFFFFFFE;
              if ( (*(_DWORD *)(v606 + 4) & 3) != 0 )
                HIDWORD(v615) = (HIDWORD(v615) >> 2) & 0x7FF;
              else
                HIDWORD(v615) = *(_DWORD *)((char *)v2844 + HIDWORD(v615)) & 0x3FFFF;
              v618 = (v615 + 2 * HIDWORD(v615)) & 0xFFFFFFFE;
              if ( v617 >= v612 || v618 <= v611 )
              {
                v607 = v2854;
LABEL_824:
                ++v605;
                v609 += 10;
                if ( v605 < v604 )
                  goto LABEL_805;
                v533 = (_BYTE *)v2852;
                v600 = v2844;
                if ( (_DWORD *)v606 != v607 )
                {
                  if ( (*(_DWORD *)(v2852 + 992) & 0x200000) == 0 )
                  {
                    v1195 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                    if ( v1195 )
                    {
                      if ( v1195 == 1 )
                      {
                        v2888 = -2147483490;
                        v1196 = __ROR4__(-2147483490, 31);
                      }
                      else
                      {
                        v2888 = 634;
                        v1196 = __ROR4__(634, 1);
                      }
                    }
                    else
                    {
                      v2888 = 154817;
                      v1196 = __ROR4__(162304, 9);
                    }
                    KeBugCheckEx(v1196, 10, (int)v600, 3, 0);
                  }
                  if ( *(_DWORD *)(v2852 + 880) )
                    goto LABEL_526;
                  goto LABEL_803;
                }
                v619 = (_DWORD *)v2852;
                v620 = v2847 + 6;
                v621 = *(_DWORD *)(v2852 + 796);
                v622 = *(_DWORD *)(v2852 + 992);
                v623 = v2852;
                if ( (v622 & 0x20000000) == 0 )
                  v623 = 0;
                if ( *(int *)(v2852 + 928) <= 1 )
                {
                  if ( v623 )
                  {
                    v624 = *(_DWORD *)(v623 + 812);
LABEL_840:
                    v625 = (_DWORD *(__fastcall *)(int, int))((v624 | 1) + v623);
                  }
                  else
                  {
                    v625 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                  }
                }
                else
                {
                  if ( v623 )
                  {
                    v624 = *(_DWORD *)(v623 + 816);
                    goto LABEL_840;
                  }
                  v625 = sub_5FD658;
                }
                if ( (v622 & 4) == 0 )
                  v625 = *(_DWORD *(__fastcall **)(int, int))(v2852 + 1080);
                v626 = v625(v2852, v621 + ((v2847 + 6) & 0xFFFFFFF8) + 24 * v604 + 40);
                v2741 = v626;
                if ( !v626 )
                  goto LABEL_1033;
                v627 = v619[248];
                if ( (v627 & 4) == 0 )
                {
                  v628 = v619[199];
                  v629 = v619[232];
                  v630 = v619[195];
                  if ( (v627 & 0x20000000) == 0 )
                    v629 = 0;
                  if ( v628 >= 4 )
                  {
                    v631 = v628 >> 2;
                    do
                    {
                      v628 -= 4;
                      --v631;
                      *v619++ = 0;
                    }
                    while ( v631 );
                  }
                  for ( ; v628; --v628 )
                  {
                    *(_BYTE *)v619 = 0;
                    v619 = (_DWORD *)((char *)v619 + 1);
                  }
                  v632 = v626[232];
                  v626[232] = v629;
                  if ( v629 == 3 )
                  {
                    v633 = (void (__fastcall *)(_DWORD))v626[124];
                  }
                  else
                  {
                    v633 = (void (__fastcall *)(_DWORD))v626[55];
                    if ( v629 && v629 == 1 )
                    {
                      ((void (__fastcall *)(int, _DWORD))v626[87])(v630 - 4, *(_DWORD *)(v630 - 4));
                      goto LABEL_859;
                    }
                  }
                  v633(v630);
LABEL_859:
                  v626[232] = v632;
                }
                v634 = (char *)v626 + v621;
                v635 = 10;
                v626[248] &= 0xFFFFFFFB;
                v636 = (_DWORD *)((char *)v626 + v621);
                ++v626[207];
                v637 = 40;
                do
                {
                  v637 -= 4;
                  --v635;
                  *v636++ = 0;
                }
                while ( v635 );
                for ( ; v637; --v637 )
                {
                  *(_BYTE *)v636 = 0;
                  v636 = (_DWORD *)((char *)v636 + 1);
                }
                *(_DWORD *)v634 = 30;
                *((_DWORD *)v634 + 1) = v2850;
                *((_DWORD *)v634 + 2) = 0;
                HIDWORD(v639) = v626[211];
                v638 = v626[210];
                LODWORD(v639) = v638;
                while ( 1 )
                {
                  LODWORD(v639) = FsRtlPrivateResetHighestLockOffset(v639, HIDWORD(v639), 31);
                  if ( !v639 )
                    break;
                  v638 ^= v639;
                }
                v640 = v638 & 0x7FFFFFFF;
                v641 = v2844;
                *((_DWORD *)v634 + 3) = v640;
                *((_DWORD *)v634 + 4) = v641;
                *((_DWORD *)v634 + 5) = *(_DWORD *)(v603 + 80);
                v2852 = (unsigned int)v626;
                *((_DWORD *)v634 + 6) = v2861;
                v642 = v2841;
                *((_WORD *)v634 + 14) = v604;
                v643 = v634 + 40;
                v2752 = v634 + 40;
                *((_WORD *)v634 + 15) ^= ((unsigned __int8)*((_WORD *)v634 + 15) ^ (v642 != 0)) & 1;
                v644 = (unsigned int *)&v634[(v620 & 0xFFFFFFF8) + 40];
                v645 = *((unsigned __int16 *)v634 + 14);
                v2843 = v644;
                v646 = (unsigned int)&v644[6 * v645];
                v2859 = v646;
                if ( v2847 )
                  v647 = v2850 + 2;
                else
                  v647 = v2854;
                v2834 = v647;
                v648 = &v634[(v620 & 0xFFFFFFF8) + 40];
                do
                {
                  v649 = 2;
                  do
                  {
                    *(_DWORD *)v648 = 0;
                    *((_DWORD *)v648 + 1) = 0;
                    *((_DWORD *)v648 + 2) = 0x80000000;
                    v648 += 12;
                    --v649;
                  }
                  while ( v649 );
                  --v604;
                }
                while ( v604 );
                if ( v644 != (unsigned int *)v646 )
                {
                  v650 = v626;
                  v651 = (int *)v2714;
                  do
                  {
                    v652 = v651[9];
                    v653 = 0;
                    v2861 = 0;
                    if ( (v652 & v2871) != 0
                      || *v651 == 1414090313 && v651[1] == 1195525195
                      || *v651 == 1162297680
                      && ((v654 = *((unsigned __int16 *)v651 + 2), v654 == 30839) || v654 == 29303 || v654 == 30583) )
                    {
                      v653 = 1;
                      v2861 = 1;
                    }
                    else
                    {
                      v656 = (int *)v650[235];
                      v655 = (int *)v650[234];
                      v657 = *((_QWORD *)v650 + 118);
                      v658 = 7;
                      v659 = v651;
                      while ( 1 )
                      {
                        v661 = *v659++;
                        v660 = v661;
                        v662 = *v655++;
                        if ( v660 != v662 )
                          break;
                        v658 -= 4;
                        if ( v658 < 4 )
                        {
                          if ( !v658 )
                          {
LABEL_910:
                            v653 = 1;
                            v2861 = 1;
                            goto LABEL_911;
                          }
                          while ( 1 )
                          {
                            v664 = *(unsigned __int8 *)v659;
                            v659 = (int *)((char *)v659 + 1);
                            v663 = v664;
                            v665 = *(unsigned __int8 *)v655;
                            v655 = (int *)((char *)v655 + 1);
                            if ( v663 != v665 )
                              goto LABEL_890;
                            if ( !--v658 )
                              goto LABEL_910;
                          }
                        }
                      }
LABEL_890:
                      v666 = 8;
                      v667 = v651;
                      while ( 1 )
                      {
                        v669 = *v667++;
                        v668 = v669;
                        v670 = *v656++;
                        if ( v668 != v670 )
                          break;
                        v666 -= 4;
                        if ( v666 < 4 )
                        {
                          if ( !v666 )
                            goto LABEL_910;
                          while ( 1 )
                          {
                            v672 = *(unsigned __int8 *)v667;
                            v667 = (int *)((char *)v667 + 1);
                            v671 = v672;
                            v673 = *(unsigned __int8 *)v656;
                            v656 = (int *)((char *)v656 + 1);
                            if ( v671 != v673 )
                              goto LABEL_897;
                            if ( !--v666 )
                              goto LABEL_910;
                          }
                        }
                      }
LABEL_897:
                      v674 = 4;
                      v675 = v651;
                      while ( 1 )
                      {
                        v677 = *v675++;
                        v676 = v677;
                        v678 = *(_DWORD *)v657;
                        LODWORD(v657) = v657 + 4;
                        if ( v676 != v678 )
                          break;
                        v674 -= 4;
                        if ( v674 < 4 )
                        {
                          if ( !v674 )
                            goto LABEL_910;
                          while ( 1 )
                          {
                            v680 = *(unsigned __int8 *)v675;
                            v675 = (int *)((char *)v675 + 1);
                            v679 = v680;
                            v681 = *(unsigned __int8 *)v657;
                            LODWORD(v657) = v657 + 1;
                            if ( v679 != v681 )
                              goto LABEL_904;
                            if ( !--v674 )
                              goto LABEL_910;
                          }
                        }
                      }
LABEL_904:
                      v682 = 6;
                      v683 = v651;
                      while ( 1 )
                      {
                        v685 = *v683++;
                        v684 = v685;
                        v686 = *(_DWORD *)HIDWORD(v657);
                        HIDWORD(v657) += 4;
                        if ( v684 != v686 )
                          break;
                        v682 -= 4;
                        if ( v682 < 4 )
                        {
                          if ( !v682 )
                            goto LABEL_910;
                          while ( 1 )
                          {
                            v688 = *(unsigned __int8 *)v683;
                            v683 = (int *)((char *)v683 + 1);
                            v687 = v688;
                            v689 = (unsigned __int8)*(_BYTE *)HIDWORD(v657);
                            ++HIDWORD(v657);
                            if ( v687 != v689 )
                              goto LABEL_911;
                            if ( !--v682 )
                              goto LABEL_910;
                          }
                        }
                      }
LABEL_911:
                      v644 = v2843;
                    }
                    if ( v651[9] < 0 )
                    {
                      v653 = 1;
                      v2861 = 1;
                    }
                    if ( v653 && *v651 == 1414090313 && v651[1] == 1195525195 && (v650[248] & v2873) != 0 )
                    {
                      v653 = 0;
                      v2861 = 0;
                    }
                    v690 = v651[4];
                    v691 = v651[3];
                    v692 = v651[2];
                    v693 = v2850;
                    v2845 = v691;
                    if ( v690 <= v692 )
                      v690 = v692;
                    v694 = v2854;
                    v695 = (int *)(v691 + v690);
                    v2851 = (int *)(v691 + v690);
                    if ( v2850 == v2854 )
                    {
                      v697 = 0;
                      v2847 = 0;
                      v699 = 0;
                    }
                    else
                    {
                      v696 = *(_QWORD *)v2850;
                      v697 = *v2850 & 0xFFFFFFFE;
                      v2847 = v697;
                      if ( (v696 & 0x300000000i64) != 0 )
                      {
                        HIDWORD(v696) = (HIDWORD(v696) >> 2) & 0x7FF;
                      }
                      else
                      {
                        v693 = v2850;
                        HIDWORD(v696) = *(_DWORD *)((char *)v2844 + HIDWORD(v696)) & 0x3FFFF;
                      }
                      v698 = v696 + 2 * HIDWORD(v696);
                      v694 = v2854;
                      v699 = v698 & 0xFFFFFFFE;
                    }
                    v700 = (int *)v691;
                    v2688 = v691;
                    v2797 = v699;
                    if ( v693 == v694 || v697 <= v691 || v699 > (unsigned int)v695 )
                    {
                      v701 = v2844;
                    }
                    else
                    {
                      v701 = v2844;
                      if ( !v653 )
                      {
                        *v644 = v691;
                        v644[1] = v697;
                        v702 = *v644;
                        v700 = (int *)v697;
                        v2688 = v697;
                        v703 = (char *)v701 + *v644;
                        v704 = v697 - *v644;
                        v2846 = (unsigned int)v703;
                        v2761 = v697 - v702;
                        v705 = (char *)v701 + v697;
                        v706 = 0;
                        while ( 1 )
                        {
                          v707 = v2948[v706];
                          if ( (unsigned int)v703 < v2944[v706] + v707 && (unsigned int)v705 > v707 )
                            break;
                          if ( (unsigned int)++v706 >= 4 )
                          {
                            for ( l = v703; l < v705; l += 128 )
                              __pld(l);
                            v709 = v704;
                            HIDWORD(v710) = v650[211];
                            v711 = v650[210];
                            v2841 = v704;
                            if ( v704 >= 8 )
                            {
                              v712 = v704 >> 3;
                              v713 = v650[209] & 0x3F;
                              v714 = 64 - v713;
                              do
                              {
                                v715 = v711 ^ *(_DWORD *)v703;
                                v716 = HIDWORD(v710) ^ *((_DWORD *)v703 + 1);
                                LODWORD(v710) = (v715 >> v714) | (v716 << (v713 - 32)) | (v716 >> (32 - v713));
                                HIDWORD(v710) = (v716 >> v714) | (v715 << (v713 - 32)) | (v716 << v713) | (v715 >> (32 - v713));
                                v703 = (char *)(v2846 + 8);
                                v709 = v2841 - 8;
                                v2846 += 8;
                                v2841 -= 8;
                                v711 = v710 | (v715 << v713);
                                --v712;
                              }
                              while ( v712 );
                              v650 = v2741;
                            }
                            if ( v709 )
                            {
                              v717 = v650[209] & 0x3F;
                              v718 = 64 - v717;
                              do
                              {
                                v719 = v711 ^ (unsigned __int8)*v703;
                                LODWORD(v710) = (v719 >> v718) | (HIDWORD(v710) << (v717 - 32)) | (HIDWORD(v710) >> (32 - v717));
                                v2846 = (unsigned int)(v703 + 1);
                                HIDWORD(v710) = (HIDWORD(v710) >> v718) | (v719 << (v717 - 32)) | (HIDWORD(v710) << v717) | (v719 >> (32 - v717));
                                ++v703;
                                _ZF = v2841-- == 1;
                                v711 = v710 | (v719 << v717);
                              }
                              while ( !_ZF );
                              v650 = v2741;
                            }
                            LODWORD(v710) = v711;
                            v650[214] += v2761;
                            while ( 1 )
                            {
                              LODWORD(v710) = FsRtlPrivateResetHighestLockOffset(v710, HIDWORD(v710), 31);
                              if ( !v710 )
                                break;
                              v711 ^= v710;
                            }
                            v644 = v2843;
                            v701 = v2844;
                            v720 = v711 & 0x7FFFFFFF;
                            v700 = (int *)v2688;
                            v691 = v2845;
                            v643 = v2752;
                            v2843[2] = v720;
                            break;
                          }
                        }
                        v693 = v2850;
                        v695 = v2851;
                        v694 = v2854;
                      }
                    }
                    if ( v2847 >= v691 && v2797 <= (unsigned int)v695 && v693 != v694 )
                    {
                      v721 = v2834;
                      v722 = v2834[1];
                      if ( (v722 & 3) != 0 )
                        v723 = (v722 >> 2) & 0x7FF;
                      else
                        v723 = *(_DWORD *)((char *)v701 + v722) & 0x3FFFF;
                      v724 = (*v2834 + 2 * v723) & 0xFFFFFFFE;
                      v2798 = v724;
                      if ( v724 <= (unsigned int)v695 )
                      {
                        v725 = v2854;
                        while ( v721 != v725 )
                        {
                          if ( v2861 )
                          {
                            *v643 = 0x80;
                          }
                          else
                          {
                            v726 = v693[1];
                            v727 = (v726 & 3) != 0 ? (v726 >> 2) & 0x7FF : *(_DWORD *)((char *)v701 + v726) & 0x3FFFF;
                            v728 = (*v693 + 2 * v727) & 0xFFFFFFFE;
                            v729 = *v721;
                            v730 = (char *)v701 + v728;
                            v2846 = (unsigned int)v701 + v728;
                            v731 = (v729 & 0xFFFFFFFE) - v728;
                            v732 = (char *)v701 + (v729 & 0xFFFFFFFE);
                            v733 = 0;
                            v2688 = v729 & 0xFFFFFFFE;
                            v2762 = v731;
                            do
                            {
                              v734 = v2948[v733];
                              if ( (unsigned int)v730 < v2944[v733] + v734 && (unsigned int)v732 > v734 )
                                goto LABEL_988;
                              ++v733;
                            }
                            while ( v733 < 4 );
                            if ( v731 < 4 )
                            {
LABEL_988:
                              v748 = 0x80;
                              goto LABEL_989;
                            }
                            for ( m = v730; m < v732; m += 128 )
                              __pld(m);
                            v736 = v731;
                            v737 = *((_QWORD *)v650 + 105);
                            v2841 = v731;
                            if ( v731 >= 8 )
                            {
                              v738 = v731 >> 3;
                              v739 = v650[209] & 0x3F;
                              v740 = 64 - v739;
                              do
                              {
                                v741 = *(_DWORD *)v730 ^ v737;
                                v742 = HIDWORD(v737) ^ *((_DWORD *)v730 + 1);
                                v743 = (v741 >> v740) | (v742 << (v739 - 32)) | (v742 >> (32 - v739));
                                HIDWORD(v737) = (v742 >> v740) | (v741 << (v739 - 32)) | (v742 << v739) | (v741 >> (32 - v739));
                                v730 = (char *)(v2846 + 8);
                                v736 = v2841 - 8;
                                LODWORD(v737) = v743 | (v741 << v739);
                                v2846 += 8;
                                v2841 -= 8;
                                --v738;
                              }
                              while ( v738 );
                              v650 = v2741;
                            }
                            if ( v736 )
                            {
                              v744 = v650[209] & 0x3F;
                              v745 = 64 - v744;
                              do
                              {
                                v746 = (unsigned __int8)*v730 ^ (unsigned int)v737;
                                LODWORD(v737) = (v746 >> v745) | (HIDWORD(v737) << (v744 - 32)) | (HIDWORD(v737) >> (32 - v744));
                                v2846 = (unsigned int)(v730 + 1);
                                HIDWORD(v737) = (HIDWORD(v737) >> v745) | (v746 << (v744 - 32)) | (HIDWORD(v737) << v744) | (v746 >> (32 - v744));
                                LODWORD(v737) = v737 | (v746 << v744);
                                _ZF = v2841 == 1;
                                ++v730;
                                --v2841;
                              }
                              while ( !_ZF );
                              v650 = v2741;
                            }
                            v747 = v737;
                            v650[214] += v2762;
                            while ( 1 )
                            {
                              LODWORD(v737) = FsRtlPrivateResetHighestLockOffset(v737, HIDWORD(v737), 7);
                              if ( !v737 )
                                break;
                              v747 ^= v737;
                            }
                            v643 = v2752;
                            v721 = v2834;
                            v748 = v747 & 0x7F;
LABEL_989:
                            v693 = v2850;
                            v695 = v2851;
                            *v643 = v748;
                            v724 = v2798;
                          }
                          v725 = v2854;
                          v693 += 2;
                          ++v643;
                          v721 += 2;
                          v2850 = v693;
                          v2752 = v643;
                          v2834 = v721;
                          if ( v721 != v2854 )
                          {
                            v749 = v721[1];
                            if ( (v749 & 3) != 0 )
                            {
                              v750 = (v749 >> 2) & 0x7FF;
                            }
                            else
                            {
                              v693 = v2850;
                              v750 = *(_DWORD *)((char *)v2844 + v749) & 0x3FFFF;
                            }
                            v724 = (*v721 + 2 * v750) & 0xFFFFFFFE;
                            v725 = v2854;
                            v2798 = v724;
                          }
                          if ( v724 > (unsigned int)v695 )
                            break;
                          v701 = v2844;
                        }
                        v700 = (int *)v2688;
                      }
                      v644 = v2843;
                    }
                    if ( v2861 )
                    {
LABEL_1019:
                      v751 = v2844;
                    }
                    else
                    {
                      v751 = v2844;
                      if ( v700 != v695 )
                      {
                        v644[3] = (unsigned int)v700;
                        v644[4] = (unsigned int)v695;
                        v752 = v644[3];
                        v753 = (char *)v751 + v752;
                        v754 = (unsigned int)v695 - v752;
                        v2799 = (char *)v751 + v752;
                        v2763 = (char *)v695 - v752;
                        v755 = (char *)v751 + (_DWORD)v695;
                        v756 = 0;
                        while ( 1 )
                        {
                          v757 = v2948[v756];
                          if ( (unsigned int)v753 < v2944[v756] + v757 && (unsigned int)v755 > v757 )
                            break;
                          if ( (unsigned int)++v756 >= 4 )
                          {
                            v758 = (char *)v751 + v752;
                            if ( v753 < v755 )
                            {
                              do
                              {
                                __pld(v758);
                                v758 += 128;
                              }
                              while ( v758 < v755 );
                            }
                            v759 = v754;
                            HIDWORD(v760) = v650[211];
                            v761 = v650[210];
                            v2689 = v754;
                            if ( v754 >= 8 )
                            {
                              v762 = v754 >> 3;
                              v763 = v650[209] & 0x3F;
                              v764 = 64 - v763;
                              do
                              {
                                v765 = v761 ^ *(_DWORD *)v753;
                                v766 = HIDWORD(v760) ^ *((_DWORD *)v753 + 1);
                                LODWORD(v760) = (v765 >> v764) | (v766 << (v763 - 32)) | (v766 >> (32 - v763));
                                HIDWORD(v760) = (v766 >> v764) | (v765 << (v763 - 32)) | (v766 << v763) | (v765 >> (32 - v763));
                                v753 = v2799 + 8;
                                v759 = v2689 - 8;
                                v2799 += 8;
                                v2689 -= 8;
                                v761 = v760 | (v765 << v763);
                                --v762;
                              }
                              while ( v762 );
                              v650 = v2741;
                            }
                            if ( v759 )
                            {
                              v767 = v650[209] & 0x3F;
                              v768 = 64 - v767;
                              do
                              {
                                v769 = v761 ^ (unsigned __int8)*v753;
                                LODWORD(v760) = (v769 >> v768) | (HIDWORD(v760) << (v767 - 32)) | (HIDWORD(v760) >> (32 - v767));
                                HIDWORD(v760) = (HIDWORD(v760) >> v768) | (v769 << (v767 - 32)) | (HIDWORD(v760) << v767) | (v769 >> (32 - v767));
                                ++v753;
                                _ZF = v2689-- == 1;
                                v761 = v760 | (v769 << v767);
                              }
                              while ( !_ZF );
                              v650 = v2741;
                            }
                            LODWORD(v760) = v761;
                            v650[214] += v2763;
                            while ( 1 )
                            {
                              LODWORD(v760) = FsRtlPrivateResetHighestLockOffset(v760, HIDWORD(v760), 31);
                              if ( !v760 )
                                break;
                              v761 ^= v760;
                            }
                            v644 = v2843;
                            v2843[5] = v761 & 0x7FFFFFFF;
                            goto LABEL_1019;
                          }
                        }
                      }
                    }
                    v770 = v2850;
                    if ( v2850 != v2854 )
                    {
                      v771 = *(_QWORD *)v2850;
                      HIDWORD(v771) = (v2850[1] & 3) != 0 ? (HIDWORD(v771) >> 2) & 0x7FF : *(_DWORD *)((char *)v751 + HIDWORD(v771)) & 0x3FFFF;
                      v772 = (v771 + 2 * HIDWORD(v771)) & 0xFFFFFFFE;
                      if ( (*v2850 & 0xFFFFFFFE) >= v2845 && v772 <= (unsigned int)v2851 )
                      {
                        if ( v2834 != v2854 )
                        {
                          *v2752 = 0x80;
                          v2834 += 2;
                          ++v2752;
                        }
                        v2850 = v770 + 2;
                      }
                    }
                    v644 += 6;
                    v651 = (int *)(v2714 + 40);
                    v643 = v2752;
                    v2714 += 40;
                    v2843 = v644;
                  }
                  while ( v644 != (unsigned int *)v2859 );
                  v140 = (unsigned int)v2734;
                }
                v533 = (_BYTE *)v2852;
                goto LABEL_1032;
              }
              if ( v617 < v611 || v618 > v612 )
                break;
              v607 = v2854;
              v606 += 8;
            }
            v613 = (_DWORD *)v2852;
            if ( (*(_DWORD *)(v2852 + 992) & 0x200000) == 0 )
            {
              v1193 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
              if ( v1193 )
              {
                if ( v1193 == 1 )
                {
                  v2886 = -2147483490;
                  v1194 = __ROR4__(-2147483490, 31);
                }
                else
                {
                  v2886 = 634;
                  v1194 = __ROR4__(634, 1);
                }
              }
              else
              {
                v2886 = 154817;
                v1194 = __ROR4__(162304, 9);
              }
              KeBugCheckEx(v1194, 10, (int)v2844, 2, 0);
            }
            if ( !*(_DWORD *)(v2852 + 880) )
            {
              *(_DWORD *)(v2852 + 888) = v2852 - 1849117464;
              v613[223] = 0;
              v613[224] = 0;
              v613[225] = 0;
              v613[226] = 271;
              v613[227] = 0;
              v613[228] = v616;
              goto LABEL_812;
            }
LABEL_526:
            v369 = -1073741701;
LABEL_1034:
            v359 = 1;
LABEL_1035:
            v533 = v2843;
LABEL_1036:
            v365 = jj;
            v364 = (int *)&v533[(_DWORD)v2822 - v140];
            v2822 = v364;
            v140 = (unsigned int)v533;
            v2734 = v533;
LABEL_1038:
            if ( v369 >= 0 || v369 == -1073741554 )
              v364[6] = v365;
LABEL_1066:
            *(_DWORD *)(v140 + 856) += v359 << 15;
            ++*(_DWORD *)(v140 + 852);
            if ( *(_DWORD *)(v140 + 856) < *(_DWORD *)(v140 + 860) )
            {
              v157 = v2822;
              continue;
            }
            break;
          }
LABEL_1564:
          v149 = v2839;
          v150 = v2840;
          v151 = v2838;
LABEL_1565:
          if ( !*(_DWORD *)(v140 + 852) )
            goto LABEL_277;
          v147 = v2857 - 1;
LABEL_278:
          v250 = *(_DWORD *)(v140 + 880);
          v2857 = ++v147;
          if ( v250 || *(_DWORD *)(v140 + 856) >= *(_DWORD *)(v140 + 860) )
            goto LABEL_1583;
          continue;
        case 25:
          v785 = *(_QWORD *)(v140 + 640);
          v2800 = 0;
          v786 = *(int (**)(void))(v140 + 504);
          v2841 = v785 + 16;
          v2847 = HIDWORD(v785);
          v2753 = v786();
          (*(void (__fastcall **)(unsigned int))(v140 + 272))(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
          (*(void (__fastcall **)(_DWORD, int))(v140 + 212))(*(_DWORD *)(v140 + 648), 1);
          v787 = *(_DWORD *)v785;
          v2846 = v785 + 16 + 16 * *(_DWORD *)v785;
          v2690 = v787;
          v2715 = 0;
          if ( *(_BYTE *)(v785 + 12) )
          {
            v788 = (_DWORD *)*(_DWORD *)HIDWORD(v785);
            v787 = 0;
            v2690 = 0;
            if ( *(_DWORD *)HIDWORD(v785) != HIDWORD(v785) )
            {
              do
              {
                v788 = (_DWORD *)*v788;
                ++v787;
              }
              while ( v788 != (_DWORD *)HIDWORD(v785) );
              v2690 = v787;
            }
          }
          v789 = __mrc(15, 0, 9, 13, 0);
          v790 = v789 << 29;
          v791 = v789 ^ (v789 >> 3);
          v792 = 67117057i64 * (unsigned int)v791;
          v793 = 1880096896i64 * (unsigned int)v791 + 67117057i64 * v790;
          v794 = (1880096896i64 * v790 + (unsigned __int64)HIDWORD(v793)) >> 32;
          v795 = 1880096896 * v790 + HIDWORD(v793);
          if ( (unsigned int)(v793 + HIDWORD(v792)) < HIDWORD(v792) )
            v794 = (__PAIR64__(v794, v795++) + 1) >> 32;
          LODWORD(v796) = v792 ^ v795;
          HIDWORD(v796) = (v793 + HIDWORD(v792)) ^ v794;
          v797 = FsRtlRemovePerStreamContextEx(2048i64, v796);
          v798 = v797;
          v2859 = v797;
          v799 = __mrc(15, 0, 9, 13, 0);
          v800 = v799 << 29;
          v801 = v799 ^ (v799 >> 3);
          v802 = 67117057i64 * (unsigned int)v801;
          v803 = 1880096896i64 * (unsigned int)v801 + 67117057i64 * v800;
          v804 = (1880096896i64 * v800 + (unsigned __int64)HIDWORD(v803)) >> 32;
          v805 = 1880096896 * v800 + HIDWORD(v803);
          if ( (unsigned int)(v803 + HIDWORD(v802)) < HIDWORD(v802) )
            v804 = (__PAIR64__(v804, v805++) + 1) >> 32;
          LODWORD(v806) = v802 ^ v805;
          HIDWORD(v806) = (v803 + HIDWORD(v802)) ^ v804;
          v807 = FsRtlRemovePerStreamContextEx(v797 + 1, v806);
          v808 = v807;
          v2764 = v807;
          v809 = (*(int (__fastcall **)(int, unsigned int, _DWORD))(v140 + 216))(
                   512,
                   v798 + 4 * v787,
                   *(_DWORD *)(v140 + 832));
          v2845 = v809;
          if ( v809 )
          {
            v810 = v808;
            v811 = (_DWORD *)v809;
            if ( v808 >= 8 )
            {
              v812 = v808 >> 3;
              do
              {
                v813 = __mrc(15, 0, 9, 13, 0);
                v814 = v813 << 29;
                v815 = v813 ^ (v813 >> 3);
                v816 = 67117057i64 * (unsigned int)v815;
                v817 = 67117057 * v814 + 1880096896 * v815;
                v818 = (1880096896i64 * v814
                      + ((67117057i64 * v814 + 1880096896 * (unsigned __int64)(unsigned int)v815) >> 32)) >> 32;
                v819 = 1880096896 * v814
                     + ((67117057i64 * v814 + 1880096896 * (unsigned __int64)(unsigned int)v815) >> 32);
                if ( (unsigned int)(v817 + HIDWORD(v816)) < HIDWORD(v816) )
                  v818 = (__PAIR64__(v818, v819++) + 1) >> 32;
                *v811 = v819 ^ v816;
                v811[1] = v818 ^ (v817 + HIDWORD(v816));
                v811 += 2;
                v810 -= 8;
                --v812;
              }
              while ( v812 );
              v140 = (unsigned int)v2734;
            }
            if ( v810 )
            {
              v820 = __mrc(15, 0, 9, 13, 0);
              v821 = v820 << 29;
              v822 = v820 ^ (v820 >> 3);
              v823 = 67117057i64 * (unsigned int)v822;
              v824 = 67117057 * v821 + 1880096896 * v822;
              v825 = (1880096896i64 * v821
                    + ((67117057i64 * v821 + 1880096896 * (unsigned __int64)(unsigned int)v822) >> 32)) >> 32;
              v826 = 1880096896 * v821
                   + ((67117057i64 * v821 + 1880096896 * (unsigned __int64)(unsigned int)v822) >> 32);
              if ( (unsigned int)(v824 + HIDWORD(v823)) < HIDWORD(v823) )
                v825 = (__PAIR64__(v825, v826++) + 1) >> 32;
              v827 = v823 ^ v826;
              v828 = (v824 + HIDWORD(v823)) ^ v825;
              do
              {
                *(_BYTE *)v811 = v827;
                v811 = (_DWORD *)((char *)v811 + 1);
                v827 = FsRtlPrivateResetHighestLockOffset(v827, v828, 8);
                --v810;
              }
              while ( v810 );
            }
            v829 = v2859 - v2764;
            v830 = v2845 + v2764;
            jj = v2845 + v2764;
            v831 = (_DWORD *)(v2845 + v2764 + 4 * v2690);
            if ( v2859 - (unsigned int)v2764 >= 8 )
            {
              v832 = v829 >> 3;
              do
              {
                v833 = __mrc(15, 0, 9, 13, 0);
                v834 = v833 << 29;
                v835 = v833 ^ (v833 >> 3);
                v836 = 67117057i64 * (unsigned int)v835;
                v837 = 1880096896 * v835 + 67117057 * v834;
                v838 = (1880096896i64 * v834
                      + ((1880096896i64 * (unsigned int)v835 + 67117057 * (unsigned __int64)v834) >> 32)) >> 32;
                v839 = 1880096896 * v834
                     + ((1880096896i64 * (unsigned int)v835 + 67117057 * (unsigned __int64)v834) >> 32);
                if ( (unsigned int)(v837 + HIDWORD(v836)) < HIDWORD(v836) )
                  v838 = (__PAIR64__(v838, v839++) + 1) >> 32;
                *v831 = v839 ^ v836;
                v831[1] = v838 ^ (v837 + HIDWORD(v836));
                v829 -= 8;
                v831 += 2;
                --v832;
              }
              while ( v832 );
              v140 = (unsigned int)v2734;
              v830 = jj;
            }
            if ( v829 )
            {
              v840 = __mrc(15, 0, 9, 13, 0);
              v841 = v840 << 29;
              v842 = v840 ^ (v840 >> 3);
              v843 = 67117057i64 * (unsigned int)v842;
              v844 = 1880096896 * v842 + 67117057 * v841;
              v845 = (1880096896i64 * v841
                    + ((1880096896i64 * (unsigned int)v842 + 67117057 * (unsigned __int64)v841) >> 32)) >> 32;
              v846 = 1880096896 * v841
                   + ((1880096896i64 * (unsigned int)v842 + 67117057 * (unsigned __int64)v841) >> 32);
              if ( (unsigned int)(v844 + HIDWORD(v843)) < HIDWORD(v843) )
                v845 = (__PAIR64__(v845, v846++) + 1) >> 32;
              v847 = v843 ^ v846;
              v848 = (v844 + HIDWORD(v843)) ^ v845;
              do
              {
                *(_BYTE *)v831 = v847;
                v831 = (_DWORD *)((char *)v831 + 1);
                v847 = FsRtlPrivateResetHighestLockOffset(v847, v848, 8);
                --v829;
              }
              while ( v829 );
            }
            if ( v830 )
            {
              v850 = v2847;
              v851 = *(_DWORD **)v2847;
              if ( *(_DWORD *)v2847 != v2847 )
              {
                v852 = (_DWORD *)v830;
                do
                {
                  v853 = v851[6];
                  if ( !(*(int (__fastcall **)(int))(v140 + 408))(v853) && v2715 < v2690 )
                  {
                    *v852 = v853;
                    ++v2715;
                    ++v852;
                  }
                  v851 = (_DWORD *)*v851;
                  ++v2800;
                }
                while ( v851 != (_DWORD *)v850 );
                v830 = jj;
              }
              (*(void (__fastcall **)(int, unsigned int))(v140 + 520))(v830, v2715);
              v854 = v2841;
              do
              {
                v855 = *(_DWORD *)(v854 + 4);
                if ( !(*(int (__fastcall **)(unsigned int))(v140 + 408))(v855)
                  && !__103(v830, v2715, v855)
                  && !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = v855;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
                v854 += 16;
              }
              while ( v854 < v2846 );
              v849 = v2845;
LABEL_1117:
              v856 = (*(int (__fastcall **)(_DWORD))(v140 + 232))(*(_DWORD *)(v140 + 648));
              (*(void (__fastcall **)(int))(v140 + 276))(v856);
              (*(void (__fastcall **)(int))(v140 + 508))(v2753);
              if ( v849 )
              {
                *(_DWORD *)(v140 + 856) += v2800 << 9;
                v315 = *(void (**)(void))(v140 + 220);
LABEL_382:
                v315();
              }
              goto LABEL_1564;
            }
          }
          else
          {
            ++*(_DWORD *)(v140 + 1056);
          }
          v849 = 0;
          goto LABEL_1117;
        case 26:
          if ( (*(_DWORD *)(v140 + 864) & 1) != 0 )
            goto LABEL_1565;
          v857 = *(_DWORD *)(v140 + 700);
          v261 = 0;
          v858 = *(_DWORD *)(v140 + 656);
          v2765 = *(_DWORD **)(v140 + 704);
          v859 = *(void (**)(void))(v140 + 280);
          jj = 0;
          v2859 = v857;
          v859();
          (*(void (__fastcall **)(int, _DWORD))(v140 + 240))(v858, 0);
          v860 = *(_DWORD ***)(v140 + 636);
          v861 = *v860;
          if ( *v860 != v860 )
          {
            do
            {
              *((_BYTE *)v861 - 74) = 1;
              v861 = (_DWORD *)*v861;
              ++v261;
            }
            while ( v861 != v860 );
            jj = v261;
          }
          (*(void (__fastcall **)(unsigned int, _DWORD))(v140 + 248))(v857, 0);
          v862 = *(_DWORD ***)(v140 + 696);
          v863 = *v862;
          if ( *v862 != v862 )
          {
            do
            {
              if ( v863 - 4 != v2765 )
              {
                v864 = *(v863 - 1);
                if ( !*(_BYTE *)(v864 + 106) && (*(_DWORD *)(v864 + 192) & 0x4000000) != 0 && !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = v864;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
                *(_BYTE *)(v864 + 106) = 0;
              }
              v863 = (_DWORD *)*v863;
            }
            while ( v863 != v862 );
            v261 = jj;
            v857 = v2859;
          }
          (*(void (__fastcall **)(unsigned int, _DWORD))(v140 + 252))(v857, 0);
LABEL_306:
          v271 = (*(int (__fastcall **)(_DWORD, _DWORD))(v140 + 244))(*(_DWORD *)(v140 + 656), 0);
          (*(void (__fastcall **)(int))(v140 + 284))(v271);
          goto LABEL_307;
        case 27:
          if ( (*(_DWORD *)(v140 + 864) & 1) == 0 )
            goto LABEL_1565;
          v865 = *(_QWORD *)(v140 + 700);
          v866 = *(_DWORD *)(v140 + 656);
          v2766 = *(_DWORD *)(v140 + 700);
          v867 = 0;
          (*(void (**)(void))(v140 + 280))();
          (*(void (__fastcall **)(int, _DWORD))(v140 + 240))(v866, 0);
          (*(void (__fastcall **)(_DWORD, _DWORD))(v140 + 248))(v865, 0);
          v868 = *(_DWORD ***)(v140 + 696);
          for ( n = *v868; n != v868; n = (_DWORD *)*n )
          {
            if ( n - 4 != (_DWORD *)HIDWORD(v865) )
              *(_BYTE *)(*(n - 1) + 106) = 1;
          }
          v870 = *(_DWORD **)(v140 + 636);
          for ( ii = (_DWORD *)*v870; ii != v870; ++v867 )
          {
            if ( !*((_BYTE *)ii - 74) )
            {
              v872 = ii[39];
              if ( v872 )
              {
                if ( v872 != HIDWORD(v865) && !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = ii - 45;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
            }
            *((_BYTE *)ii - 74) = 0;
            ii = (_DWORD *)*ii;
          }
          (*(void (__fastcall **)(int, _DWORD))(v140 + 252))(v2766, 0);
          v873 = (*(int (__fastcall **)(_DWORD, _DWORD))(v140 + 244))(*(_DWORD *)(v140 + 656), 0);
          (*(void (__fastcall **)(int))(v140 + 284))(v873);
          v260 = *(_DWORD *)(v140 + 856) + (v867 << 8);
          goto LABEL_294;
        case 28:
          v874 = v157[2];
          jj = v874;
          if ( v874 )
          {
            v916 = (_DWORD *)v157[1];
            v917 = (char *)v916;
            if ( v916 < (_DWORD *)((char *)v916 + v874) )
            {
              do
              {
                __pld(v917);
                v917 += 128;
              }
              while ( v917 < (char *)v916 + v874 );
            }
            v918 = *(_DWORD *)(v140 + 844);
            v919 = *(_DWORD *)(v140 + 840);
            v920 = v874;
            v2717 = v918;
            if ( v874 >= 8 )
            {
              v921 = *(_DWORD *)(v140 + 836);
              v922 = v874 >> 3;
              v923 = v921 & 0x3F;
              v924 = 64 - (v921 & 0x3F);
              v925 = (v921 & 0x3F) - 32;
              v926 = 32 - (v921 & 0x3F);
              do
              {
                v920 -= 8;
                v927 = v919 ^ *v916;
                v928 = v916[1];
                v916 += 2;
                v929 = (v927 >> v924) | ((v918 ^ v928) << v925) | ((v918 ^ v928) >> v926);
                v918 = ((v918 ^ v928) >> v924) | (__PAIR64__(v918 ^ v928, v927) << v923 >> 32);
                v919 = v929 | (v927 << v923);
                --v922;
                v926 = v924 - 32;
              }
              while ( v922 );
              v140 = (unsigned int)v2734;
              v874 = jj;
              v2717 = v918;
            }
            if ( v920 )
            {
              v930 = *(_DWORD *)(v140 + 836) & 0x3F;
              v931 = 64 - v930;
              v932 = 32 - v930;
              do
              {
                v933 = *(unsigned __int8 *)v916;
                v916 = (_DWORD *)((char *)v916 + 1);
                v934 = v919 ^ v933;
                v935 = (v934 >> v931) | (v918 << (v930 - 32)) | (v918 >> (32 - v930));
                v918 = (v918 >> v931) | (v934 << (v930 - 32)) | (v2717 << v930) | (v934 >> v932);
                v2717 = v918;
                v919 = v935 | (v934 << v930);
                --v920;
                v932 = 32 - v930;
              }
              while ( v920 );
              v140 = (unsigned int)v2734;
              v874 = jj;
            }
            v936 = __PAIR64__(v918, v919);
            *(_DWORD *)(v140 + 856) += v874;
            while ( 1 )
            {
              LODWORD(v936) = FsRtlPrivateResetHighestLockOffset(v936, HIDWORD(v936), 31);
              if ( !v936 )
                break;
              v919 ^= v936;
            }
            v937 = v2822[3];
            if ( (v919 & 0x7FFFFFFF) != v937 )
            {
              if ( !*(_DWORD *)(v140 + 880) )
              {
                v938 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v938 + 16) = v919 & 0x7FFFFFFF ^ v937;
                *(_DWORD *)(v938 + 20) = 0;
              }
              v939 = v2822[1];
              if ( !*(_DWORD *)(v140 + 880) )
              {
                *(_QWORD *)(v140 + 888) = v140 - 1849117464;
                *(_QWORD *)(v140 + 896) = (unsigned int)v2822 - 465226731;
                *(_QWORD *)(v140 + 904) = *v2822;
                *(_DWORD *)(v140 + 912) = v939;
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
            }
            v940 = 0;
            v2718 = 0;
            v2887 = v2822[1] - 56;
            HIDWORD(v941) = *(_DWORD *)(v2887 + 40);
            v2767 = HIDWORD(v941);
            if ( HIDWORD(v941) )
            {
              v940 = *(_DWORD *)HIDWORD(v941);
              v2718 = *(_DWORD *)HIDWORD(v941);
            }
            LODWORD(v941) = *(_DWORD *)(v2887 + 40);
            v2692 = v941;
            v942 = (char *)v941;
            if ( HIDWORD(v941) < v940 + HIDWORD(v941) )
            {
              do
              {
                __pld(v942);
                v942 += 128;
              }
              while ( (unsigned int)v942 < v940 + HIDWORD(v941) );
            }
            HIDWORD(v941) = *(_DWORD *)(v140 + 844);
            v943 = *(_DWORD *)(v140 + 840);
            v944 = v940;
            if ( v940 >= 8 )
            {
              v945 = v940 >> 3;
              v946 = *(_DWORD *)(v140 + 836) & 0x3F;
              v947 = 64 - v946;
              do
              {
                v944 -= 8;
                v948 = v943 ^ *(_DWORD *)v941;
                v949 = HIDWORD(v941) ^ *(_DWORD *)(v941 + 4);
                v950 = (v948 >> v947) | (v949 << (v946 - 32)) | (v949 >> (32 - v946));
                v951 = v949 >> v947;
                v952 = (v949 << v946) | (v948 >> (32 - v946));
                v953 = v948 << (v946 - 32);
                v943 = v950 | (v948 << v946);
                HIDWORD(v941) = v951 | v953 | v952;
                LODWORD(v941) = v2692 + 8;
                v2692 += 8;
                --v945;
              }
              while ( v945 );
              v940 = v2718;
              v140 = (unsigned int)v2734;
            }
            if ( v944 )
            {
              v954 = *(_DWORD *)(v140 + 836) & 0x3F;
              v955 = 64 - v954;
              do
              {
                v956 = v943 ^ *(unsigned __int8 *)v941;
                v957 = __PAIR64__(HIDWORD(v941), v956) << v954 >> 32;
                v943 = (v956 >> v955) | (HIDWORD(v941) << (v954 - 32)) | (HIDWORD(v941) >> (32 - v954)) | (v956 << v954);
                LODWORD(v941) = v941 + 1;
                HIDWORD(v941) = (HIDWORD(v941) >> v955) | v957;
                --v944;
              }
              while ( v944 );
              v940 = v2718;
              v140 = (unsigned int)v2734;
            }
            LODWORD(v941) = v943;
            *(_DWORD *)(v140 + 856) += v940;
            while ( 1 )
            {
              LODWORD(v941) = FsRtlPrivateResetHighestLockOffset(v941, HIDWORD(v941), 31);
              if ( !v941 )
                break;
              v943 ^= v941;
            }
            v958 = v2822[7];
            if ( (v943 & 0x7FFFFFFF) != v958 )
            {
              if ( !*(_DWORD *)(v140 + 880) )
              {
                v959 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v959 + 16) = v943 & 0x7FFFFFFF ^ v958;
                *(_DWORD *)(v959 + 20) = 0;
              }
              if ( !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v2822;
                *(_DWORD *)(v140 + 912) = v2767;
                goto LABEL_440;
              }
            }
          }
          else
          {
            v2946 = v157 + 10;
            v2945[0] = *((_WORD *)v157 + 12);
            v2945[1] = v2945[0];
            if ( (*(int (__fastcall **)(__int16 *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int *))(v140 + 316))(
                   v2945,
                   0,
                   0,
                   0,
                   *(_DWORD *)(v140 + 632),
                   0,
                   0,
                   &v2887) < 0 )
              goto LABEL_1564;
            if ( (*(_DWORD *)(v2887 + 8) & 0x10) == 0 )
            {
LABEL_381:
              v315 = *(void (**)(void))(v140 + 312);
              goto LABEL_382;
            }
            if ( (*(int (__fastcall **)(_DWORD, unsigned int *, char *))(v140 + 328))(
                   *(_DWORD *)(v140 + 316),
                   &v2917,
                   v2950)
              && (v875 = (*(int (__fastcall **)(unsigned int))(v140 + 324))(v2917)) != 0 )
            {
              v876 = *(_BYTE **)(v875 + 80);
              v2853 = v876;
            }
            else
            {
              v876 = v2853;
            }
            if ( (*(int (__fastcall **)(int, unsigned int *, char *))(v140 + 328))(v157[4], &v2916, v2951) )
            {
              v877 = (*(int (__fastcall **)(unsigned int))(v140 + 324))(v2916);
              if ( v877 )
                v2811 = *(_BYTE **)(v877 + 80);
            }
            v878 = 0;
            v157[1] = v2887 + 56;
            v157[2] = 112;
            while ( 1 )
            {
              v879 = *(_DWORD *)(v2887 + 4 * v878 + 56);
              if ( (!v876 || v879 < v2917 || v879 > (unsigned int)&v876[v2917 - 1])
                && (!v2811 || v879 < v2916 || v879 > (unsigned int)&v2811[v2916 - 1]) )
              {
                break;
              }
              v878 = (unsigned __int8)(v878 + 1);
              if ( v878 >= 0x1C )
              {
                v880 = (_DWORD *)v157[1];
                v881 = (char *)v880;
                if ( v880 < v880 + 28 )
                {
                  do
                  {
                    __pld(v881);
                    v881 += 128;
                  }
                  while ( v881 < (char *)v880 + 112 );
                }
                v882 = *(_DWORD *)(v140 + 840);
                HIDWORD(v886) = *(_DWORD *)(v140 + 844);
                v883 = 112;
                v884 = *(_QWORD *)(v140 + 836) & 0x3F;
                v885 = 64 - v884;
                LOBYTE(v886) = 32 - v884;
                v887 = 14;
                do
                {
                  v883 -= 8;
                  v888 = v882 ^ *v880;
                  v889 = v880[1];
                  v880 += 2;
                  HIDWORD(v886) ^= v889;
                  v890 = __PAIR64__(HIDWORD(v886), v888) << v884;
                  v882 = (v888 >> v885) | (HIDWORD(v886) << (v884 - 32)) | (HIDWORD(v886) >> v886) | (v888 << v884);
                  HIDWORD(v886) = (HIDWORD(v886) >> v885) | HIDWORD(v890);
                  --v887;
                  LOBYTE(v886) = 32 - v884;
                }
                while ( v887 );
                v140 = (unsigned int)v2734;
                if ( v883 )
                {
                  do
                  {
                    v891 = *(unsigned __int8 *)v880;
                    v880 = (_DWORD *)((char *)v880 + 1);
                    v892 = v882 ^ v891;
                    LODWORD(v886) = __PAIR64__(HIDWORD(v886), v892) >> v885;
                    HIDWORD(v886) = (HIDWORD(v886) >> v885) | (__PAIR64__(HIDWORD(v886), v892) << v884 >> 32);
                    v882 = v886 | (v892 << v884);
                    --v883;
                  }
                  while ( v883 );
                  v140 = (unsigned int)v2734;
                }
                LODWORD(v886) = v882;
                *(_DWORD *)(v140 + 856) += 112;
                while ( 1 )
                {
                  LODWORD(v886) = FsRtlPrivateResetHighestLockOffset(v886, HIDWORD(v886), 31);
                  if ( !v886 )
                    break;
                  v882 ^= v886;
                }
                v893 = 0;
                v2822[3] = v882 & 0x7FFFFFFF;
                v2716 = 0;
                LODWORD(v894) = *(_DWORD *)(v2887 + 40);
                v2691 = v894;
                if ( (_DWORD)v894 )
                {
                  v893 = *(_DWORD *)v894;
                  v895 = 0;
                  v896 = (unsigned int)(*(_DWORD *)v894 - 4) >> 2;
                  v2716 = *(_DWORD *)v894;
                  if ( v896 )
                  {
                    do
                    {
                      v897 = *(_DWORD *)(v894 + 4 + 4 * v895);
                      if ( v897 )
                      {
                        v140 = (unsigned int)v2734;
                        if ( (!v2853 || v897 < v2917 || v897 > (unsigned int)&v2853[v2917 - 1])
                          && (!v2811 || v897 < v2916 || v897 > (unsigned int)&v2811[v2916 - 1]) )
                        {
                          v2822[5] = v897;
                          v914 = (int **)*((_DWORD *)v2734 + 172);
                          *v914 = v2822;
                          v914[2] = (int *)40;
                          if ( *((_DWORD *)v2734 + 220) )
                            goto LABEL_1564;
                          *((_DWORD *)v2734 + 222) = v2734 - 1849117464;
                          *((_DWORD *)v2734 + 223) = 0;
                          *((_DWORD *)v2734 + 224) = (char *)v2822 - 465226731;
                          *((_DWORD *)v2734 + 225) = 0;
                          *((_QWORD *)v2734 + 113) = *v2822;
                          *((_DWORD *)v2734 + 228) = v894;
LABEL_440:
                          *(_DWORD *)(v140 + 916) = 0;
LABEL_1563:
                          *(_DWORD *)(v140 + 880) = 1;
                          goto LABEL_1564;
                        }
                      }
                      v895 = (unsigned __int8)(v895 + 1);
                    }
                    while ( v895 < v896 );
                    v893 = *(_DWORD *)v894;
                  }
                }
                v898 = *(char **)(v2887 + 40);
                if ( (unsigned int)v894 < v893 + (unsigned int)v894 )
                {
                  do
                  {
                    __pld(v898);
                    v898 += 128;
                  }
                  while ( (unsigned int)v898 < v893 + (unsigned int)v894 );
                }
                HIDWORD(v894) = *(_DWORD *)(v140 + 844);
                v899 = *(_DWORD *)(v140 + 840);
                v900 = v893;
                if ( v893 >= 8 )
                {
                  v901 = v893 >> 3;
                  v902 = *(_DWORD *)(v140 + 836) & 0x3F;
                  v903 = 64 - v902;
                  do
                  {
                    v900 -= 8;
                    v904 = v899 ^ *(_DWORD *)v894;
                    v905 = HIDWORD(v894) ^ *(_DWORD *)(v894 + 4);
                    v906 = (v904 >> v903) | (v905 << (v902 - 32)) | (v905 >> (32 - v902));
                    v907 = v905 >> v903;
                    v908 = (v905 << v902) | (v904 >> (32 - v902));
                    v909 = v904 << (v902 - 32);
                    v899 = v906 | (v904 << v902);
                    HIDWORD(v894) = v907 | v909 | v908;
                    LODWORD(v894) = v2691 + 8;
                    v2691 += 8;
                    --v901;
                  }
                  while ( v901 );
                  v140 = (unsigned int)v2734;
                }
                if ( v900 )
                {
                  v910 = *(_DWORD *)(v140 + 836) & 0x3F;
                  v911 = 64 - v910;
                  do
                  {
                    v912 = v899 ^ *(unsigned __int8 *)v894;
                    v913 = __PAIR64__(HIDWORD(v894), v912) << v910 >> 32;
                    v899 = (v912 >> v911) | (HIDWORD(v894) << (v910 - 32)) | (HIDWORD(v894) >> (32 - v910)) | (v912 << v910);
                    LODWORD(v894) = v894 + 1;
                    HIDWORD(v894) = (HIDWORD(v894) >> v911) | v913;
                    --v900;
                  }
                  while ( v900 );
                  v140 = (unsigned int)v2734;
                }
                LODWORD(v894) = v899;
                *(_DWORD *)(v140 + 856) += v2716;
                while ( 1 )
                {
                  LODWORD(v894) = FsRtlPrivateResetHighestLockOffset(v894, HIDWORD(v894), 31);
                  if ( !v894 )
                    break;
                  v899 ^= v894;
                }
                v2822[7] = v899 & 0x7FFFFFFF;
                goto LABEL_1564;
              }
            }
            v157[5] = v879;
            v915 = *(int ***)(v140 + 688);
            *v915 = v157;
            v915[2] = (int *)40;
            v356 = v157[1];
            if ( !*(_DWORD *)(v140 + 880) )
            {
LABEL_439:
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v157;
              *(_DWORD *)(v140 + 912) = v356;
              goto LABEL_440;
            }
          }
          goto LABEL_1564;
        case 29:
          v960 = v157[2];
          v961 = (_DWORD *)v157[1];
          v2768 = v960;
          v962 = (char *)v961;
          if ( v961 < (_DWORD *)((char *)v961 + v960) )
          {
            do
            {
              __pld(v962);
              v962 += 128;
            }
            while ( v962 < (char *)v961 + v960 );
          }
          v963 = *(_DWORD *)(v140 + 844);
          v964 = *(_DWORD *)(v140 + 840);
          v965 = v157[2];
          v2719 = v963;
          if ( v960 >= 8 )
          {
            v966 = v960 >> 3;
            v967 = *(_DWORD *)(v140 + 836) & 0x3F;
            v968 = 64 - v967;
            v969 = 32 - v967;
            do
            {
              v965 -= 8;
              v970 = v964 ^ *v961;
              v971 = v961[1];
              v961 += 2;
              v972 = (v970 >> v968) | ((v963 ^ v971) << (v967 - 32)) | ((v963 ^ v971) >> v969);
              v963 = ((v963 ^ v971) >> v968) | (__PAIR64__(v963 ^ v971, v970) << v967 >> 32);
              v964 = v972 | (v970 << v967);
              --v966;
              v969 = 32 - v967;
            }
            while ( v966 );
            v140 = (unsigned int)v2734;
            v2719 = v963;
          }
          if ( v965 )
          {
            v973 = *(_DWORD *)(v140 + 836) & 0x3F;
            v974 = 64 - v973;
            v975 = 32 - v973;
            do
            {
              v976 = *(unsigned __int8 *)v961;
              v961 = (_DWORD *)((char *)v961 + 1);
              v977 = v964 ^ v976;
              v978 = (v977 >> v974) | (v963 << (v973 - 32)) | (v963 >> (32 - v973));
              v963 = (v963 >> v974) | (v977 << (v973 - 32)) | (v2719 << v973) | (v977 >> v975);
              v2719 = v963;
              v964 = v978 | (v977 << v973);
              --v965;
              v975 = 32 - v973;
            }
            while ( v965 );
            v140 = (unsigned int)v2734;
          }
          v979 = __PAIR64__(v963, v964);
          *(_DWORD *)(v140 + 856) += v2768;
          while ( 1 )
          {
            LODWORD(v979) = FsRtlPrivateResetHighestLockOffset(v979, HIDWORD(v979), 31);
            if ( !v979 )
              break;
            v964 ^= v979;
          }
          v980 = v2822[3];
          if ( (v964 & 0x7FFFFFFF) != v980 )
          {
            if ( !*(_DWORD *)(v140 + 880) )
            {
              v981 = *(_DWORD *)(v140 + 688);
              *(_DWORD *)(v981 + 16) = v964 & 0x7FFFFFFF ^ v980;
              *(_DWORD *)(v981 + 20) = 0;
            }
            v982 = v2822[1];
            if ( !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2822;
              *(_DWORD *)(v140 + 912) = v982;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
          }
          v983 = (_DWORD **)v2822[1];
          v984 = (unsigned int)v2822[2] >> 3;
          for ( jj = v984; v984; jj = v984 )
          {
            v985 = *v983;
            v983 += 2;
            HIDWORD(v986) = *v985;
            v2926 = 0;
            LODWORD(v986) = (*(int (__fastcall **)(_DWORD, int *))(v140 + 452))(HIDWORD(v986), &v2926);
            if ( (_DWORD)v986 )
            {
              do
              {
                (*(void (__fastcall **)(_DWORD, int *, char *))(v140 + 328))(v986, &v2922, v2955);
                if ( !v2922 && !(*(int (__fastcall **)(_DWORD, int *))(v140 + 332))(v986, &v2922) )
                {
                  *((_QWORD *)v2822 + 2) = v986;
                  v987 = *(int ***)(v140 + 688);
                  *v987 = v2822;
                  v987[2] = (int *)40;
                  v988 = *(_DWORD *)(v140 + 688);
                  *(_DWORD *)(v988 + 4) = v986;
                  *(_DWORD *)(v988 + 12) = 4096;
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_QWORD *)(v140 + 904) = *v2822;
                    *(_DWORD *)(v140 + 912) = 6;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
                LODWORD(v986) = (*(int (__fastcall **)(_DWORD, int *))(v140 + 452))(HIDWORD(v986), &v2926);
              }
              while ( (_DWORD)v986 );
              v984 = jj;
            }
            --v984;
          }
          goto LABEL_1564;
        case 30:
          if ( (*((_WORD *)v157 + 15) & 1) != 0 && !*(_DWORD *)(v140 + 988) )
          {
LABEL_210:
            *(_DWORD *)(v140 + 852) = 0;
            v149 = v2839;
            v150 = v2840;
            v151 = v2838;
            goto LABEL_278;
          }
          v989 = v157[1];
          v990 = *(_DWORD *)(v140 + 852);
          v991 = (unsigned int)v157[6] >> 3;
          v2841 = v989 + 8 * v991;
          v2846 = v989;
          v992 = (_DWORD *)(v989 + 8 * v990);
          v993 = v157 + 10;
          v994 = (int *)((char *)v157 + ((v991 + 6) & 0xFFFFFFF8) + 40);
          v995 = v992 + 2;
          v996 = (char *)v993 + v990;
          v997 = *((unsigned __int16 *)v2822 + 14);
          v2847 = (unsigned int)v992;
          v2720 = v992 + 2;
          v2861 = (unsigned int)&v994[6 * v997];
          v998 = v991 - 1;
          v2845 = (unsigned int)v993 + v990;
          v2851 = v994;
          if ( v990 < v991 - 1 )
          {
            v999 = v2822;
            do
            {
              if ( (*v996 & 0x80) == 0 )
              {
                v1000 = v992[1];
                if ( (v1000 & 3) != 0 )
                  v1001 = (v1000 >> 2) & 0x7FF;
                else
                  v1001 = *(_DWORD *)(v1000 + v999[4]) & 0x3FFFF;
                v1002 = (*v992 + 2 * v1001) & 0xFFFFFFFE;
                HIDWORD(v1003) = (*v995 & 0xFFFFFFFE) - v1002;
                v2769 = HIDWORD(v1003);
                v1004 = (_DWORD *)(v1002 + v999[4]);
                v2801 = v1004;
                v2859 = (unsigned int)v1004;
                v1005 = (char *)v1004;
                if ( v1004 < (_DWORD *)((char *)v1004 + HIDWORD(v1003)) )
                {
                  do
                  {
                    __pld(v1005);
                    v1005 += 128;
                  }
                  while ( v1005 < (char *)v1004 + HIDWORD(v1003) );
                }
                v1006 = *(_DWORD *)(v140 + 844);
                LODWORD(v1003) = *(_DWORD *)(v140 + 840);
                v1007 = HIDWORD(v1003);
                v2693 = HIDWORD(v1003);
                jj = v1006;
                if ( HIDWORD(v1003) < 8 )
                {
                  HIDWORD(v1003) = jj;
                }
                else
                {
                  v1008 = HIDWORD(v1003) >> 3;
                  HIDWORD(v1003) = v1006;
                  v1009 = *(_DWORD *)(v140 + 836) & 0x3F;
                  v1010 = 64 - v1009;
                  do
                  {
                    v1011 = v1003 ^ *v1004;
                    v1012 = HIDWORD(v1003) ^ v1004[1];
                    v1013 = (v1011 >> v1010) | (v1012 << (v1009 - 32)) | (v1012 >> (32 - v1009));
                    HIDWORD(v1003) = (v1012 >> v1010) | (v1011 << (v1009 - 32)) | (v1012 << v1009) | (v1011 >> (32 - v1009));
                    v1004 = v2801 + 2;
                    v1007 = v2693 - 8;
                    LODWORD(v1003) = v1013 | (v1011 << v1009);
                    v2801 += 2;
                    v2693 -= 8;
                    --v1008;
                  }
                  while ( v1008 );
                  v140 = (unsigned int)v2734;
                }
                if ( v1007 )
                {
                  v1014 = *(_DWORD *)(v140 + 836) & 0x3F;
                  v1015 = 64 - v1014;
                  do
                  {
                    v1016 = *(unsigned __int8 *)v1004 ^ (unsigned int)v1003;
                    LODWORD(v1003) = (v1016 >> v1015) | (HIDWORD(v1003) << (v1014 - 32)) | (HIDWORD(v1003) >> (32 - v1014));
                    HIDWORD(v1003) = (HIDWORD(v1003) >> v1015) | (v1016 << (v1014 - 32)) | (HIDWORD(v1003) << v1014) | (v1016 >> (32 - v1014));
                    LODWORD(v1003) = v1003 | (v1016 << v1014);
                    _ZF = v2693 == 1;
                    v1004 = (_DWORD *)((char *)v1004 + 1);
                    --v2693;
                  }
                  while ( !_ZF );
                  v140 = (unsigned int)v2734;
                }
                v1017 = v1003;
                *(_DWORD *)(v140 + 856) += v2769;
                while ( 1 )
                {
                  LODWORD(v1003) = FsRtlPrivateResetHighestLockOffset(v1003, HIDWORD(v1003), 7);
                  if ( !v1003 )
                    break;
                  v1017 ^= v1003;
                }
                v996 = (_BYTE *)v2845;
                v1018 = *(_BYTE *)v2845 & 0x7F;
                if ( (v1017 & 0x7F) == v1018 )
                {
                  v999 = v2822;
                }
                else
                {
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    v1019 = *(_DWORD *)(v140 + 688);
                    *(_DWORD *)(v1019 + 16) = v1017 & 0x7F ^ v1018;
                    *(_DWORD *)(v1019 + 20) = 0;
                  }
                  v999 = v2822;
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_QWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_QWORD *)(v140 + 896) = (unsigned int)v2822 - 465226731;
                    *(_QWORD *)(v140 + 904) = *v2822;
                    *(_QWORD *)(v140 + 912) = v2859;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
                v992 = (_DWORD *)v2847;
                v995 = v2720;
                *(_DWORD *)(v140 + 856) += 64;
              }
              ++v996;
              v992 += 2;
              v995 += 2;
              v2845 = (unsigned int)v996;
              v2847 = (unsigned int)v992;
              v2720 = v995;
            }
            while ( (unsigned int)v995 < v2841 && *(_DWORD *)(v140 + 856) < *(_DWORD *)(v140 + 860) );
            v994 = v2851;
            *(_DWORD *)(v140 + 852) = (int)((int)v992 - v2846) >> 3;
            v149 = v2839;
            v150 = v2840;
            v151 = v2838;
            v998 = v991 - 1;
          }
          v1020 = *(_DWORD *)(v140 + 852);
          if ( v1020 < v998 || *(_DWORD *)(v140 + 856) >= *(_DWORD *)(v140 + 860) )
            goto LABEL_1565;
          v1021 = v2822;
          v1022 = &v994[6 * (v1020 - v991) + 6];
          do
          {
            jj = 2;
            v2754 = v1022;
            do
            {
              if ( (v1022[2] & 0x80000000) == 0 )
              {
                v1023 = v1022[1] - *v1022;
                v2770 = v1023;
                v1024 = (_DWORD *)(*v1022 + v1021[4]);
                v2694 = v1024;
                v2859 = (unsigned int)v1024;
                v1025 = (char *)v1024;
                if ( v1024 < (_DWORD *)((char *)v1024 + v1023) )
                {
                  do
                  {
                    __pld(v1025);
                    v1025 += 128;
                  }
                  while ( v1025 < (char *)v1024 + v1023 );
                }
                HIDWORD(v1026) = *(_DWORD *)(v140 + 844);
                v1027 = *(_DWORD *)(v140 + 840);
                v1028 = v1023;
                v2721 = v1023;
                if ( v1023 >= 8 )
                {
                  v1029 = v1023 >> 3;
                  v1030 = *(_DWORD *)(v140 + 836) & 0x3F;
                  v1031 = 64 - v1030;
                  do
                  {
                    v1028 -= 8;
                    v1032 = v1027 ^ *v1024;
                    v1033 = HIDWORD(v1026) ^ v1024[1];
                    LODWORD(v1026) = (v1032 >> v1031) | (v1033 << (v1030 - 32)) | (v1033 >> (32 - v1030));
                    HIDWORD(v1026) = (v1033 >> v1031) | (__PAIR64__(v1033, v1032) << v1030 >> 32);
                    v1027 = v1026 | (v1032 << v1030);
                    v1024 = v2694 + 2;
                    v2694 += 2;
                    --v1029;
                  }
                  while ( v1029 );
                  v140 = (unsigned int)v2734;
                  v2721 = v1028;
                }
                if ( v1028 )
                {
                  v1034 = *(_DWORD *)(v140 + 836) & 0x3F;
                  v1035 = 64 - v1034;
                  do
                  {
                    v1036 = v1027 ^ *(unsigned __int8 *)v1024;
                    LODWORD(v1026) = (v1036 >> v1035) | (HIDWORD(v1026) << (v1034 - 32)) | (HIDWORD(v1026) >> (32 - v1034));
                    HIDWORD(v1026) = (HIDWORD(v1026) >> v1035) | (v1036 << (v1034 - 32)) | (HIDWORD(v1026) << v1034) | (v1036 >> (32 - v1034));
                    v1024 = (_DWORD *)((char *)v1024 + 1);
                    v1027 = v1026 | (v1036 << v1034);
                    --v2721;
                  }
                  while ( v2721 );
                  v140 = (unsigned int)v2734;
                }
                LODWORD(v1026) = v1027;
                *(_DWORD *)(v140 + 856) += v2770;
                while ( 1 )
                {
                  LODWORD(v1026) = FsRtlPrivateResetHighestLockOffset(v1026, HIDWORD(v1026), 31);
                  if ( !v1026 )
                    break;
                  v1027 ^= v1026;
                }
                v1037 = v2754[2] & 0x7FFFFFFF;
                if ( (v1027 & 0x7FFFFFFF) == v1037 )
                {
                  v1022 = v2754;
                  v1021 = v2822;
                }
                else
                {
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    v1038 = *(_DWORD *)(v140 + 688);
                    *(_DWORD *)(v1038 + 16) = v1027 & 0x7FFFFFFF ^ v1037;
                    *(_DWORD *)(v1038 + 20) = 0;
                  }
                  v1021 = v2822;
                  v1022 = v2754;
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_QWORD *)(v140 + 904) = *v2822;
                    *(_DWORD *)(v140 + 912) = v2859;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
              }
              v1022 += 3;
              v2754 = v1022;
              --jj;
            }
            while ( jj );
            ++*(_DWORD *)(v140 + 852);
            if ( v1022 == (int *)v2861 )
            {
              *(_DWORD *)(v140 + 852) = 0;
              goto LABEL_1564;
            }
          }
          while ( *(_DWORD *)(v140 + 856) < *(_DWORD *)(v140 + 860) );
          goto LABEL_1564;
        case 31:
          if ( (*(_DWORD *)(v140 + 864) & 1) == 0 )
            goto LABEL_1565;
          v1039 = 0;
          v2755 = 0;
          if ( (MEMORY[0xFFFF92D0] & v2863) == 0 || (*(_DWORD *)(v140 + 996) & 2) != 0 )
          {
            if ( *(_DWORD *)(v140 + 988)
              && (*(int (__fastcall **)(int, int *, _DWORD, _DWORD))(v140 + 540))(26, &v2940, 0, 0) >= 0 )
            {
              v1039 = v2940;
            }
            else
            {
              v1039 = 0;
            }
            v2755 = v1039;
          }
          v261 = 0;
          v2695 = 0;
          v1040 = (*(int (__fastcall **)(_DWORD))(v140 + 532))(0);
          if ( !v1040 )
            goto LABEL_1416;
          v2859 = v140 - 1849117464;
          v1041 = v140 - 1849117464;
          v1042 = v140 - 1849117464;
          v2847 = v140 - 1849117464;
          v2845 = v140 - 1849117464;
          break;
        case 35:
          if ( (v157[6] & 1) != 0 && !*(_DWORD *)(v140 + 988) )
            goto LABEL_1565;
          v1084 = v157[2];
          v1085 = (_DWORD *)v157[1];
          v2772 = v1084;
          v1086 = (char *)v1085;
          if ( v1085 < (_DWORD *)((char *)v1085 + v1084) )
          {
            do
            {
              __pld(v1086);
              v1086 += 128;
            }
            while ( v1086 < (char *)v1085 + v1084 );
          }
          v1087 = *(_DWORD *)(v140 + 844);
          v1088 = *(_DWORD *)(v140 + 840);
          v1089 = v157[2];
          v2722 = v1087;
          if ( v1084 >= 8 )
          {
            v1090 = v1084 >> 3;
            v1091 = *(_DWORD *)(v140 + 836) & 0x3F;
            v1092 = 64 - v1091;
            v1093 = 32 - v1091;
            do
            {
              v1089 -= 8;
              v1094 = v1088 ^ *v1085;
              v1095 = v1085[1];
              v1085 += 2;
              v1096 = (v1094 >> v1092) | ((v1095 ^ v1087) << (v1091 - 32)) | ((v1095 ^ v1087) >> v1093);
              v1087 = ((v1095 ^ v1087) >> v1092) | (__PAIR64__(v1095 ^ v1087, v1094) << v1091 >> 32);
              v1088 = v1096 | (v1094 << v1091);
              --v1090;
              v1093 = 32 - v1091;
            }
            while ( v1090 );
            v140 = (unsigned int)v2734;
            v2722 = v1087;
          }
          if ( v1089 )
          {
            v1097 = *(_DWORD *)(v140 + 836) & 0x3F;
            v1098 = 64 - v1097;
            v1099 = 32 - v1097;
            do
            {
              v1100 = *(unsigned __int8 *)v1085;
              v1085 = (_DWORD *)((char *)v1085 + 1);
              v1101 = v1088 ^ v1100;
              v1102 = (v1101 >> v1098) | (v1087 << (v1097 - 32)) | (v1087 >> (32 - v1097));
              v1087 = (v1087 >> v1098) | (v1101 << (v1097 - 32)) | (v2722 << v1097) | (v1101 >> v1099);
              v2722 = v1087;
              v1088 = v1102 | (v1101 << v1097);
              --v1089;
              v1099 = 32 - v1097;
            }
            while ( v1089 );
            v140 = (unsigned int)v2734;
          }
          v1103 = __PAIR64__(v1087, v1088);
          *(_DWORD *)(v140 + 856) += v2772;
          while ( 1 )
          {
            LODWORD(v1103) = FsRtlPrivateResetHighestLockOffset(v1103, HIDWORD(v1103), 31);
            if ( !v1103 )
              break;
            v1088 ^= v1103;
          }
          v1104 = v2822[3];
          if ( (v1088 & 0x7FFFFFFF) != v1104 )
          {
            if ( !*(_DWORD *)(v140 + 880) )
            {
              v1105 = *(_DWORD *)(v140 + 688);
              *(_DWORD *)(v1105 + 16) = v1088 & 0x7FFFFFFF ^ v1104;
              *(_DWORD *)(v1105 + 20) = 0;
            }
            v1106 = v2822[1];
            if ( !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2822;
              *(_DWORD *)(v140 + 912) = v1106;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
          }
          v1107 = v2822[6];
          if ( (v1107 & 2) != 0 )
          {
            v1108 = v2822[1];
            if ( (v1107 & 4) != 0 )
            {
              v1109 = v2822[4];
              v1110 = **(_DWORD **)(v1108 + 72);
              if ( v1110 != v1109 )
              {
                v1111 = *(_DWORD **)(v140 + 688);
                *v1111 = v1110;
                v1111[2] = 256;
                if ( !*(_DWORD *)(v140 + 880) )
                  *(_QWORD *)(*(_DWORD *)(v140 + 688) + 16) = v1110 ^ v1109;
                v1112 = *(_DWORD *)(v1108 + 72);
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = v1112;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
            }
            if ( (v2822[6] & 8) != 0 )
            {
              v1113 = v2822[5];
              v1114 = **(_DWORD **)(v1108 + 76);
              if ( v1114 != v1113 )
              {
                v1115 = *(_DWORD **)(v140 + 688);
                *v1115 = v1114;
                v1115[2] = 256;
                if ( !*(_DWORD *)(v140 + 880) )
                  *(_QWORD *)(*(_DWORD *)(v140 + 688) + 16) = v1114 ^ v1113;
                v186 = *(_DWORD *)(v1108 + 76);
                if ( !*(_DWORD *)(v140 + 880) )
                {
LABEL_434:
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  v187 = *v2822;
LABEL_207:
                  *(_QWORD *)(v140 + 904) = v187;
                  *(_DWORD *)(v140 + 912) = v186;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
            }
          }
          goto LABEL_1564;
        case 36:
          v1116 = v157[2];
          v1117 = (_DWORD *)v157[1];
          v2773 = v1116;
          v1118 = (char *)v1117;
          if ( v1117 < (_DWORD *)((char *)v1117 + v1116) )
          {
            do
            {
              __pld(v1118);
              v1118 += 128;
            }
            while ( v1118 < (char *)v1117 + v1116 );
          }
          v1119 = *(_DWORD *)(v140 + 844);
          v1120 = *(_DWORD *)(v140 + 840);
          v1121 = v157[2];
          v2723 = v1119;
          if ( v1116 >= 8 )
          {
            v1122 = v1116 >> 3;
            v1123 = *(_DWORD *)(v140 + 836) & 0x3F;
            v1124 = 64 - v1123;
            v1125 = 32 - v1123;
            do
            {
              v1121 -= 8;
              v1126 = v1120 ^ *v1117;
              v1127 = v1117[1];
              v1117 += 2;
              v1128 = (v1126 >> v1124) | ((v1127 ^ v1119) << (v1123 - 32)) | ((v1127 ^ v1119) >> v1125);
              v1119 = ((v1127 ^ v1119) >> v1124) | (__PAIR64__(v1127 ^ v1119, v1126) << v1123 >> 32);
              v1120 = v1128 | (v1126 << v1123);
              --v1122;
              v1125 = 32 - v1123;
            }
            while ( v1122 );
            v140 = (unsigned int)v2734;
            v2723 = v1119;
          }
          if ( v1121 )
          {
            v1129 = *(_DWORD *)(v140 + 836) & 0x3F;
            v1130 = 64 - v1129;
            v1131 = 32 - v1129;
            do
            {
              v1132 = *(unsigned __int8 *)v1117;
              v1117 = (_DWORD *)((char *)v1117 + 1);
              v1133 = v1120 ^ v1132;
              v1134 = (v1133 >> v1130) | (v1119 << (v1129 - 32)) | (v1119 >> (32 - v1129));
              v1119 = (v1119 >> v1130) | (v1133 << (v1129 - 32)) | (v2723 << v1129) | (v1133 >> v1131);
              v2723 = v1119;
              v1120 = v1134 | (v1133 << v1129);
              --v1121;
              v1131 = 32 - v1129;
            }
            while ( v1121 );
            v140 = (unsigned int)v2734;
          }
          v1135 = __PAIR64__(v1119, v1120);
          *(_DWORD *)(v140 + 856) += v2773;
          while ( 1 )
          {
            LODWORD(v1135) = FsRtlPrivateResetHighestLockOffset(v1135, HIDWORD(v1135), 31);
            if ( !v1135 )
              break;
            v1120 ^= v1135;
          }
          v1136 = v2822[3];
          if ( (v1120 & 0x7FFFFFFF) != v1136 )
          {
            if ( !*(_DWORD *)(v140 + 880) )
            {
              v1137 = *(_DWORD *)(v140 + 688);
              *(_DWORD *)(v1137 + 16) = v1120 & 0x7FFFFFFF ^ v1136;
              *(_DWORD *)(v1137 + 20) = 0;
            }
            v1136 = v2822[1];
            if ( !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2822;
              *(_DWORD *)(v140 + 912) = v1136;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
          }
          v1138 = *(_DWORD *)(v140 + 652);
          v1139 = *(_DWORD *)(v140 + 640) + 16;
          v1140 = (*(int (__fastcall **)(int, int))(v140 + 356))(12, v1136);
          (*(void (__fastcall **)(int))(v140 + 260))(v1138);
          v1141 = *(_DWORD *)(v140 + 640);
          v1142 = *(_BYTE *)(v1141 + 12) != 0;
          v1143 = v1139 + 16 * *(_DWORD *)v1141;
          while ( 1 )
          {
            v1144 = 16;
            v1145 = v2822 + 4;
            v1146 = (int *)v1139;
            do
            {
              v1148 = *v1146++;
              v1147 = v1148;
              v1149 = *v1145++;
              if ( v1147 != v1149 )
                goto LABEL_1512;
              v1144 -= 4;
            }
            while ( v1144 >= 4 );
            if ( v1144 )
            {
              while ( 1 )
              {
                v1151 = *(unsigned __int8 *)v1146;
                v1146 = (int *)((char *)v1146 + 1);
                v1150 = v1151;
                v1152 = *(unsigned __int8 *)v1145;
                v1145 = (int *)((char *)v1145 + 1);
                if ( v1150 != v1152 )
                  break;
                if ( !--v1144 )
                  goto LABEL_1513;
              }
LABEL_1512:
              v1139 += 16;
              if ( v1139 < v1143 )
                continue;
            }
LABEL_1513:
            (*(void (__fastcall **)(_DWORD))(v140 + 292))(*(_DWORD *)(v140 + 652));
            (*(void (__fastcall **)(int))(v140 + 360))(v1140);
            if ( (!v1142 || v2822[4] != 1) && v1139 == v1143 && !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2822;
              *(_DWORD *)(v140 + 912) = v1139;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
            v1153 = *(_DWORD *)(v140 + 652);
            v1154 = *(_DWORD *)(v140 + 640) + 16;
            v1155 = (*(int (__fastcall **)(int))(v140 + 356))(12);
            (*(void (__fastcall **)(int))(v140 + 260))(v1153);
            v1156 = 0;
            v1157 = v1154 + 16 * **(_DWORD **)(v140 + 640);
            while ( 1 )
            {
              v1154 += 16;
              if ( v1154 >= v1157 )
                break;
              v1158 = *(_DWORD *)(v1154 + 4);
              if ( v1158 < v1156 )
                break;
              if ( (v1158 & 0xFFFFF000) != v1158 )
                break;
              v1159 = *(_DWORD *)(v1154 + 8) + v1158;
              if ( v1159 <= v1158 || v1159 == v1156 )
                break;
              v1156 = *(_DWORD *)(v1154 + 8) + v1158;
            }
            (*(void (__fastcall **)(_DWORD))(v140 + 292))(*(_DWORD *)(v140 + 652));
            (*(void (__fastcall **)(int))(v140 + 360))(v1155);
            if ( v1154 != v1157 && !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2822;
              *(_DWORD *)(v140 + 912) = v1154;
LABEL_349:
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
            goto LABEL_1564;
          }
        case 37:
          if ( (*(_DWORD *)(v140 + 996) & 2) != 0 )
            goto LABEL_1565;
          if ( !(*(int (**)(void))(v140 + 584))() || *(_DWORD *)(v140 + 880) )
            goto LABEL_1564;
          *(_DWORD *)(v140 + 888) = v140 - 1849117464;
          *(_DWORD *)(v140 + 892) = 0;
          *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
          *(_DWORD *)(v140 + 900) = 0;
          *(_QWORD *)(v140 + 904) = *v157;
          goto LABEL_1532;
        default:
          if ( v164 == 9 )
          {
            v1168 = v157[2];
            v1169 = (_DWORD *)v157[1];
            v2774 = v1168;
            v1170 = (char *)v1169;
            if ( v1169 < (_DWORD *)((char *)v1169 + v1168) )
            {
              do
              {
                __pld(v1170);
                v1170 += 128;
              }
              while ( v1170 < (char *)v1169 + v1168 );
            }
            v1171 = *(_DWORD *)(v140 + 844);
            v1172 = *(_DWORD *)(v140 + 840);
            v1173 = v157[2];
            v2724 = v1171;
            if ( v1168 >= 8 )
            {
              v1174 = v1168 >> 3;
              v1175 = *(_DWORD *)(v140 + 836) & 0x3F;
              v1176 = 64 - v1175;
              v1177 = 32 - v1175;
              do
              {
                v1173 -= 8;
                v1178 = v1172 ^ *v1169;
                v1179 = v1169[1];
                v1169 += 2;
                v1180 = (v1178 >> v1176) | ((v1179 ^ v1171) << (v1175 - 32)) | ((v1179 ^ v1171) >> v1177);
                v1171 = ((v1179 ^ v1171) >> v1176) | (__PAIR64__(v1179 ^ v1171, v1178) << v1175 >> 32);
                v1172 = v1180 | (v1178 << v1175);
                --v1174;
                v1177 = 32 - v1175;
              }
              while ( v1174 );
              v140 = (unsigned int)v2734;
              v2724 = v1171;
            }
            if ( v1173 )
            {
              v1181 = *(_DWORD *)(v140 + 836) & 0x3F;
              v1182 = 64 - v1181;
              v1183 = 32 - v1181;
              do
              {
                v1184 = *(unsigned __int8 *)v1169;
                v1169 = (_DWORD *)((char *)v1169 + 1);
                v1185 = v1172 ^ v1184;
                v1186 = (v1185 >> v1182) | (v1171 << (v1181 - 32)) | (v1171 >> (32 - v1181));
                v1171 = (v1171 >> v1182) | (v1185 << (v1181 - 32)) | (v2724 << v1181) | (v1185 >> v1183);
                v2724 = v1171;
                v1172 = v1186 | (v1185 << v1181);
                --v1173;
                v1183 = 32 - v1181;
              }
              while ( v1173 );
              v140 = (unsigned int)v2734;
            }
            v1187 = __PAIR64__(v1171, v1172);
            *(_DWORD *)(v140 + 856) += v2774;
            while ( 1 )
            {
              LODWORD(v1187) = FsRtlPrivateResetHighestLockOffset(v1187, HIDWORD(v1187), 31);
              if ( !v1187 )
                break;
              v1172 ^= v1187;
            }
            if ( (v1172 & 0x7FFFFFFF) != v2822[3] )
            {
              v1188 = v2822[1];
              if ( !*(_DWORD *)(v140 + 880) )
              {
                *(_QWORD *)(v140 + 888) = v140 - 1849117464;
                *(_QWORD *)(v140 + 896) = (unsigned int)v2822 - 465226731;
                *(_QWORD *)(v140 + 904) = *v2822;
                *(_DWORD *)(v140 + 912) = v1188;
                *(_DWORD *)(v140 + 916) = 0;
                goto LABEL_1563;
              }
            }
            goto LABEL_1564;
          }
          if ( v164 == 22 )
          {
            (*(void (__fastcall **)(char *, int))(v140 + 300))(v2969, v157[6]);
            v1160 = (*(int (__fastcall **)(char *, _DWORD))(v140 + 304))(v2969, 0);
            __disable_irq();
            v1161 = __mrc(15, 0, 1, 0, 2);
            v1162 = v1161 & v2870;
            if ( (v1161 & v2870) == 0 )
            {
              __mcr(15, 0, v2870 | v1161, 1, 0, 2);
              __isb(0xFu);
            }
            __asm { VMRS            R4, FPEXC }
            if ( !v1162 )
            {
              __mcr(15, 0, v1161, 1, 0, 2);
              __isb(0xFu);
            }
            __enable_irq();
            (*(void (__fastcall **)(int))(v140 + 296))(v1160);
            v1166 = *((_QWORD *)v157 + 2);
            if ( (_R4 & (unsigned int)v1166) != HIDWORD(v1166) )
            {
              if ( !*(_DWORD *)(v140 + 880) )
              {
                v1167 = *(_DWORD *)(v140 + 688);
                *(_DWORD *)(v1167 + 16) = HIDWORD(v1166) ^ _R4 & v1166;
                *(_DWORD *)(v1167 + 20) = 0;
              }
              if ( !*(_DWORD *)(v140 + 880) )
              {
                *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                *(_DWORD *)(v140 + 892) = 0;
                *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
                *(_DWORD *)(v140 + 900) = 0;
                *(_QWORD *)(v140 + 904) = *v157;
                *(_DWORD *)(v140 + 912) = HIDWORD(v1166);
                *(_DWORD *)(v140 + 916) = 0;
                *(_DWORD *)(v140 + 880) = 1;
              }
            }
            v260 = *(_DWORD *)(v140 + 856) + 0x8000;
            goto LABEL_294;
          }
          if ( *(_DWORD *)(v140 + 880) )
            goto LABEL_1565;
          *(_DWORD *)(v140 + 888) = v140 - 1849117464;
          *(_DWORD *)(v140 + 892) = 0;
          *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
          *(_DWORD *)(v140 + 900) = 0;
          *(_DWORD *)(v140 + 904) = 257;
          *(_DWORD *)(v140 + 908) = 0;
LABEL_1532:
          *(_DWORD *)(v140 + 912) = 0;
          goto LABEL_440;
      }
      break;
    }
    while ( v1039 == v1040 )
    {
      if ( (*(int (__fastcall **)(int))(v140 + 524))(v1040) >= 0 )
      {
        v1043 = (*(unsigned __int8 (__fastcall **)(int))(v140 + 548))(v1040);
        v1044 = (*(int (__fastcall **)(int, unsigned __int8 *))(v140 + 552))(v1040, &v2867);
        v1045 = (*(int (__fastcall **)(int))(v140 + 556))(v1040);
        if ( v1043 == 97 )
        {
          v1047 = v2822;
        }
        else
        {
          if ( !*(_DWORD *)(v140 + 880) )
          {
            v1046 = *(_DWORD *)(v140 + 688);
            *(_DWORD *)(v1046 + 16) = v1043 ^ 0x61;
            *(_DWORD *)(v1046 + 20) = 0;
          }
          v1047 = v2822;
          if ( !*(_DWORD *)(v140 + 880) )
          {
            *(_DWORD *)(v140 + 888) = v1041;
            *(_DWORD *)(v140 + 892) = 0;
            *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
            *(_DWORD *)(v140 + 900) = 0;
            *(_QWORD *)(v140 + 904) = *v2822;
            *(_DWORD *)(v140 + 912) = v1040;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
        }
        v1048 = 0;
        v1049 = 0;
        if ( (v1043 & 7) == 1 )
        {
          v1048 = 48;
        }
        else if ( (v1043 & 7) == 2 )
        {
          v1048 = 16;
          v1049 = 16;
        }
        else if ( (v1043 & 7) != 0 && !*(_DWORD *)(v140 + 880) )
        {
          *(_DWORD *)(v140 + 888) = v140 - 1849117464;
          LODWORD(v1050) = 0;
          HIDWORD(v1050) = (char *)v1047 - 465226731;
          *(_QWORD *)(v140 + 892) = v1050;
          *(_DWORD *)(v140 + 900) = 0;
          *(_QWORD *)(v140 + 904) = *v1047;
          *(_DWORD *)(v140 + 912) = v1040;
          *(_DWORD *)(v140 + 916) = 0;
          *(_DWORD *)(v140 + 880) = 1;
        }
        v1051 = (unsigned __int8 *)(*(_DWORD *)(v140 + 720) + 2 * (v1043 >> 4));
        if ( (*v1051 | v1048) != v1044 && !*(_DWORD *)(v140 + 880) )
        {
          *(_DWORD *)(v140 + 888) = v140 - 1849117464;
          *(_DWORD *)(v140 + 892) = 0;
          *(_DWORD *)(v140 + 896) = (char *)v1047 - 465226731;
          *(_DWORD *)(v140 + 900) = 0;
          *(_QWORD *)(v140 + 904) = *v1047;
          *(_DWORD *)(v140 + 912) = v1040;
          *(_DWORD *)(v140 + 916) = 0;
          *(_DWORD *)(v140 + 880) = 1;
        }
        if ( (v1051[1] | v1049) != v2867 && !*(_DWORD *)(v140 + 880) )
        {
          *(_DWORD *)(v140 + 888) = v1042;
          *(_DWORD *)(v140 + 892) = 0;
          *(_DWORD *)(v140 + 896) = (char *)v1047 - 465226731;
          *(_DWORD *)(v140 + 900) = 0;
          *(_QWORD *)(v140 + 904) = *v1047;
          *(_DWORD *)(v140 + 912) = v1040;
          *(_DWORD *)(v140 + 916) = 0;
          *(_DWORD *)(v140 + 880) = 1;
        }
        if ( v1040 == *(_DWORD *)(v140 + 600) )
          v1052 = 0;
        else
          v1052 = (int *)(*(int (__fastcall **)(int, int))(v140 + 544))(v1040, 1);
        jj = (unsigned int)v1052;
        if ( v1052 )
        {
          v1053 = v1052;
          if ( *v1052 )
          {
            v1054 = v2859;
            do
            {
              *v1053 &= 0xFFFFFFFC;
              (*(void (**)(void))(v140 + 312))();
              v1055 = v1053[1] & 0xFFFF0000;
              if ( v1055 == v1045 )
                v1056 = v1044;
              else
                v1056 = v2867;
              if ( !(*(int (__fastcall **)(unsigned int, int))(v140 + 560))(((unsigned int)v1053[1] >> 6) & 0xF, v1056) )
              {
                v2822[4] = v1055;
                v2822[5] = *v1053;
                *((_BYTE *)v2822 + 24) = ((unsigned int)v1053[1] >> 6) & 0xF;
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v1054;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_QWORD *)(v140 + 904) = *v2822;
                  *(_DWORD *)(v140 + 912) = v1040;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
              }
              v1057 = v1053[8];
              v1053 += 8;
            }
            while ( v1057 );
            goto LABEL_1411;
          }
          goto LABEL_1412;
        }
        goto LABEL_1413;
      }
LABEL_1414:
      v2695 = ++v261;
      v1040 = (*(int (__fastcall **)(int))(v140 + 532))(v1040);
      if ( !v1040 )
      {
        v157 = v2822;
LABEL_1416:
        v1071 = *(_DWORD *)(v140 + 600);
        if ( (*(int (__fastcall **)(int))(v140 + 524))(v1071) >= 0 )
        {
          v1072 = (*(unsigned __int8 (__fastcall **)(int))(v140 + 548))(v1071);
          v1073 = (*(int (__fastcall **)(int, char *))(v140 + 552))(v1071, v2868);
          v2771 = v1073;
          v2859 = (*(int (__fastcall **)(int))(v140 + 556))(v1071);
          if ( v1072 != 98 )
          {
            if ( !*(_DWORD *)(v140 + 880) )
            {
              v1074 = *(_DWORD *)(v140 + 688);
              *(_DWORD *)(v1074 + 16) = v1072 ^ 0x62;
              *(_DWORD *)(v1074 + 20) = 0;
            }
            if ( !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v157;
              *(_DWORD *)(v140 + 912) = v1071;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
          }
          v1075 = 0;
          v1076 = 0;
          if ( (v1072 & 7) == 1 )
          {
            v1075 = 48;
          }
          else if ( (v1072 & 7) == 2 )
          {
            v1075 = 16;
            v1076 = 16;
          }
          else if ( (v1072 & 7) != 0 && !*(_DWORD *)(v140 + 880) )
          {
            *(_DWORD *)(v140 + 888) = v140 - 1849117464;
            *(_DWORD *)(v140 + 892) = 0;
            *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
            *(_DWORD *)(v140 + 900) = 0;
            *(_QWORD *)(v140 + 904) = *v157;
            *(_DWORD *)(v140 + 912) = v1071;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
          v1077 = (unsigned __int8 *)(*(_DWORD *)(v140 + 720) + 2 * (v1072 >> 4));
          if ( (*v1077 | v1075) != v1073 && !*(_DWORD *)(v140 + 880) )
          {
            *(_DWORD *)(v140 + 888) = v140 - 1849117464;
            *(_DWORD *)(v140 + 892) = 0;
            *(_DWORD *)(v140 + 896) = (char *)v157 - 465226731;
            *(_DWORD *)(v140 + 900) = 0;
            *(_QWORD *)(v140 + 904) = *v157;
            *(_DWORD *)(v140 + 912) = v1071;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
          if ( (v1077[1] | v1076) != (unsigned __int8)v2868[0] && !*(_DWORD *)(v140 + 880) )
          {
            *(_QWORD *)(v140 + 888) = v140 - 1849117464;
            *(_QWORD *)(v140 + 896) = (unsigned int)v157 - 465226731;
            *(_QWORD *)(v140 + 904) = *v157;
            *(_DWORD *)(v140 + 912) = v1071;
            *(_DWORD *)(v140 + 916) = 0;
            *(_DWORD *)(v140 + 880) = 1;
          }
          if ( v1071 == *(_DWORD *)(v140 + 600) )
            v1078 = 0;
          else
            v1078 = (int *)(*(int (__fastcall **)(int, int))(v140 + 544))(v1071, 1);
          jj = (unsigned int)v1078;
          if ( v1078 )
          {
            v1079 = v1078;
            if ( *v1078 )
            {
              v1080 = (char *)v157 - 465226731;
              do
              {
                *v1079 &= 0xFFFFFFFC;
                (*(void (**)(void))(v140 + 312))();
                v1081 = v1079[1] & 0xFFFF0000;
                if ( v1081 == v2859 )
                  v1082 = v2771;
                else
                  v1082 = (unsigned __int8)v2868[0];
                if ( !(*(int (__fastcall **)(unsigned int, int))(v140 + 560))(
                        ((unsigned int)v1079[1] >> 6) & 0xF,
                        v1082) )
                {
                  v2822[4] = v1081;
                  v2822[5] = *v1079;
                  *((_BYTE *)v2822 + 24) = ((unsigned int)v1079[1] >> 6) & 0xF;
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = v1080;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_QWORD *)(v140 + 904) = *v2822;
                    *(_DWORD *)(v140 + 912) = v1071;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
                v1083 = v1079[8];
                v1079 += 8;
              }
              while ( v1083 );
              v1078 = (int *)jj;
              v261 = v2695;
            }
            (*(void (__fastcall **)(int *))(v140 + 220))(v1078);
          }
          (*(void (__fastcall **)(int))(v140 + 528))(v1071);
          *(_DWORD *)(v140 + 856) += 0x8000;
        }
        if ( v2755 )
          (*(void (**)(void))(v140 + 312))();
LABEL_307:
        v260 = *(_DWORD *)(v140 + 856) + (v261 << 8);
LABEL_294:
        *(_DWORD *)(v140 + 856) = v260;
        goto LABEL_1564;
      }
    }
    if ( !(*(int (__fastcall **)(int))(v140 + 536))(v1040) || (*(int (__fastcall **)(int))(v140 + 524))(v1040) < 0 )
      goto LABEL_1414;
    v1058 = (*(unsigned __int8 (__fastcall **)(int))(v140 + 548))(v1040);
    v1059 = (*(int (__fastcall **)(int, char *))(v140 + 552))(v1040, v2864);
    v1060 = (*(int (__fastcall **)(int))(v140 + 556))(v1040);
    if ( v1058 == 97 )
    {
      v1062 = v2822;
    }
    else
    {
      if ( !*(_DWORD *)(v140 + 880) )
      {
        v1061 = *(_DWORD *)(v140 + 688);
        *(_DWORD *)(v1061 + 16) = v1058 ^ 0x61;
        *(_DWORD *)(v1061 + 20) = 0;
      }
      v1062 = v2822;
      if ( !*(_DWORD *)(v140 + 880) )
      {
        *(_DWORD *)(v140 + 888) = v140 - 1849117464;
        *(_DWORD *)(v140 + 892) = 0;
        *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
        *(_DWORD *)(v140 + 900) = 0;
        *(_QWORD *)(v140 + 904) = *v2822;
        *(_DWORD *)(v140 + 912) = v1040;
        *(_DWORD *)(v140 + 916) = 0;
        *(_DWORD *)(v140 + 880) = 1;
      }
    }
    v1063 = 0;
    v1064 = 0;
    if ( (v1058 & 7) == 1 )
    {
      v1063 = 48;
    }
    else if ( (v1058 & 7) == 2 )
    {
      v1063 = 16;
      v1064 = 16;
    }
    else if ( (v1058 & 7) != 0 && !*(_DWORD *)(v140 + 880) )
    {
      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
      LODWORD(v1065) = 0;
      HIDWORD(v1065) = (char *)v1062 - 465226731;
      *(_QWORD *)(v140 + 892) = v1065;
      *(_DWORD *)(v140 + 900) = 0;
      *(_QWORD *)(v140 + 904) = *v1062;
      *(_DWORD *)(v140 + 912) = v1040;
      *(_DWORD *)(v140 + 916) = 0;
      *(_DWORD *)(v140 + 880) = 1;
    }
    v1066 = (unsigned __int8 *)(*(_DWORD *)(v140 + 720) + 2 * (v1058 >> 4));
    if ( (*v1066 | v1063) != v1059 && !*(_DWORD *)(v140 + 880) )
    {
      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
      *(_DWORD *)(v140 + 892) = 0;
      *(_DWORD *)(v140 + 896) = (char *)v1062 - 465226731;
      *(_DWORD *)(v140 + 900) = 0;
      *(_QWORD *)(v140 + 904) = *v1062;
      *(_DWORD *)(v140 + 912) = v1040;
      *(_DWORD *)(v140 + 916) = 0;
      *(_DWORD *)(v140 + 880) = 1;
    }
    if ( (v1064 | v1066[1]) != (unsigned __int8)v2864[0] && !*(_DWORD *)(v140 + 880) )
    {
      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
      *(_DWORD *)(v140 + 892) = 0;
      *(_DWORD *)(v140 + 896) = (char *)v1062 - 465226731;
      *(_DWORD *)(v140 + 900) = 0;
      *(_QWORD *)(v140 + 904) = *v1062;
      *(_DWORD *)(v140 + 912) = v1040;
      *(_DWORD *)(v140 + 916) = 0;
      *(_DWORD *)(v140 + 880) = 1;
    }
    if ( v1040 == *(_DWORD *)(v140 + 600) )
      v1052 = 0;
    else
      v1052 = (int *)(*(int (__fastcall **)(int, int))(v140 + 544))(v1040, 1);
    jj = (unsigned int)v1052;
    if ( v1052 )
    {
      v1067 = v1052;
      if ( *v1052 )
      {
        do
        {
          *v1067 &= 0xFFFFFFFC;
          (*(void (**)(void))(v140 + 312))();
          v1068 = v1067[1] & 0xFFFF0000;
          if ( v1068 == v1060 )
            v1069 = v1059;
          else
            v1069 = (unsigned __int8)v2864[0];
          if ( !(*(int (__fastcall **)(unsigned int, int))(v140 + 560))(((unsigned int)v1067[1] >> 6) & 0xF, v1069) )
          {
            v2822[4] = v1068;
            v2822[5] = *v1067;
            *((_BYTE *)v2822 + 24) = ((unsigned int)v1067[1] >> 6) & 0xF;
            if ( !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2822 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2822;
              *(_DWORD *)(v140 + 912) = v1040;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
          }
          v1070 = v1067[8];
          v1067 += 8;
        }
        while ( v1070 );
LABEL_1411:
        v1052 = (int *)jj;
      }
LABEL_1412:
      (*(void (__fastcall **)(int *))(v140 + 220))(v1052);
    }
LABEL_1413:
    (*(void (__fastcall **)(int))(v140 + 528))(v1040);
    v261 = v2695;
    v1039 = v2755;
    v1041 = v2847;
    v1042 = v2845;
    *(_DWORD *)(v140 + 856) += 0x8000;
    goto LABEL_1414;
  }
LABEL_1583:
  v1197 = v2842;
  *(_DWORD *)(v140 + 848) = v147;
  if ( v1197 && ((*(_DWORD *)(v140 + 992) & 0x8000) != 0 || !*(_DWORD *)(v140 + 880)) )
  {
    v1198 = *(_DWORD *)(v140 + 988);
    *(_DWORD *)(v140 + 988) = 0;
    (*(void (__fastcall **)(int, char *))(v140 + 400))(v1198, v2954);
    v1199 = *(_DWORD *)(v140 + 992);
    if ( (v1199 & 1) != 0 )
    {
      *(_DWORD *)(v140 + 992) = v1199 & 0xFFFFFFFE;
      v1198 = (*(int (__fastcall **)(int))(v140 + 388))(v1198);
      if ( v1198 )
        *(_DWORD *)(v140 + 976) = (*(int (**)(void))(v140 + 404))();
      else
        *(_DWORD *)(v140 + 976) = -1;
    }
    if ( v1198 )
      (*(void (__fastcall **)(int))(v140 + 392))(v1198);
  }
  if ( (*(_DWORD *)(v140 + 992) & 8) != 0 && (v1200 = *(_DWORD *)(v140 + 996), (v1200 & 4) != 0) )
  {
    v2742 = *(_DWORD *)(v140 + 796);
    v1201 = *(_DWORD *)(v140 + 1048);
    v1202 = *(_DWORD *)(v140 + 824);
    v2775 = *(_DWORD *)(v140 + 1076);
    jj = (*(_DWORD *)(v140 + 996) & 1) != 0;
    if ( (v1200 & 1) != 0 )
      v1201 = *(_DWORD *)(v140 + 728);
    v2842 = *(_DWORD *)(v140 + 268);
    v2847 = *(_DWORD *)(v140 + 572);
    v2845 = *(_DWORD *)(v140 + 416);
    v2859 = *(_DWORD *)(v140 + 476);
    v1203 = __mrc(15, 0, 9, 13, 0);
    v1204 = v1203 << 29;
    v1205 = v1203 ^ (v1203 >> 3);
    v1206 = 67117057i64 * (unsigned int)v1205;
    v1207 = 1880096896i64 * (unsigned int)v1205 + 67117057i64 * v1204;
    v1208 = (1880096896i64 * v1204 + (unsigned __int64)HIDWORD(v1207)) >> 32;
    v1209 = 1880096896 * v1204 + HIDWORD(v1207);
    if ( (unsigned int)(v1207 + HIDWORD(v1206)) < HIDWORD(v1206) )
      v1208 = (__PAIR64__(v1208, v1209++) + 1) >> 32;
    LODWORD(v1210) = v1206 ^ v1209;
    HIDWORD(v1210) = (v1207 + HIDWORD(v1206)) ^ v1208;
    v2903 = -6000000000i64 - FsRtlRemovePerStreamContextEx(100000000i64, v1210);
    if ( (*(_DWORD *)(v140 + 992) & 0x4000000) != 0 )
    {
      v1211 = __mrc(15, 0, 9, 13, 0);
      v1212 = v1211 << 29;
      v1213 = v1211 ^ (v1211 >> 3);
      v1214 = 67117057i64 * (unsigned int)v1213;
      v1215 = 1880096896i64 * (unsigned int)v1213 + 67117057i64 * v1212;
      v1216 = (1880096896i64 * v1212 + (unsigned __int64)HIDWORD(v1215)) >> 32;
      v1217 = 1880096896 * v1212 + HIDWORD(v1215);
      if ( (unsigned int)(v1215 + HIDWORD(v1214)) < HIDWORD(v1214) )
        v1216 = (__PAIR64__(v1216, v1217++) + 1) >> 32;
      LODWORD(v1218) = v1214 ^ v1217;
      HIDWORD(v1218) = (v1215 + HIDWORD(v1214)) ^ v1216;
      if ( (unsigned __int64)FsRtlRemovePerStreamContextEx(10i64, v1218) < 2 )
      {
        v1219 = __mrc(15, 0, 9, 13, 0);
        v1220 = v1219 << 29;
        v1221 = v1219 ^ (v1219 >> 3);
        v1222 = 67117057i64 * (unsigned int)v1221;
        v1223 = 1880096896i64 * (unsigned int)v1221 + 67117057i64 * v1220;
        v1224 = (1880096896i64 * v1220 + (unsigned __int64)HIDWORD(v1223)) >> 32;
        v1225 = 1880096896 * v1220 + HIDWORD(v1223);
        if ( (unsigned int)(v1223 + HIDWORD(v1222)) < HIDWORD(v1222) )
          v1224 = (__PAIR64__(v1224, v1225++) + 1) >> 32;
        LODWORD(v1226) = v1222 ^ v1225;
        HIDWORD(v1226) = (v1223 + HIDWORD(v1222)) ^ v1224;
        v1227 = FsRtlRemovePerStreamContextEx(10i64, v1226);
        HIDWORD(v1227) = ((unsigned __int64)(v1227 + 1) >> 32) * v2903 + (v1227 + 1) * HIDWORD(v2903);
        v1228 = (unsigned int)(v1227 + 1) * (unsigned __int64)(unsigned int)v2903;
        LODWORD(v2903) = (v1227 + 1) * v2903;
        HIDWORD(v2903) = HIDWORD(v1227) + HIDWORD(v1228);
      }
    }
    v1229 = *(_DWORD *)(v140 + 992);
    v1230 = 0;
    v1231 = 0;
    v1232 = 0;
    v1233 = 0;
    if ( (v1229 & 2) == 0 )
      v2742 = v1202;
    v2812 = (*(_DWORD *)(v140 + 992) & 0x80) != 0;
    if ( ((v1229 & v2863) == 0 || (v1229 & 0x100000) == 0) && (v1229 & 0x10) != 0 )
    {
      (*(void (__fastcall **)(char *, _DWORD))(v140 + 300))(v2966, *(_DWORD *)(v140 + 924));
      v1234 = (*(int (__fastcall **)(char *, _DWORD))(v140 + 304))(v2966, 0);
      __disable_irq();
      v1235 = __mrc(14, 0, 0, 2, 2);
      if ( (*(_DWORD *)(v140 + 992) & 0x20) != 0 )
        v1235 |= 0x8000u;
      __mcr(14, 0, v1235, 0, 2, 2);
      __enable_irq();
      (*(void (__fastcall **)(int))(v140 + 296))(v1234);
      *(_DWORD *)(v140 + 992) &= 0xFFFFFFDF;
      *(_DWORD *)(v140 + 924) = -1;
    }
    if ( v2812 )
    {
      v1236 = __mrc(15, 0, 9, 13, 0);
      v1237 = v1236 << 29;
      v1238 = v1236 ^ (v1236 >> 3);
      v1239 = 67117057i64 * (unsigned int)v1238;
      v1240 = 1880096896 * v1238 + 67117057 * v1237;
      v1241 = (1880096896i64 * v1237 + ((1880096896i64 * (unsigned int)v1238 + 67117057 * (unsigned __int64)v1237) >> 32)) >> 32;
      v1242 = 1880096896 * v1237 + ((1880096896i64 * (unsigned int)v1238 + 67117057 * (unsigned __int64)v1237) >> 32);
      v1243 = v1240 + HIDWORD(v1239);
      if ( (unsigned int)(v1240 + HIDWORD(v1239)) < HIDWORD(v1239) )
        v1241 = (__PAIR64__(v1241, v1242++) + 1) >> 32;
      v1231 = v1239 ^ v1242;
      v1232 = v1243 ^ v1241;
      v1244 = (int *)(v140 + 1104);
      v1245 = v1239 ^ v1242;
      v1230 = v140 ^ v1239 ^ v1242;
      v1233 = v1232;
      v1246 = 276;
      do
      {
        v1247 = *--v1244;
        v1248 = v1247 ^ v1245;
        v1245 = __ROR4__(v1245, v1246);
        *v1244 = v1248;
        --v1246;
      }
      while ( v1246 );
      v1249 = (unsigned int)(v1202 - 1104) >> 2;
      if ( v1249 )
      {
        v1250 = v140 + 1104 + 4 * v1249;
        do
        {
          v1251 = *(_DWORD *)(v1250 - 4);
          v1250 -= 4;
          v1233 = (v1230 >> 31) | (2 * v1233);
          v1230 = __ROR4__(v1251, v1249--) ^ (2 * v1230);
        }
        while ( v1249 );
      }
      v1252 = (unsigned int)(v2742 - v1202) >> 2;
      if ( v1252 )
      {
        v1253 = (int *)(v1202 + v140 + 4 * v1252);
        do
        {
          v1254 = *--v1253;
          v1255 = v1254 ^ v1245;
          v1245 = __ROR4__(v1245, v1252);
          *v1253 = v1255;
          --v1252;
        }
        while ( v1252 );
      }
    }
    if ( v2775 )
    {
      v1256 = v2742;
      ((void (__fastcall *)(unsigned int, int, __int64 *, unsigned int, int))v2859)(v140, v2742, &v2903, v2842, v2775);
    }
    else
    {
      if ( v1201 )
      {
        if ( !((int (__fastcall *)(int, _DWORD, _DWORD, _DWORD, __int64 *))v2845)(v1201, 0, 0, 0, &v2903) && jj )
          ((void (__fastcall *)(int, _DWORD, _DWORD))v2847)(v1201, 0, 0);
      }
      else
      {
        ((void (__fastcall *)(_DWORD, _DWORD, __int64 *))v2842)(0, 0, &v2903);
      }
      v1256 = v2742;
    }
    if ( v2812 )
    {
      v1257 = (int *)(v140 + 1104);
      v1258 = v140 ^ v1231;
      v1259 = 276;
      do
      {
        v1260 = *--v1257;
        v1261 = v1260 ^ v1231;
        v1231 = __ROR4__(v1231, v1259);
        *v1257 = v1261;
        --v1259;
      }
      while ( v1259 );
      v1262 = (unsigned int)(v1202 - 1104) >> 2;
      if ( v1262 )
      {
        v1263 = v140 + 1104 + 4 * v1262;
        do
        {
          v1264 = *(_DWORD *)(v1263 - 4);
          v1263 -= 4;
          v1232 = (v1258 >> 31) | (2 * v1232);
          v1258 = __ROR4__(v1264, v1262--) ^ (2 * v1258);
        }
        while ( v1262 );
      }
      v1265 = (unsigned int)(v1256 - v1202) >> 2;
      if ( v1265 )
      {
        v1266 = (int *)(v1202 + v140 + 4 * v1265);
        do
        {
          v1267 = *--v1266;
          v1268 = v1267 ^ v1231;
          v1231 = __ROR4__(v1231, v1265);
          *v1266 = v1268;
          --v1265;
        }
        while ( v1265 );
      }
      if ( v1258 != v1230 || v1232 != v1233 )
      {
        v1269 = *(unsigned int **)(v140 + 688);
        v1270 = *(_DWORD *)(v140 + 796);
        *v1269 = v140;
        v1269[2] = v1270;
        if ( !*(_DWORD *)(v140 + 880) )
        {
          v1271 = *(_DWORD *)(v140 + 688);
          *(_DWORD *)(v1271 + 16) = v1258 ^ v1230;
          *(_DWORD *)(v1271 + 20) = v1232 ^ v1233;
        }
        if ( !*(_DWORD *)(v140 + 880) )
        {
          *(_QWORD *)(v140 + 888) = v140 - 1849117464;
          *(_DWORD *)(v140 + 896) = 0;
          *(_DWORD *)(v140 + 900) = 0;
          *(_QWORD *)(v140 + 904) = 270i64;
          *(_DWORD *)(v140 + 912) = v1258;
          *(_DWORD *)(v140 + 916) = 0;
          *(_DWORD *)(v140 + 880) = 1;
        }
      }
    }
    v1272 = *(_DWORD *)(v140 + 992);
    v1273 = v2863;
    if ( ((v1272 & v2863) == 0 || (v1272 & 0x100000) == 0) && (v1272 & 0x10) != 0 )
    {
      __disable_irq();
      v1274 = __mrc(14, 0, 0, 2, 2);
      if ( *(_DWORD *)(v140 + 924) == -1
        && (*(_DWORD *)(v140 + 992) ^= ((unsigned __int8)*(_DWORD *)(v140 + 992) ^ (unsigned __int8)(32 * ((v1274 & 0x8000) != 0))) & 0x20,
            *(_DWORD *)(v140 + 924) == -1)
        || *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) == *(_DWORD *)(v140 + 924) )
      {
        __mcr(14, 0, v1274 & 0xFFFF7FFF, 0, 2, 2);
        __isb(0xFu);
      }
      if ( *(_DWORD *)(v140 + 924) == -1 )
        *(_DWORD *)(v140 + 924) = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
      __enable_irq();
    }
  }
  else
  {
    v1273 = v2863;
  }
  v1275 = *(_DWORD *)(v140 + 952);
  if ( v1275 == 6 || v1275 == 1 )
    goto LABEL_2668;
  if ( !*(_DWORD *)(v140 + 880) )
  {
    v1276 = *(_QWORD *)*(_DWORD *)(v140 + 960);
    __dmb(0xBu);
    if ( v1276 == *(_QWORD *)(v140 + 968) )
    {
      if ( (*(_DWORD *)(v140 + 864) & 1) != 0 )
      {
        v1277 = *(_DWORD *)(v140 + 976) == -1 ? 0 : (*(int (**)(void))(v140 + 384))();
        if ( v1277 || (v1277 = (*(int (__fastcall **)(_DWORD))(v140 + 388))(0)) != 0 )
        {
          v1278 = (*(int (__fastcall **)(int, char *))(v140 + 396))(v1277, v2954);
          if ( v1278 >= 0 )
          {
            *(_DWORD *)(v140 + 988) = v1277;
            *(_DWORD *)(v140 + 856) += v1273;
            v1278 = 0;
          }
          else
          {
            (*(void (__fastcall **)(int))(v140 + 392))(v1277);
          }
          if ( v1278 >= 0 )
          {
            v1279 = *(_QWORD *)*(_DWORD *)(v140 + 960);
            __dmb(0xBu);
            if ( v1279 == *(_QWORD *)(v140 + 968) )
            {
              if ( *(_DWORD *)(*(_DWORD *)(v140 + 676) + 24) )
              {
                __dmb(0xFu);
                v1280 = *(_QWORD *)*(_DWORD *)(v140 + 960);
                __dmb(0xBu);
                if ( v1280 == *(_QWORD *)(v140 + 968) )
                {
                  v1281 = *(_QWORD *)*(_DWORD *)(v140 + 960);
                  __dmb(0xBu);
                  if ( !*(_DWORD *)(v140 + 880) )
                    *(_QWORD *)(*(_DWORD *)(v140 + 688) + 16) = v1281 ^ *(_QWORD *)(v140 + 968);
                  v1282 = *(_DWORD *)(v140 + 968);
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = 0;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_DWORD *)(v140 + 904) = 259;
                    *(_DWORD *)(v140 + 908) = 0;
                    *(_DWORD *)(v140 + 912) = v1282;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
              }
            }
            if ( (*(_DWORD *)(v140 + 992) & 0x8000) != 0 || !*(_DWORD *)(v140 + 880) )
            {
              v1283 = *(_DWORD *)(v140 + 988);
              *(_DWORD *)(v140 + 988) = 0;
              (*(void (__fastcall **)(int, char *))(v140 + 400))(v1283, v2954);
              v1284 = *(_DWORD *)(v140 + 992);
              if ( (v1284 & 1) != 0 )
              {
                *(_DWORD *)(v140 + 992) = v1284 & 0xFFFFFFFE;
                v1283 = (*(int (__fastcall **)(int))(v140 + 388))(v1283);
                if ( v1283 )
                  *(_DWORD *)(v140 + 976) = (*(int (**)(void))(v140 + 404))();
                else
                  *(_DWORD *)(v140 + 976) = -1;
              }
              if ( v1283 )
                (*(void (__fastcall **)(int))(v140 + 392))(v1283);
            }
          }
        }
      }
      goto LABEL_2668;
    }
    v1285 = *(_DWORD *)(v140 + 976);
    v1286 = (_BYTE *)v140;
    v2850 = (_DWORD *)v140;
    if ( v1285 == -1 )
      v1287 = 0;
    else
      v1287 = (*(int (__fastcall **)(int, _DWORD))(v140 + 384))(v1285, HIDWORD(v1276));
    if ( !v1287 )
    {
      v1287 = (*(int (__fastcall **)(_DWORD))(v140 + 388))(0);
      if ( !v1287 )
        goto LABEL_2668;
    }
    v1288 = (*(int (__fastcall **)(int, char *))(v140 + 396))(v1287, v2954);
    if ( v1288 >= 0 )
    {
      *(_DWORD *)(v140 + 988) = v1287;
      *(_DWORD *)(v140 + 856) += v1273;
      v1288 = 0;
    }
    else
    {
      (*(void (__fastcall **)(int))(v140 + 392))(v1287);
    }
    if ( v1288 < 0 )
      goto LABEL_2668;
    if ( (*(int (__fastcall **)(_DWORD))(v140 + 404))(*(_DWORD *)(v140 + 988)) )
      goto LABEL_2033;
    v1290 = *(_DWORD *)(v140 + 960);
    v1291 = 0;
    v1292 = (unsigned int *)(*(_DWORD *)(v140 + 676) + 16);
    v1293 = *v1292;
    v2847 = (unsigned int)v1292;
    v1294 = v1292[2];
    v2845 = v1293;
    v1295 = (_DWORD *)v1293;
    v1296 = 4 * v1294;
    v1297 = 4 * v1294 + v1293;
    v2841 = v1294;
    v1298 = (char *)v1293;
    if ( v1293 < v1297 )
    {
      do
      {
        __pld(v1298);
        v1298 += 128;
      }
      while ( (unsigned int)v1298 < v1297 );
    }
    v1299 = v1290 & 0x3F;
    v2776 = v1290 & 0x3F;
    if ( v1296 >= 8 )
    {
      v1300 = v1290 & 0x3F;
      v1301 = 64 - (v1290 & 0x3F);
      v1302 = 32 - (v1290 & 0x3F);
      v1303 = (v1290 & 0x3F) - 32;
      v1304 = v1296 >> 3;
      do
      {
        v1296 -= 8;
        LODWORD(v1305) = v1290 ^ *v1295;
        v1306 = v1295[1];
        v1295 += 2;
        HIDWORD(v1305) = v1291 ^ v1306;
        v1307 = v1305 >> v1301;
        v1291 = (HIDWORD(v1305) << v1300) | ((unsigned int)v1305 >> v1302) | ((_DWORD)v1305 << v1303) | (HIDWORD(v1305) >> v1301);
        v1290 = ((_DWORD)v1305 << v1300) | v1307;
        v1303 = v1300 - 32;
        --v1304;
      }
      while ( v1304 );
      v140 = (unsigned int)v2734;
      v1286 = v2850;
      v1299 = v2776;
    }
    if ( v1296 )
    {
      v1308 = v1299 & 0x3F;
      v1309 = 64 - (v1299 & 0x3F);
      v1310 = 32 - (v1299 & 0x3F);
      v1311 = (v1299 & 0x3F) - 32;
      do
      {
        v1312 = *(unsigned __int8 *)v1295;
        v1295 = (_DWORD *)((char *)v1295 + 1);
        v1313 = v1290 ^ v1312;
        v1314 = __PAIR64__(v1291, v1313) >> v1309;
        v1291 = (v1291 << v1308) | (v1313 >> v1310) | (v1313 << v1311) | (v1291 >> v1309);
        v1290 = (v1313 << v1308) | v1314;
        --v1296;
      }
      while ( v1296 );
      v140 = (unsigned int)v2734;
      v1286 = v2850;
    }
    v1315 = *(_DWORD **)(v2847 + 12);
    v1316 = v1290 ^ *(_DWORD *)(v140 + 968);
    v1317 = v1291 ^ *(_DWORD *)(v140 + 972);
    v2852 = v1317;
    v1318 = (char *)v1315;
    if ( v1315 < (_DWORD *)((char *)v1315 + v2841) )
    {
      do
      {
        __pld(v1318);
        v1318 += 128;
      }
      while ( v1318 < (char *)v1315 + v2841 );
    }
    v1319 = v1316 & 0x3F;
    v2777 = v1316 & 0x3F;
    v1320 = v2841;
    if ( v2841 >= 8 )
    {
      v1321 = v1316 & 0x3F;
      v1322 = v2841 >> 3;
      v1323 = 64 - (v1316 & 0x3F);
      v1324 = 32 - (v1316 & 0x3F);
      v1325 = (v1316 & 0x3F) - 32;
      do
      {
        v1320 -= 8;
        v1326 = v1316 ^ *v1315;
        v1327 = v1315[1];
        v1315 += 2;
        v1328 = v2852 ^ v1327;
        v1329 = ((v2852 ^ v1327) << v1321) | (v1326 >> v1324) | (v1326 << v1325);
        v1330 = __PAIR64__(v2852 ^ v1327, v1326) >> v1323;
        v1331 = v1326 << v1321;
        v1317 = v1329 | (v1328 >> v1323);
        v1316 = v1331 | v1330;
        v2852 = v1317;
        --v1322;
        v1325 = v1321 - 32;
      }
      while ( v1322 );
      v140 = (unsigned int)v2734;
      v1286 = v2850;
      v1319 = v2777;
    }
    if ( v1320 )
    {
      v1332 = v1319 & 0x3F;
      v1333 = 64 - (v1319 & 0x3F);
      v1334 = (v1319 & 0x3F) - 32;
      v1335 = 32 - (v1319 & 0x3F);
      do
      {
        v1336 = *(unsigned __int8 *)v1315;
        v1315 = (_DWORD *)((char *)v1315 + 1);
        v1337 = v1316 ^ v1336;
        v1338 = (v2852 >> (v1333 - 32)) | (v1337 >> v1333) | (v2852 << v1334);
        v1317 = (v1317 << v1332) | (v1337 >> v1335) | (v1337 << v1334) | (v2852 >> v1333);
        v2852 = v1317;
        v1316 = (v1337 << v1332) | v1338;
        --v1320;
      }
      while ( v1320 );
      v140 = (unsigned int)v2734;
      v1286 = v2850;
    }
    v1339 = v2845;
    v1340 = v2841;
    v1341 = v2841 ^ v2845 ^ v1316;
    v1342 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v140 + 328);
    jj = v1341;
    if ( !v1342(v2845, &v2941, v2957) )
      goto LABEL_1865;
    v1343 = __mrc(15, 0, 9, 13, 0);
    v1344 = v1343 << 29;
    v1345 = v1343 ^ (v1343 >> 3);
    v1346 = 67117057i64 * (unsigned int)v1345;
    v1347 = 1880096896i64 * (unsigned int)v1345 + 67117057i64 * v1344;
    v1348 = (1880096896i64 * v1344 + (unsigned __int64)HIDWORD(v1347)) >> 32;
    v1349 = 1880096896 * v1344 + HIDWORD(v1347);
    if ( (unsigned int)(v1347 + HIDWORD(v1346)) < HIDWORD(v1346) )
      v1348 = (__PAIR64__(v1348, v1349++) + 1) >> 32;
    LODWORD(v1350) = v1346 ^ v1349;
    HIDWORD(v1350) = (v1347 + HIDWORD(v1346)) ^ v1348;
    switch ( (unsigned int)FsRtlRemovePerStreamContextEx(11i64, v1350) )
    {
      case 0u:
        if ( !FsRtlRemovePerStreamContextEx(3i64, 0i64) )
        {
          v2895 = -795291432;
          v1352 = -795291432;
          goto LABEL_1724;
        }
        v2895 = 1665295171;
        v1351 = 1665295171;
        goto LABEL_1779;
      case 1u:
        v1354 = FsRtlRemovePerStreamContextEx(3i64, 1ui64);
        if ( !v1354 )
        {
          v2894 = -1262057781;
          v1352 = -1262057782;
          goto LABEL_1731;
        }
        if ( v1354 == 1 )
        {
          v1353 = 31;
          v2894 = -1297272415;
          v1352 = -1297272415;
          goto LABEL_1725;
        }
        v2894 = -894122362;
        v1352 = -894122362;
        goto LABEL_1775;
      case 2u:
        v1355 = FsRtlRemovePerStreamContextEx(3i64, 2ui64);
        if ( v1355 )
        {
          if ( v1355 == 1 )
          {
            v2892 = -665102064;
            v1352 = -665102064;
            goto LABEL_1769;
          }
          v1353 = 2;
          v2892 = -2051698419;
          v1352 = -2051698419;
        }
        else
        {
          v1353 = 12;
          v2892 = -700172780;
          v1352 = -700172778;
        }
        goto LABEL_1725;
      case 3u:
        v1356 = FsRtlRemovePerStreamContextEx(3i64, 3ui64);
        if ( v1356 )
        {
          if ( v1356 == 1 )
          {
            v2876 = -1907430904;
            v1351 = __ROR4__(-1907430904, 29);
            goto LABEL_1779;
          }
          v1353 = 3;
          v2876 = -1816493533;
          v1352 = -1816493533;
        }
        else
        {
          v1353 = 15;
          v2876 = -1474152136;
          v1352 = -1474152133;
        }
        goto LABEL_1725;
      case 4u:
        v1357 = FsRtlRemovePerStreamContextEx(3i64, 4ui64);
        if ( v1357 )
        {
          if ( v1357 == 1 )
          {
            v2889 = 1728537748;
            v1351 = __ROR4__(1728537748, 28);
            goto LABEL_1779;
          }
          v1353 = 4;
          v2889 = 124032103;
          v1352 = 124032103;
        }
        else
        {
          v1353 = 18;
          v2889 = 622445021;
          v1352 = 622445017;
        }
        goto LABEL_1725;
      case 5u:
        v1358 = FsRtlRemovePerStreamContextEx(3i64, 5ui64);
        if ( !v1358 )
        {
          v2877 = 1240279177;
          v1351 = __ROR4__(1240279180, 21);
          goto LABEL_1779;
        }
        if ( v1358 == 1 )
        {
          v2877 = 2068456210;
          v1359 = 2068456210;
          goto LABEL_1763;
        }
        v1353 = 5;
        v2877 = 680282605;
        v1352 = 680282605;
        goto LABEL_1725;
      case 6u:
        v1360 = FsRtlRemovePerStreamContextEx(3i64, 6ui64);
        if ( !v1360 )
        {
          v2878 = 1314342514;
          v1361 = 1314342516;
          goto LABEL_1757;
        }
        if ( v1360 == 1 )
        {
          v2878 = 962402769;
          v1351 = __ROR4__(962402769, 26);
          goto LABEL_1779;
        }
        v2878 = -778234987;
        v1352 = -778234987;
LABEL_1724:
        v1353 = 6;
        goto LABEL_1725;
      case 7u:
        v1362 = FsRtlRemovePerStreamContextEx(3i64, 7ui64);
        if ( !v1362 )
        {
          v2880 = 186293093;
          v1359 = 186293090;
LABEL_1763:
          v1351 = __ROR4__(v1359, 27);
          goto LABEL_1779;
        }
        if ( v1362 == 1 )
        {
          v2880 = -2100910376;
          v1351 = __ROR4__(-2100910376, 25);
          goto LABEL_1779;
        }
        v1353 = 7;
        v2880 = -1447681871;
        v1352 = -1447681871;
        goto LABEL_1725;
      case 8u:
        v1363 = FsRtlRemovePerStreamContextEx(3i64, 8ui64);
        if ( !v1363 )
        {
          v2885 = 1352210840;
          v1352 = 1352210832;
LABEL_1769:
          v1353 = 30;
          goto LABEL_1725;
        }
        if ( v1363 != 1 )
        {
          v1353 = 8;
          v2885 = 1684422978;
          v1352 = 1684422978;
          goto LABEL_1725;
        }
        v2885 = 1094870118;
        v1361 = 1094870118;
LABEL_1757:
        v1351 = __ROR4__(v1361, 24);
        goto LABEL_1779;
      case 9u:
        v1364 = FsRtlRemovePerStreamContextEx(3i64, 9ui64);
        if ( v1364 )
        {
          if ( v1364 == 1 )
          {
            v2883 = -1557388889;
            v1351 = __ROR4__(-1557388889, 23);
LABEL_1779:
            v1375 = (_DWORD *)(*(int (__fastcall **)(int, int, int))(v140 + 216))(512, 64, v1351);
            v1376 = v1375;
            v2802 = v1375;
            if ( !v1375 )
              goto LABEL_2033;
            v1377 = 64;
            v1378 = v1375;
            v1379 = 16;
            do
            {
              v1377 -= 4;
              --v1379;
              *v1378++ = 0;
            }
            while ( v1379 );
            for ( ; v1377; --v1377 )
            {
              *(_BYTE *)v1378 = 0;
              v1378 = (_DWORD *)((char *)v1378 + 1);
            }
            v1380 = __PAIR64__(v2852, v1341);
            v1381 = 0;
            v2875 = v2941;
            *v1375 = v2941;
            v2824 = v1341;
            v2743 = HIDWORD(v1380);
            v2853 = 0;
            while ( 1 )
            {
              v2875 = v1376[v1381];
              if ( !v2875 )
                goto LABEL_1860;
              v1382 = (*(int (**)(void))(v140 + 324))();
              v2835 = v1382;
              if ( !v1382 )
              {
                v1317 = v2852;
                v1341 = jj;
                if ( !*(_DWORD *)(v140 + 880) )
                {
                  *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                  *(_DWORD *)(v140 + 892) = 0;
                  *(_DWORD *)(v140 + 896) = 0;
                  *(_DWORD *)(v140 + 900) = 0;
                  *(_DWORD *)(v140 + 904) = 258;
                  *(_DWORD *)(v140 + 908) = 0;
                  *(_DWORD *)(v140 + 912) = -1073741701;
                  *(_DWORD *)(v140 + 916) = 0;
                  *(_DWORD *)(v140 + 880) = 1;
                }
                goto LABEL_1861;
              }
              v1383 = v2875;
              v1384 = (_DWORD *)(*(unsigned __int16 *)(v1382 + 20) + v1382 + 24);
              v2813 = v1384;
              v2696 = v2875;
              v2756 = &v1384[10 * *(unsigned __int16 *)(v1382 + 6)];
              v1385 = v1380 & 0x3F;
              v2857 = 32 - v1385;
              v1386 = v1385 - 32;
              v2859 = v1385;
              v2725 = v1385 - 32;
              v2846 = 64 - v1385;
              v2842 = v1385;
              v1387 = v1380 & 0x3F;
              do
              {
                if ( (v1384[9] & v2871) != 0 || *v1384 == 1414090313 && v1384[1] == 1195525195 )
                  goto LABEL_1823;
                if ( *v1384 == 1162297680 )
                {
                  v1388 = *((unsigned __int16 *)v1384 + 2);
                  if ( v1388 == 30839 || v1388 == 29303 || v1388 == 30583 )
                    goto LABEL_1823;
                }
                v1390 = *(int **)(v140 + 940);
                v1389 = *(int **)(v140 + 936);
                v1392 = *(int **)(v140 + 948);
                v1391 = *(int **)(v140 + 944);
                v1393 = 7;
                v1394 = v1384;
                do
                {
                  v1396 = *v1394++;
                  v1395 = v1396;
                  v1397 = *v1389++;
                  if ( v1395 != v1397 )
                    goto LABEL_1802;
                  v1393 -= 4;
                }
                while ( v1393 >= 4 );
                if ( !v1393 )
                  goto LABEL_1822;
                while ( 1 )
                {
                  v1399 = *(unsigned __int8 *)v1394;
                  v1394 = (int *)((char *)v1394 + 1);
                  v1398 = v1399;
                  v1400 = *(unsigned __int8 *)v1389;
                  v1389 = (int *)((char *)v1389 + 1);
                  if ( v1398 != v1400 )
                    break;
                  if ( !--v1393 )
                    goto LABEL_1822;
                }
LABEL_1802:
                v1401 = 8;
                v1402 = v1384;
                do
                {
                  v1404 = *v1402++;
                  v1403 = v1404;
                  v1405 = *v1390++;
                  if ( v1403 != v1405 )
                    goto LABEL_1809;
                  v1401 -= 4;
                }
                while ( v1401 >= 4 );
                if ( !v1401 )
                  goto LABEL_1822;
                while ( 1 )
                {
                  v1407 = *(unsigned __int8 *)v1402;
                  v1402 = (int *)((char *)v1402 + 1);
                  v1406 = v1407;
                  v1408 = *(unsigned __int8 *)v1390;
                  v1390 = (int *)((char *)v1390 + 1);
                  if ( v1406 != v1408 )
                    break;
                  if ( !--v1401 )
                    goto LABEL_1822;
                }
LABEL_1809:
                v1409 = 4;
                v1410 = v1384;
                do
                {
                  v1412 = *v1410++;
                  v1411 = v1412;
                  v1413 = *v1391++;
                  if ( v1411 != v1413 )
                    goto LABEL_1816;
                  v1409 -= 4;
                }
                while ( v1409 >= 4 );
                if ( !v1409 )
                  goto LABEL_1822;
                while ( 1 )
                {
                  v1415 = *(unsigned __int8 *)v1410;
                  v1410 = (int *)((char *)v1410 + 1);
                  v1414 = v1415;
                  v1416 = *(unsigned __int8 *)v1391;
                  v1391 = (int *)((char *)v1391 + 1);
                  if ( v1414 != v1416 )
                    break;
                  if ( !--v1409 )
                    goto LABEL_1822;
                }
LABEL_1816:
                v1417 = 6;
                v1418 = v1384;
                do
                {
                  v1420 = *v1418++;
                  v1419 = v1420;
                  v1421 = *v1392++;
                  if ( v1419 != v1421 )
                    goto LABEL_1853;
                  v1417 -= 4;
                }
                while ( v1417 >= 4 );
                if ( !v1417 )
                {
LABEL_1822:
                  v1383 = v2875;
                  v1380 = __PAIR64__(v2743, v2824);
                  v1386 = v2725;
                  v2696 = v2875;
LABEL_1823:
                  v1425 = 1;
                  goto LABEL_1824;
                }
                while ( 1 )
                {
                  v1423 = *(unsigned __int8 *)v1418;
                  v1418 = (int *)((char *)v1418 + 1);
                  v1422 = v1423;
                  v1424 = *(unsigned __int8 *)v1392;
                  v1392 = (int *)((char *)v1392 + 1);
                  if ( v1422 != v1424 )
                    break;
                  if ( !--v1417 )
                    goto LABEL_1822;
                }
LABEL_1853:
                v1383 = v2875;
                v1425 = 0;
                v1380 = __PAIR64__(v2743, v2824);
                v1386 = v2725;
                v2696 = v2875;
LABEL_1824:
                v1426 = v1384[4];
                if ( (int)v1384[9] < 0 )
                  v1425 = 1;
                if ( v1426 <= v1384[2] )
                  v1426 = v1384[2];
                v1427 = v1384[3];
                v1428 = v1426 + v1427;
                if ( !v1425 )
                {
                  v1429 = v1428 - v1427;
                  v1430 = (_DWORD *)(v1427 + v1383);
                  v1431 = v1383 + v1428;
                  for ( kk = (char *)(v1427 + v1383); (unsigned int)kk < v1431; kk += 128 )
                    __pld(kk);
                  v2743 = HIDWORD(v1380);
                  v2824 = v1380;
                  if ( v1429 >= 8 )
                  {
                    v1433 = v1429 >> 3;
                    do
                    {
                      v1429 -= 8;
                      LODWORD(v1380) = v1380 ^ *v1430;
                      v1434 = v1430[1];
                      v1430 += 2;
                      HIDWORD(v1380) ^= v1434;
                      v1435 = v1380 >> v2846;
                      HIDWORD(v1380) = (HIDWORD(v1380) << v2859) | ((unsigned int)v1380 >> v2857) | ((_DWORD)v1380 << v1386) | (HIDWORD(v1380) >> v2846);
                      v1386 = v2859 - 32;
                      LODWORD(v1380) = ((_DWORD)v1380 << v2859) | v1435;
                      --v1433;
                    }
                    while ( v1433 );
                    v140 = (unsigned int)v2734;
                    v1384 = v2813;
                    v1383 = v2696;
                    v1387 = v2842;
                    v2743 = HIDWORD(v1380);
                    v2824 = v1380;
                  }
                  if ( v1429 )
                  {
                    v1436 = 64 - v1387;
                    do
                    {
                      v1437 = *(unsigned __int8 *)v1430;
                      v1430 = (_DWORD *)((char *)v1430 + 1);
                      v2824 = ((v1380 ^ v1437) >> v1436) | ((v1437 ^ (unsigned int)v1380) << v1387);
                      HIDWORD(v1380) = (HIDWORD(v1380) << v1387) | ((v1437 ^ (unsigned int)v1380) >> (32 - v1387)) | ((v1437 ^ (unsigned int)v1380) << (v1387 - 32)) | (HIDWORD(v1380) >> v1436);
                      LODWORD(v1380) = v2824;
                      --v1429;
                    }
                    while ( v1429 );
                    v140 = (unsigned int)v2734;
                    v1384 = v2813;
                    v1383 = v2696;
                    v2743 = HIDWORD(v1380);
                  }
                }
                v1384 += 10;
                LODWORD(v1380) = v2824;
                v1386 = v2725;
                v2813 = v1384;
              }
              while ( v1384 != v2756 );
              v1438 = v2853;
              v1286 = v2850;
              if ( !v2853 )
              {
                v1439 = *(_DWORD *)(v2835 + 132);
                if ( v1439 >= 0x14 )
                {
                  v1440 = *(_DWORD *)(v2835 + 128);
                  v1441 = v1439 + v1440;
                  v1442 = v1441 + v1383;
                  v1443 = v1440 + v1383;
                  if ( v1440 + v1383 != v1441 + v1383 )
                  {
                    do
                    {
                      if ( !*(_DWORD *)(v1443 + 12) )
                        break;
                      v1444 = *(_DWORD *)(v1443 + 16);
                      if ( !v1444 )
                        break;
                      v1445 = *(_DWORD *)(v1444 + v1383);
                      if ( v1445
                        && (*(int (__fastcall **)(int))(v140 + 408))(v1445)
                        && (*(int (__fastcall **)(int, int *, char *))(v140 + 328))(v1445, &v2875, v2959) )
                      {
                        v1376 = v2802;
                        v1381 = v2875;
                        v1446 = 0;
                        v1447 = v2802;
                        while ( 1 )
                        {
                          v1449 = *v1447++;
                          v1448 = v1449;
                          if ( v1449 == v2875 )
                            goto LABEL_1855;
                          if ( !v1448 )
                            break;
                          if ( (unsigned int)++v1446 >= 0x10 )
                            goto LABEL_1855;
                        }
                        v2802[v1446] = v2875;
LABEL_1855:
                        if ( v1446 == 16 )
                          goto LABEL_1859;
                      }
                      v1443 += 20;
                    }
                    while ( v1443 != v1442 );
                    v1438 = v2853;
                  }
                }
              }
              v1381 = (unsigned int)(v1438 + 1);
              v1380 = __PAIR64__(v2743, v2824);
              v1376 = v2802;
              v2853 = (_BYTE *)v1381;
              if ( v1381 >= 0x10 )
              {
LABEL_1859:
                v1380 = __PAIR64__(v2743, v2824);
LABEL_1860:
                v1341 = v1380;
                v1317 = HIDWORD(v1380);
LABEL_1861:
                LODWORD(v1450) = *(_DWORD *)(v140 + 972);
                HIDWORD(v1450) = *(_DWORD *)(v140 + 968);
                if ( __PAIR64__(v1341, v1317) == v1450 || !(v1341 | v1317) )
                {
                  v1317 = ~v1317;
                  v1341 ^= 0x43D5D824u;
                }
                (*(void (__fastcall **)(_DWORD *, unsigned int))(v140 + 220))(v1376, v1381);
                v1339 = v2845;
                v1340 = v2841;
LABEL_1865:
                LODWORD(v1451) = *(_DWORD *)(*(_DWORD *)(v140 + 960) + 4);
                HIDWORD(v1451) = **(_DWORD **)(v140 + 960);
                __dmb(0xBu);
                if ( __PAIR64__(v1341, v1317) != v1451 )
                {
                  v1452 = *(_QWORD *)*(_DWORD *)(v140 + 960);
                  __dmb(0xBu);
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    v1453 = *(_DWORD *)(v140 + 688);
                    *(_DWORD *)(v1453 + 16) = v1452 ^ v1341;
                    *(_DWORD *)(v1453 + 20) = HIDWORD(v1452) ^ v1317;
                  }
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = 0;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_DWORD *)(v140 + 904) = 258;
                    *(_DWORD *)(v140 + 908) = 0;
                    *(_DWORD *)(v140 + 912) = v1341;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
                v1454 = 0;
                v1455 = v1339 + v2847;
                if ( v1340 )
                {
                  v1456 = (int *)v1339;
                  do
                  {
                    v1457 = *v1456++;
                    ++v1454;
                    v1455 = ((*(_DWORD *)((v1457 >> 4) + v1339) + v1457) ^ v1455) * v1454;
                  }
                  while ( v1454 < v1340 );
                }
                v1458 = 2 * v1455;
                v1459 = **(_DWORD **)(v140 + 692);
                if ( 2 * v1455 != v1459 && (*(_DWORD *)(v140 + 992) & 0x20000) != 0 )
                {
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    v1460 = v1458 ^ v1459;
                    v1461 = *(_DWORD *)(v140 + 688);
                    *(_DWORD *)(v1461 + 16) = v1460;
                    *(_DWORD *)(v1461 + 20) = 0;
                  }
                  if ( !*(_DWORD *)(v140 + 880) )
                  {
                    *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                    *(_DWORD *)(v140 + 892) = 0;
                    *(_DWORD *)(v140 + 896) = 0;
                    *(_DWORD *)(v140 + 900) = 0;
                    *(_DWORD *)(v140 + 904) = 263;
                    *(_DWORD *)(v140 + 908) = 0;
                    *(_DWORD *)(v140 + 912) = v1458;
                    *(_DWORD *)(v140 + 916) = 0;
                    *(_DWORD *)(v140 + 880) = 1;
                  }
                }
                LODWORD(v1289) = *(_DWORD *)(v140 + 952);
                if ( (_DWORD)v1289 && (int)v1289 > 3 )
                {
                  if ( (_DWORD)v1289 != 4 )
                  {
LABEL_2662:
                    *((_DWORD *)v1286 + 238) = 6;
                    goto LABEL_2033;
                  }
LABEL_2041:
                  v140 = (unsigned int)v1286;
                  v2736 = v1286;
                  v2842 = *(_DWORD *)(*((_DWORD *)v1286 + 169) + 16);
                  v1573 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))*((_DWORD *)v1286 + 82);
                  v2869 = (BOOL)v1286;
                  v1574 = v1573(v2842, &v2896, &v2912);
                  v2778 = v1574;
                  if ( !v1574 )
                    goto LABEL_2033;
                  v1575 = &v2932;
                  v1576 = 3;
                  v2859 = (unsigned int)v2912;
                  jj = v2896;
                  v1577 = 12;
                  do
                  {
                    v1577 -= 4;
                    --v1576;
                    *v1575++ = 0;
                  }
                  while ( v1576 );
                  for ( ; v1577; --v1577 )
                  {
                    *(_BYTE *)v1575 = 0;
                    v1575 = (int *)((char *)v1575 + 1);
                  }
                  v1578 = 0;
                  if ( *((_DWORD *)v1286 + 207) )
                  {
                    v1579 = v2933;
                    v1580 = v2934;
                    v1581 = v2932;
                    while ( 1 )
                    {
                      v1582 = v1286;
                      if ( *((_DWORD *)v1286 + 271) )
                        v1582 = (_BYTE *)*((_DWORD *)v1286 + 271);
                      v1583 = 0;
                      v1584 = &v1582[*((_DWORD *)v1582 + 206)];
                      if ( v1581 && v1579 <= v1578 )
                      {
                        v1583 = v1579;
                        v1584 = &v1582[v1580];
                      }
                      if ( v1583 != v1578 )
                        break;
LABEL_2080:
                      v1581 = 1;
                      v1580 = v1584 - v1582;
                      v2932 = 1;
                      v2933 = v1583;
                      v2934 = v1584 - v1582;
                      v1591 = *(_DWORD *)v1584;
                      v1579 = v1583;
                      if ( (*(_DWORD *)v1584 == 1 || v1591 == 12)
                        && *((_DWORD *)v1584 + 1) == v1574
                        && *((_DWORD *)v1584 + 2) == v2859
                        || (v1591 == 33 || v1591 == 34) && *((_DWORD *)v1584 + 5) == jj )
                      {
                        goto LABEL_2089;
                      }
                      if ( ++v1578 >= *((_DWORD *)v1286 + 207) )
                        goto LABEL_2088;
                    }
                    v1585 = v1578 - v1583;
                    v1583 = v1578;
                    while ( 2 )
                    {
                      v1586 = *(_DWORD *)v1584;
                      if ( *(int *)v1584 > 17 )
                      {
                        if ( v1586 != 19 )
                        {
                          if ( v1586 != 28 )
                          {
                            if ( v1586 != 30 )
                            {
                              if ( (unsigned int)(v1586 - 33) <= 1 )
                              {
                                v1590 = 5
                                      * (((*((_DWORD *)v1584 + 6) + (*((_DWORD *)v1584 + 5) & 0xFFFu) + 4095) >> 12) + 2);
                                goto LABEL_2074;
                              }
LABEL_2062:
                              v1587 = 40;
LABEL_2078:
                              v1584 += v1587;
                              if ( !--v1585 )
                              {
                                v1286 = v2850;
                                v1574 = v2778;
                                goto LABEL_2080;
                              }
                              continue;
                            }
                            v1588 = ((((unsigned int)(*((_DWORD *)v1584 + 6) - 1) >> 3) + 7) & 0xFFFFFFF8)
                                  + 24 * *((unsigned __int16 *)v1584 + 14);
LABEL_2067:
                            v1587 = v1588 + 40;
                            goto LABEL_2078;
                          }
                          v1589 = *((unsigned __int16 *)v1584 + 12);
LABEL_2065:
                          v1587 = (v1589 + 47) & 0xFFFFFFF8;
                          goto LABEL_2078;
                        }
                      }
                      else if ( *(_DWORD *)v1584 != 17 )
                      {
                        if ( v1586 == 1 )
                          goto LABEL_2068;
                        if ( v1586 == 7 )
                        {
                          v1588 = 24 * *((_DWORD *)v1584 + 4);
                          goto LABEL_2067;
                        }
                        if ( v1586 != 8 )
                        {
                          if ( v1586 != 10 )
                          {
                            if ( v1586 != 12 )
                              goto LABEL_2062;
LABEL_2068:
                            v1590 = (*((_DWORD *)v1584 + 2) >> 3) + 10;
LABEL_2074:
                            v1587 = 4 * v1590;
                            goto LABEL_2078;
                          }
                          v1588 = 12 * *((_DWORD *)v1584 + 5);
                          goto LABEL_2067;
                        }
                        v1589 = *((unsigned __int16 *)v1584 + 10);
                        goto LABEL_2065;
                      }
                      break;
                    }
                    v1587 = 44;
                    goto LABEL_2078;
                  }
LABEL_2088:
                  v1584 = 0;
LABEL_2089:
                  if ( v1584 )
                    goto LABEL_2090;
                  v2844 = (_DWORD *)(*((int (__fastcall **)(unsigned int, int *, unsigned int *))v1286 + 82))(
                                      v2842,
                                      &v2874,
                                      &v2866);
                  if ( !v2844 )
                  {
                    v2862 = -1073741701;
                    goto LABEL_2644;
                  }
                  v1592 = v2874;
                  v1593 = &v2935;
                  v2859 = v2866;
                  v1594 = 12;
                  v1595 = 3;
                  v2779 = v2874;
                  do
                  {
                    v1594 -= 4;
                    --v1595;
                    *v1593++ = 0;
                  }
                  while ( v1595 );
                  for ( ; v1594; --v1594 )
                  {
                    *(_BYTE *)v1593 = 0;
                    v1593 = (int *)((char *)v1593 + 1);
                  }
                  v1596 = 0;
                  if ( *((_DWORD *)v1286 + 207) )
                  {
                    v1597 = v2936;
                    v1598 = v2937;
                    v1599 = v2935;
                    while ( 1 )
                    {
                      v1600 = v1286;
                      if ( *((_DWORD *)v1286 + 271) )
                        v1600 = (_BYTE *)*((_DWORD *)v1286 + 271);
                      v1601 = 0;
                      v1602 = &v1600[*((_DWORD *)v1600 + 206)];
                      if ( v1599 && v1597 <= v1596 )
                      {
                        v1601 = v1597;
                        v1602 = &v1600[v1598];
                      }
                      if ( v1601 != v1596 )
                        break;
LABEL_2131:
                      v1599 = 1;
                      v1598 = v1602 - v1600;
                      v2935 = 1;
                      v2936 = v1601;
                      v2937 = v1602 - v1600;
                      v1593 = *(int **)v1602;
                      v1597 = v1601;
                      if ( (*(_DWORD *)v1602 == 1 || v1593 == (int *)12)
                        && *((_DWORD **)v1602 + 1) == v2844
                        && *((_DWORD *)v1602 + 2) == v2859
                        || (v1593 == (int *)33 || v1593 == (int *)34) && *((_DWORD *)v1602 + 5) == v1592 )
                      {
                        goto LABEL_2140;
                      }
                      if ( ++v1596 >= *((_DWORD *)v1286 + 207) )
                        goto LABEL_2139;
                    }
                    v1603 = v1596 - v1601;
                    v1601 = v1596;
                    while ( 2 )
                    {
                      v1604 = *(int **)v1602;
                      if ( *(int *)v1602 > 17 )
                      {
                        if ( v1604 != (int *)19 )
                        {
                          if ( v1604 != (int *)28 )
                          {
                            if ( v1604 != (int *)30 )
                            {
                              if ( (unsigned int)v1604 - 33 <= 1 )
                              {
                                v1608 = 5
                                      * (((*((_DWORD *)v1602 + 6) + (*((_DWORD *)v1602 + 5) & 0xFFFu) + 4095) >> 12) + 2);
                                goto LABEL_2125;
                              }
LABEL_2113:
                              v1605 = 40;
LABEL_2129:
                              v1602 += v1605;
                              if ( !--v1603 )
                              {
                                v1286 = v2850;
                                v1592 = v2779;
                                goto LABEL_2131;
                              }
                              continue;
                            }
                            v1606 = ((((unsigned int)(*((_DWORD *)v1602 + 6) - 1) >> 3) + 7) & 0xFFFFFFF8)
                                  + 24 * *((unsigned __int16 *)v1602 + 14);
LABEL_2118:
                            v1605 = v1606 + 40;
                            goto LABEL_2129;
                          }
                          v1607 = *((unsigned __int16 *)v1602 + 12);
LABEL_2116:
                          v1605 = (v1607 + 47) & 0xFFFFFFF8;
                          goto LABEL_2129;
                        }
                      }
                      else if ( *(_DWORD *)v1602 != 17 )
                      {
                        if ( v1604 == (int *)1 )
                          goto LABEL_2119;
                        if ( v1604 == (int *)7 )
                        {
                          v1606 = 24 * *((_DWORD *)v1602 + 4);
                          goto LABEL_2118;
                        }
                        if ( v1604 != (int *)8 )
                        {
                          if ( v1604 != (int *)10 )
                          {
                            if ( v1604 != (int *)12 )
                              goto LABEL_2113;
LABEL_2119:
                            v1608 = (*((_DWORD *)v1602 + 2) >> 3) + 10;
LABEL_2125:
                            v1605 = 4 * v1608;
                            goto LABEL_2129;
                          }
                          v1606 = 12 * *((_DWORD *)v1602 + 5);
                          goto LABEL_2118;
                        }
                        v1607 = *((unsigned __int16 *)v1602 + 10);
                        goto LABEL_2116;
                      }
                      break;
                    }
                    v1605 = 44;
                    goto LABEL_2129;
                  }
LABEL_2139:
                  v1602 = 0;
LABEL_2140:
                  if ( v1602 )
                    goto LABEL_2645;
                  v1609 = (*((int (__fastcall **)(unsigned int, _DWORD, int *))v1286 + 102))(v2842, 0, v1593);
                  v1610 = v2866;
                  v2836 = v2866;
                  if ( !v1609 )
                    goto LABEL_2645;
                  v2857 = v2874;
                  v2845 = (*((int (__fastcall **)(int))v1286 + 81))(v2874);
                  if ( !v2845 )
                    goto LABEL_2143;
                  v1612 = *((_DWORD *)v1286 + 248);
                  v1613 = *((_DWORD *)v1286 + 199);
                  v1614 = *((_DWORD *)v1286 + 232);
                  v1615 = v1286;
                  if ( (v1612 & 0x20000000) == 0 )
                    v1615 = 0;
                  jj = v1610 >> 3;
                  if ( v1614 <= 1 )
                  {
                    if ( v1615 )
                    {
                      v1616 = *((_DWORD *)v1615 + 203);
LABEL_2152:
                      v1617 = (_DWORD *(__fastcall *)(int, int))&v1615[v1616 | 1];
                    }
                    else
                    {
                      v1617 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                    }
                  }
                  else
                  {
                    if ( v1615 )
                    {
                      v1616 = *((_DWORD *)v1615 + 204);
                      goto LABEL_2152;
                    }
                    v1617 = sub_5FD658;
                  }
                  if ( (v1612 & 4) == 0 )
                    v1617 = (_DWORD *(__fastcall *)(int, int))*((_DWORD *)v1286 + 270);
                  v1618 = v1617((int)v1286, v1613 + 4 * (v1610 >> 3) + 40);
                  v2804 = v1618;
                  if ( !v1618 )
                    goto LABEL_2642;
                  v1619 = *((_DWORD *)v1286 + 248);
                  if ( (v1619 & 4) == 0 )
                  {
                    v1620 = *((_DWORD *)v1286 + 199);
                    v1621 = *((_DWORD *)v1286 + 232);
                    v1622 = *((_DWORD *)v1286 + 195);
                    if ( (v1619 & 0x20000000) == 0 )
                      v1621 = 0;
                    if ( v1620 >= 4 )
                    {
                      v1623 = v1620 >> 2;
                      do
                      {
                        v1620 -= 4;
                        --v1623;
                        *(_DWORD *)v1286 = 0;
                        v1286 += 4;
                      }
                      while ( v1623 );
                    }
                    for ( ; v1620; --v1620 )
                      *v1286++ = 0;
                    v1624 = v1618[232];
                    v1618[232] = v1621;
                    if ( v1621 == 3 )
                    {
                      v1625 = (void (__fastcall *)(_DWORD))v1618[124];
                    }
                    else
                    {
                      v1625 = (void (__fastcall *)(_DWORD))v1618[55];
                      if ( v1621 && v1621 == 1 )
                      {
                        ((void (__fastcall *)(int, _DWORD, int, void (__fastcall *)(int)))v1618[87])(
                          v1622 - 4,
                          *(_DWORD *)(v1622 - 4),
                          1,
                          v1625);
                        goto LABEL_2171;
                      }
                    }
                    v1625(v1622);
LABEL_2171:
                    v1618[232] = v1624;
                    v1610 = v2836;
                  }
                  v1626 = (_DWORD *)((char *)v1618 + v1613);
                  v1627 = 10;
                  v1618[248] &= 0xFFFFFFFB;
                  v1628 = v1618[207];
                  v2842 = (unsigned int)v1626;
                  v1629 = v1626;
                  v1618[207] = v1628 + 1;
                  v1630 = 40;
                  do
                  {
                    v1630 -= 4;
                    --v1627;
                    *v1629++ = 0;
                  }
                  while ( v1627 );
                  for ( ; v1630; --v1630 )
                  {
                    *(_BYTE *)v1629 = 0;
                    v1629 = (_DWORD *)((char *)v1629 + 1);
                  }
                  v1631 = v2844;
                  *v1626 = 12;
                  v1626[1] = v1631;
                  v1626[2] = v1610;
                  v1632 = v1631;
                  v1633 = (char *)v1631;
                  if ( v1631 < (_DWORD *)((char *)v1631 + v1610) )
                  {
                    do
                    {
                      __pld(v1633);
                      v1633 += 128;
                    }
                    while ( v1633 < (char *)v1631 + v1610 );
                  }
                  HIDWORD(v1634) = v1618[211];
                  v1635 = v1610;
                  v1636 = v1618[210];
                  if ( v2836 >= 8 )
                  {
                    v1637 = v2836 >> 3;
                    v1638 = v1618[209] & 0x3F;
                    v1639 = 64 - v1638;
                    LOBYTE(v1634) = 32 - v1638;
                    do
                    {
                      v1635 -= 8;
                      v1640 = v1636 ^ *v1632;
                      v1641 = v1632[1];
                      v1632 += 2;
                      HIDWORD(v1634) ^= v1641;
                      v1642 = __PAIR64__(HIDWORD(v1634), v1640) << v1638;
                      v1636 = (v1640 >> v1639) | (HIDWORD(v1634) << (v1638 - 32)) | (HIDWORD(v1634) >> v1634) | (v1640 << v1638);
                      HIDWORD(v1634) = (HIDWORD(v1634) >> v1639) | HIDWORD(v1642);
                      --v1637;
                      LOBYTE(v1634) = 32 - v1638;
                    }
                    while ( v1637 );
                    v140 = (unsigned int)v2736;
                    v1618 = v2804;
                    v1626 = (_DWORD *)v2842;
                  }
                  if ( v1635 )
                  {
                    v1643 = v1618[209] & 0x3F;
                    v1644 = 64 - v1643;
                    do
                    {
                      v1645 = *(unsigned __int8 *)v1632;
                      v1632 = (_DWORD *)((char *)v1632 + 1);
                      v1646 = v1636 ^ v1645;
                      LODWORD(v1634) = (v1646 >> v1644) | (HIDWORD(v1634) << (v1643 - 32)) | (HIDWORD(v1634) >> (32 - v1643));
                      HIDWORD(v1634) = (HIDWORD(v1634) >> v1644) | (__PAIR64__(HIDWORD(v1634), v1646) << v1643 >> 32);
                      v1636 = v1634 | (v1646 << v1643);
                      --v1635;
                    }
                    while ( v1635 );
                    v140 = (unsigned int)v2736;
                    v1618 = v2804;
                    v1626 = (_DWORD *)v2842;
                  }
                  LODWORD(v1634) = v1636;
                  v1618[214] += v2836;
                  while ( 1 )
                  {
                    LODWORD(v1634) = FsRtlPrivateResetHighestLockOffset(v1634, HIDWORD(v1634), 31);
                    if ( !v1634 )
                      break;
                    v1636 ^= v1634;
                  }
                  v1626[3] = v1636 & 0x7FFFFFFF;
                  v1647 = v1626 + 4;
                  v1618[214] += v2836;
                  v1648 = v1618[163];
                  v1649 = (_DWORD *)(v1618[160] + 16);
                  v1650 = ((int (__fastcall *)(int))v1618[89])(12);
                  ((void (__fastcall *)(int))v1618[65])(v1648);
                  v1651 = v2857;
                  v1652 = &v1649[4 * *(_DWORD *)v1618[160]];
                  while ( v1649[1] != v2857 )
                  {
                    v1649 += 4;
                    if ( v1649 >= v1652 )
                      goto LABEL_2194;
                  }
                  v1651 = v1649[1];
                  v1653 = v1649[2];
                  v1654 = v1649[3];
                  *v1647 = *v1649;
                  v1626[5] = v1651;
                  v1626[6] = v1653;
                  v1626[7] = v1654;
                  v2855 = 0;
LABEL_2194:
                  ((void (__fastcall *)(_DWORD, int))v1618[73])(v1618[163], v1651);
                  ((void (__fastcall *)(int))v1618[90])(v1650);
                  if ( (v2855 & 0x80000000) != 0 )
                  {
                    v1655 = 16;
                    v1656 = 4;
                    do
                    {
                      v1655 -= 4;
                      --v1656;
                      *v1647++ = 0;
                    }
                    while ( v1656 );
                    for ( ; v1655; --v1655 )
                    {
                      *(_BYTE *)v1647 = 0;
                      v1647 = (_DWORD *)((char *)v1647 + 1);
                    }
                    v1626[4] = 1;
                  }
                  v1657 = jj;
                  v2841 = (unsigned int)(v1626 + 10);
                  v1658 = 4 * jj;
                  v1659 = v1626 + 10;
                  if ( 4 * jj >= 8 )
                  {
                    v1660 = v1658 >> 3;
                    do
                    {
                      v1658 -= 8;
                      --v1660;
                      *v1659 = -1;
                      v1659[1] = -1;
                      v1659 += 2;
                    }
                    while ( v1660 );
                    v1657 = jj;
                  }
                  for ( ; v1658; --v1658 )
                  {
                    *(_BYTE *)v1659 = -1;
                    v1659 = (_DWORD *)((char *)v1659 + 1);
                  }
                  v1661 = -1;
                  v2842 = (unsigned int)&v2844[2 * v1657];
                  v1662 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))v1618[84];
                  v1663 = v2844;
                  v1664 = *v2844;
                  v1665 = 0;
                  v2853 = v2844;
                  v2825 = -1;
                  v2757 = 0;
                  v1666 = (int *)v1662(v2845, v2857, v1664);
LABEL_2286:
                  v1729 = v1666;
                  v2815 = v1666;
                  if ( !v1666 )
                    goto LABEL_2143;
                  v2744 = 0;
                  if ( (v1666[9] & v2871) != 0
                    || *v1666 == 1414090313 && v1666[1] == 1195525195
                    || *v1666 == 1162297680
                    && ((v1667 = *((unsigned __int16 *)v1666 + 2), v1667 == 30839) || v1667 == 29303 || v1667 == 30583) )
                  {
                    v1704 = 1;
                    v2744 = 1;
                  }
                  else
                  {
                    v1669 = (int *)v1618[235];
                    v1668 = (int *)v1618[234];
                    v1670 = (int *)v1618[237];
                    v1671 = (int *)v1618[236];
                    v1672 = 7;
                    v1673 = v1729;
                    do
                    {
                      v1675 = *v1673++;
                      v1674 = v1675;
                      v1676 = *v1668++;
                      if ( v1674 != v1676 )
                        goto LABEL_2221;
                      v1672 -= 4;
                    }
                    while ( v1672 >= 4 );
                    if ( !v1672 )
                      goto LABEL_2241;
                    while ( 1 )
                    {
                      v1678 = *(unsigned __int8 *)v1673;
                      v1673 = (int *)((char *)v1673 + 1);
                      v1677 = v1678;
                      v1679 = *(unsigned __int8 *)v1668;
                      v1668 = (int *)((char *)v1668 + 1);
                      if ( v1677 != v1679 )
                        break;
                      if ( !--v1672 )
                        goto LABEL_2241;
                    }
LABEL_2221:
                    v1680 = 8;
                    v1681 = v1729;
                    do
                    {
                      v1683 = *v1681++;
                      v1682 = v1683;
                      v1684 = *v1669++;
                      if ( v1682 != v1684 )
                        goto LABEL_2228;
                      v1680 -= 4;
                    }
                    while ( v1680 >= 4 );
                    if ( !v1680 )
                      goto LABEL_2241;
                    while ( 1 )
                    {
                      v1686 = *(unsigned __int8 *)v1681;
                      v1681 = (int *)((char *)v1681 + 1);
                      v1685 = v1686;
                      v1687 = *(unsigned __int8 *)v1669;
                      v1669 = (int *)((char *)v1669 + 1);
                      if ( v1685 != v1687 )
                        break;
                      if ( !--v1680 )
                        goto LABEL_2241;
                    }
LABEL_2228:
                    v1688 = 4;
                    v1689 = v1729;
                    do
                    {
                      v1691 = *v1689++;
                      v1690 = v1691;
                      v1692 = *v1671++;
                      if ( v1690 != v1692 )
                        goto LABEL_2235;
                      v1688 -= 4;
                    }
                    while ( v1688 >= 4 );
                    if ( !v1688 )
                      goto LABEL_2241;
                    while ( 1 )
                    {
                      v1694 = *(unsigned __int8 *)v1689;
                      v1689 = (int *)((char *)v1689 + 1);
                      v1693 = v1694;
                      v1695 = *(unsigned __int8 *)v1671;
                      v1671 = (int *)((char *)v1671 + 1);
                      if ( v1693 != v1695 )
                        break;
                      if ( !--v1688 )
                        goto LABEL_2241;
                    }
LABEL_2235:
                    v1696 = 6;
                    v1697 = v1729;
                    do
                    {
                      v1699 = *v1697++;
                      v1698 = v1699;
                      v1700 = *v1670++;
                      if ( v1698 != v1700 )
                        goto LABEL_2243;
                      v1696 -= 4;
                    }
                    while ( v1696 >= 4 );
                    if ( v1696 )
                    {
                      while ( 1 )
                      {
                        v1702 = *(unsigned __int8 *)v1697;
                        v1697 = (int *)((char *)v1697 + 1);
                        v1701 = v1702;
                        v1703 = *(unsigned __int8 *)v1670;
                        v1670 = (int *)((char *)v1670 + 1);
                        if ( v1701 != v1703 )
                          break;
                        if ( !--v1696 )
                          goto LABEL_2241;
                      }
LABEL_2243:
                      v1704 = 0;
                    }
                    else
                    {
LABEL_2241:
                      v1704 = 1;
                      v2744 = 1;
                    }
                    v1663 = v2853;
                    v1661 = v2825;
                  }
                  if ( v1729[9] < 0 )
                  {
                    v1704 = 1;
                    v2744 = 1;
                  }
                  if ( v1704 && *v1729 == 1414090313 && v1729[1] == 1195525195 && (v1618[248] & v2873) != 0 )
                  {
                    v1704 = 0;
                    v2744 = 0;
                  }
                  v1705 = v1729[4];
                  if ( v1705 <= v1729[2] )
                    v1705 = v1729[2];
                  v1706 = v1729[3] + v1705;
                  v2859 = v1706;
                  while ( 1 )
                  {
                    v1707 = v1663[1];
                    if ( (v1707 & 3) == 0 )
                    {
                      if ( v1707 < v1661 )
                        v2825 = v1663[1];
                      if ( v1707 > v1665 )
                        v2757 = v1663[1];
                    }
                    v1709 = *v1663;
                    v1663 += 2;
                    v1708 = v1709;
                    v1710 = v2857;
                    v1711 = v1709 & 0xFFFFFFFE;
                    v1712 = (_DWORD *)((v1709 & 0xFFFFFFFE) + v2857);
                    v2853 = v1663;
                    v1713 = (v1707 & 3) != 0 ? (v1707 >> 2) & 0x7FF : *(_DWORD *)(v1707 + v2857) & 0x3FFFF;
                    v1714 = ((v1708 + 2 * v1713) & 0xFFFFFFFE) - v1711;
                    v2855 = v1714;
                    if ( v1704 )
                    {
                      v1715 = v2841;
                      *(_DWORD *)v2841 = 0x80000000;
                    }
                    else
                    {
                      v1716 = (char *)v1712;
                      if ( v1712 < (_DWORD *)((char *)v1712 + v1714) )
                      {
                        do
                        {
                          __pld(v1716);
                          v1716 += 128;
                        }
                        while ( v1716 < (char *)v1712 + v1714 );
                      }
                      v1717 = v1714;
                      HIDWORD(v1718) = v1618[211];
                      v1719 = v1618[210];
                      v2698 = v1714;
                      if ( v1714 >= 8 )
                      {
                        v1720 = v1618[209];
                        v1721 = v1714;
                        v1722 = v1720 & 0x3F;
                        v1723 = 64 - (v1720 & 0x3F);
                        v1724 = (v1720 & 0x3F) - 32;
                        LOBYTE(v1718) = 32 - (v1720 & 0x3F);
                        v1725 = v1714 >> 3;
                        do
                        {
                          v1721 -= 8;
                          v1726 = v1719 ^ *v1712;
                          v1727 = v1712[1];
                          v1712 += 2;
                          HIDWORD(v1718) ^= v1727;
                          v1728 = __PAIR64__(HIDWORD(v1718), v1726) << v1722;
                          v1719 = (v1726 >> v1723) | (HIDWORD(v1718) << v1724) | (HIDWORD(v1718) >> v1718) | (v1726 << v1722);
                          HIDWORD(v1718) = (HIDWORD(v1718) >> v1723) | HIDWORD(v1728);
                          --v1725;
                          LOBYTE(v1718) = v1723 - 32;
                        }
                        while ( v1725 );
                        v140 = (unsigned int)v2736;
                        v1729 = v2815;
                        v1714 = v2855;
                        v2698 = v1721;
                        v1618 = v2804;
                        v1717 = v2698;
                      }
                      if ( v1717 )
                      {
                        v1730 = v1618[209];
                        v1731 = v2698;
                        v1732 = v1730 & 0x3F;
                        v1733 = 64 - (v1730 & 0x3F);
                        do
                        {
                          v1734 = *(unsigned __int8 *)v1712;
                          v1712 = (_DWORD *)((char *)v1712 + 1);
                          v1735 = v1719 ^ v1734;
                          LODWORD(v1718) = (v1735 >> v1733) | (HIDWORD(v1718) << ((v1730 & 0x3F) - 32)) | (HIDWORD(v1718) >> (32 - (v1730 & 0x3F)));
                          HIDWORD(v1718) = (HIDWORD(v1718) >> v1733) | (__PAIR64__(HIDWORD(v1718), v1735) << v1732 >> 32);
                          v1719 = v1718 | (v1735 << v1732);
                          --v1731;
                        }
                        while ( v1731 );
                        v140 = (unsigned int)v2736;
                        v1618 = v2804;
                        v1729 = v2815;
                        v1714 = v2855;
                      }
                      LODWORD(v1718) = v1719;
                      v1618[214] += v1714;
                      while ( 1 )
                      {
                        LODWORD(v1718) = FsRtlPrivateResetHighestLockOffset(v1718, HIDWORD(v1718), 31);
                        if ( !v1718 )
                          break;
                        v1719 ^= v1718;
                      }
                      v1736 = v2841;
                      v1737 = v1719 & 0x7FFFFFFF;
                      v1663 = v2853;
                      v1704 = v2744;
                      v1706 = v2859;
                      v1710 = v2857;
                      *(_DWORD *)v2841 = v1737;
                      v1715 = v1736;
                    }
                    if ( v1663 == (_DWORD *)v2842 )
                      break;
                    v1738 = *v1663;
                    v2841 = v1715 + 4;
                    if ( v1738 >= v1729[3] )
                    {
                      v1739 = v1663[1];
                      v1740 = (v1739 & 3) != 0 ? (v1739 >> 2) & 0x7FF : *(_DWORD *)(v1739 + v1710) & 0x3FFFF;
                      v1741 = ((v1738 + 2 * v1740) & 0xFFFFFFFE) + v1710;
                      v1661 = v2825;
                      v1665 = v2757;
                      if ( v1741 <= v1706 )
                        continue;
                    }
                    v1666 = (int *)((int (__fastcall *)(unsigned int, unsigned int, _DWORD))v1618[84])(
                                     v2845,
                                     v2857,
                                     *v1663);
                    v1661 = v2825;
                    v1665 = v2757;
                    goto LABEL_2286;
                  }
                  v1742 = v2825;
                  if ( v2825 == -1 && !v2757 )
                    v1742 = 0;
                  v1743 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v1618[80];
                  v140 = (unsigned int)v1618;
                  v2939[0] = v1742 + v2874;
                  v2938[0] = v2757 - v1742;
                  v1744 = v1743(v2874, 1, 0, &v2866);
                  if ( v1744 )
                  {
                    v1745 = v2866;
                  }
                  else
                  {
                    v1745 = 0;
                    v2866 = 0;
                  }
                  v1746 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v1618[80];
                  v2939[1] = v1744;
                  v2938[1] = v1745;
                  v1747 = v1746(v2874, 1, 12, &v2866);
                  v2805 = (unsigned __int8 *)v1747;
                  if ( v1747 )
                  {
                    v1748 = v2866;
                  }
                  else
                  {
                    v1748 = 0;
                    v2866 = 0;
                  }
                  v2841 = v1748;
                  v2938[2] = v1748;
                  v1749 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v1618[80];
                  v2939[2] = v1747;
                  v1750 = v1749(v2874, 1, 10, &v2866);
                  if ( v1750 )
                  {
                    v1751 = v2866;
                  }
                  else
                  {
                    v1751 = 0;
                    v2866 = 0;
                  }
                  v1752 = v1618[248];
                  v2939[3] = v1750;
                  v1753 = v1618[232];
                  v1754 = v1618[199];
                  v1755 = v1618;
                  if ( (v1752 & 0x20000000) == 0 )
                    v1755 = 0;
                  v2938[3] = v1751;
                  if ( v1753 <= 1 )
                  {
                    if ( v1755 )
                    {
                      v1756 = v1755[203];
LABEL_2308:
                      v1757 = (_DWORD *(__fastcall *)(int, int))((char *)v1755 + (v1756 | 1));
                    }
                    else
                    {
                      v1757 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                    }
                  }
                  else
                  {
                    if ( v1755 )
                    {
                      v1756 = v1755[204];
                      goto LABEL_2308;
                    }
                    v1757 = sub_5FD658;
                  }
                  if ( (v1752 & 4) == 0 )
                    v1757 = (_DWORD *(__fastcall *)(int, int))v1618[270];
                  v1286 = v1757((int)v1618, v1754 + 160);
                  v2850 = v1286;
                  if ( !v1286 )
                    goto LABEL_2641;
                  v1758 = v1618[248];
                  if ( (v1758 & 4) == 0 )
                  {
                    v1759 = v1618[199];
                    v1760 = v1618[232];
                    v1761 = v1618[195];
                    if ( (v1758 & 0x20000000) == 0 )
                      v1760 = 0;
                    if ( v1759 >= 4 )
                    {
                      v1762 = v1759 >> 2;
                      do
                      {
                        v1759 -= 4;
                        --v1762;
                        *v1618++ = 0;
                      }
                      while ( v1762 );
                    }
                    for ( ; v1759; --v1759 )
                    {
                      *(_BYTE *)v1618 = 0;
                      v1618 = (_DWORD *)((char *)v1618 + 1);
                    }
                    v1763 = *((_DWORD *)v1286 + 232);
                    *((_DWORD *)v1286 + 232) = v1760;
                    if ( v1760 == 3 )
                    {
                      v1764 = (void (__fastcall *)(_DWORD))*((_DWORD *)v1286 + 124);
                    }
                    else
                    {
                      v1764 = (void (__fastcall *)(_DWORD))*((_DWORD *)v1286 + 55);
                      if ( v1760 && v1760 == 1 )
                      {
                        (*((void (__fastcall **)(int, _DWORD, int, void (__fastcall *)(_DWORD)))v1286 + 87))(
                          v1761 - 4,
                          *(_DWORD *)(v1761 - 4),
                          1,
                          v1764);
                        goto LABEL_2327;
                      }
                    }
                    v1764(v1761);
LABEL_2327:
                    *((_DWORD *)v1286 + 232) = v1763;
                  }
                  v1765 = &v1286[v1754];
                  *((_DWORD *)v1286 + 248) &= 0xFFFFFFFB;
                  v2816 = &v1286[v1754];
                  v2726 = &v1286[v1754];
                  *((_DWORD *)v1286 + 207) += 4;
                  v1766 = 0;
                  v2842 = 0;
                  do
                  {
                    v1767 = *(int *)((char *)v2938 + v1766);
                    v1768 = *(_DWORD **)((char *)v2939 + v1766);
                    v1769 = 40;
                    v1770 = 10;
                    v2855 = v1767;
                    v1771 = v1765;
                    do
                    {
                      v1769 -= 4;
                      --v1770;
                      *v1771++ = 0;
                    }
                    while ( v1770 );
                    for ( ; v1769; --v1769 )
                    {
                      *(_BYTE *)v1771 = 0;
                      v1771 = (_DWORD *)((char *)v1771 + 1);
                    }
                    *v1765 = 11;
                    v1765[1] = v1768;
                    v1765[2] = v1767;
                    v1772 = (char *)v1768;
                    if ( v1768 < (_DWORD *)((char *)v1768 + v1767) )
                    {
                      do
                      {
                        __pld(v1772);
                        v1772 += 128;
                      }
                      while ( v1772 < (char *)v1768 + v1767 );
                    }
                    HIDWORD(v1773) = *((_DWORD *)v1286 + 211);
                    v1774 = *((_DWORD *)v1286 + 210);
                    v1775 = v1767;
                    if ( v1767 >= 8 )
                    {
                      v1776 = v1767 >> 3;
                      v1777 = *((_DWORD *)v1286 + 209) & 0x3F;
                      v1778 = 64 - v1777;
                      LOBYTE(v1773) = 32 - v1777;
                      do
                      {
                        v1775 -= 8;
                        v1779 = v1774 ^ *v1768;
                        v1780 = v1768[1];
                        v1768 += 2;
                        HIDWORD(v1773) ^= v1780;
                        v1781 = __PAIR64__(HIDWORD(v1773), v1779) << v1777;
                        v1774 = (v1779 >> v1778) | (HIDWORD(v1773) << (v1777 - 32)) | (HIDWORD(v1773) >> v1773) | (v1779 << v1777);
                        HIDWORD(v1773) = (HIDWORD(v1773) >> v1778) | HIDWORD(v1781);
                        --v1776;
                        LOBYTE(v1773) = 32 - v1777;
                      }
                      while ( v1776 );
                      v1286 = v2850;
                      v1765 = v2816;
                      v1767 = v2855;
                    }
                    if ( v1775 )
                    {
                      v1782 = *((_DWORD *)v1286 + 209) & 0x3F;
                      v1783 = 64 - v1782;
                      do
                      {
                        v1784 = *(unsigned __int8 *)v1768;
                        v1768 = (_DWORD *)((char *)v1768 + 1);
                        v1785 = v1774 ^ v1784;
                        LODWORD(v1773) = (v1785 >> v1783) | (HIDWORD(v1773) << (v1782 - 32)) | (HIDWORD(v1773) >> (32 - v1782));
                        HIDWORD(v1773) = (HIDWORD(v1773) >> v1783) | (__PAIR64__(HIDWORD(v1773), v1785) << v1782 >> 32);
                        v1774 = v1773 | (v1785 << v1782);
                        --v1775;
                      }
                      while ( v1775 );
                      v1286 = v2850;
                      v1765 = v2816;
                      v1767 = v2855;
                    }
                    LODWORD(v1773) = v1774;
                    *((_DWORD *)v1286 + 214) += v1767;
                    while ( 1 )
                    {
                      LODWORD(v1773) = FsRtlPrivateResetHighestLockOffset(v1773, HIDWORD(v1773), 31);
                      if ( !v1773 )
                        break;
                      v1774 ^= v1773;
                    }
                    v1765[3] = v1774 & 0x7FFFFFFF;
                    v1765 += 10;
                    v2816 = v1765;
                    *((_DWORD *)v1286 + 214) += v1767;
                    v1766 = v2842 + 4;
                    v2842 = v1766;
                  }
                  while ( v1766 < 0x10 );
                  v1786 = (int)v2726;
                  v140 = (unsigned int)v1286;
                  v2737 = v1286;
                  v1787 = v2726 + 80;
                  if ( v2726 == (_BYTE *)-80 )
                  {
                    v1788 = *((_DWORD *)v1286 + 248);
                    v1789 = *((_DWORD *)v1286 + 199);
                    v1790 = v1286;
                    if ( (v1788 & 0x20000000) == 0 )
                      v1790 = 0;
                    if ( *((int *)v1286 + 232) <= 1 )
                    {
                      if ( v1790 )
                      {
                        v1791 = *((_DWORD *)v1790 + 203);
LABEL_2356:
                        v1792 = (_DWORD *(__fastcall *)(int, int))&v1790[v1791 | 1];
                      }
                      else
                      {
                        v1792 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                      }
                    }
                    else
                    {
                      if ( v1790 )
                      {
                        v1791 = *((_DWORD *)v1790 + 204);
                        goto LABEL_2356;
                      }
                      v1792 = sub_5FD658;
                    }
                    if ( (v1788 & 4) == 0 )
                      v1792 = (_DWORD *(__fastcall *)(int, int))*((_DWORD *)v1286 + 270);
                    v1618 = v1792((int)v1286, v1789 + 40);
                    v2846 = (unsigned int)v1618;
                    if ( !v1618 )
                      goto LABEL_2644;
                    v1793 = *((_DWORD *)v1286 + 248);
                    if ( (v1793 & 4) == 0 )
                    {
                      v1794 = *((_DWORD *)v1286 + 199);
                      v1795 = *((_DWORD *)v1286 + 232);
                      v1796 = *((_DWORD *)v1286 + 195);
                      if ( (v1793 & 0x20000000) == 0 )
                        v1795 = 0;
                      v1797 = v1286;
                      if ( v1794 >= 4 )
                      {
                        v1798 = v1794 >> 2;
                        do
                        {
                          v1794 -= 4;
                          --v1798;
                          *v1797++ = 0;
                        }
                        while ( v1798 );
                      }
                      for ( ; v1794; --v1794 )
                      {
                        *(_BYTE *)v1797 = 0;
                        v1797 = (_DWORD *)((char *)v1797 + 1);
                      }
                      v1799 = v1618[232];
                      v1618[232] = v1795;
                      if ( v1795 == 3 )
                      {
                        v1800 = (void (__fastcall *)(_DWORD, _DWORD))v1618[124];
                      }
                      else
                      {
                        v1800 = (void (__fastcall *)(_DWORD, _DWORD))v1618[55];
                        if ( v1795 && v1795 == 1 )
                        {
                          ((void (__fastcall *)(int, _DWORD, int, void (__fastcall *)(int, _DWORD *)))v1618[87])(
                            v1796 - 4,
                            *(_DWORD *)(v1796 - 4),
                            1,
                            (void (__fastcall *)(int, _DWORD *))v1800);
                          goto LABEL_2375;
                        }
                      }
                      v1800(v1796, v1797);
LABEL_2375:
                      v1618[232] = v1799;
                    }
                    v1787 = (_DWORD *)((char *)v1618 + v1789);
                    v1801 = 10;
                    v1618[248] &= 0xFFFFFFFB;
                    v1802 = v1618[207];
                    v2855 = (unsigned int)v1787;
                    v1803 = v1787;
                    v1618[207] = v1802 + 1;
                    v1804 = 40;
                    do
                    {
                      v1804 -= 4;
                      --v1801;
                      *v1803++ = 0;
                    }
                    while ( v1801 );
                    for ( ; v1804; --v1804 )
                    {
                      *(_BYTE *)v1803 = 0;
                      v1803 = (_DWORD *)((char *)v1803 + 1);
                    }
                    LODWORD(v1805) = v2841;
                    *v1787 = 14;
                    v1787[1] = v2805;
                    v1787[2] = v1805;
                    v1806 = (char *)v2805;
                    if ( v2805 < &v2805[(unsigned int)v1805] )
                    {
                      do
                      {
                        __pld(v1806);
                        v1806 += 128;
                      }
                      while ( v1806 < (char *)&v2805[v1805] );
                    }
                    v1807 = v1805;
                    HIDWORD(v1805) = v1618[211];
                    v1808 = v1618[210];
                    v2699 = v1805;
                    if ( (unsigned int)v1805 >= 8 )
                    {
                      v1809 = v1805;
                      v1810 = v2805;
                      v1811 = v1618[209] & 0x3F;
                      v1812 = 64 - v1811;
                      v1813 = (unsigned int)v1805 >> 3;
                      LOBYTE(v1805) = 32 - v1811;
                      do
                      {
                        v1809 -= 8;
                        v1814 = v1808 ^ *(_DWORD *)v1810;
                        v1815 = *((_DWORD *)v1810 + 1);
                        v1810 += 8;
                        HIDWORD(v1805) ^= v1815;
                        v1816 = __PAIR64__(HIDWORD(v1805), v1814) << v1811;
                        v1808 = (v1814 >> v1812) | (HIDWORD(v1805) << (v1811 - 32)) | (HIDWORD(v1805) >> v1805) | (v1814 << v1811);
                        HIDWORD(v1805) = (HIDWORD(v1805) >> v1812) | HIDWORD(v1816);
                        --v1813;
                        LOBYTE(v1805) = 32 - v1811;
                      }
                      while ( v1813 );
                      v140 = (unsigned int)v1286;
                      v1618 = (_DWORD *)v2846;
                      v1286 = v2850;
                      v2805 = v1810;
                      v1787 = (_DWORD *)v2855;
                      v2699 = v1809;
                      v1807 = v1809;
                      v1786 = -80;
                    }
                    if ( v1807 )
                    {
                      v1817 = v2699;
                      v1818 = v2805;
                      v1819 = v1618[209] & 0x3F;
                      v1820 = 64 - v1819;
                      do
                      {
                        v1821 = *v1818++;
                        v1822 = v1808 ^ v1821;
                        LODWORD(v1805) = (v1822 >> v1820) | (HIDWORD(v1805) << (v1819 - 32)) | (HIDWORD(v1805) >> (32 - v1819));
                        HIDWORD(v1805) = (HIDWORD(v1805) >> v1820) | (__PAIR64__(HIDWORD(v1805), v1822) << v1819 >> 32);
                        v1808 = v1805 | (v1822 << v1819);
                        --v1817;
                      }
                      while ( v1817 );
                      v1786 = -80;
                      v140 = (unsigned int)v2737;
                      v1618 = (_DWORD *)v2846;
                      v1286 = v2850;
                      v1787 = (_DWORD *)v2855;
                    }
                    v1823 = v2841;
                    LODWORD(v1805) = v1808;
                    v1618[214] += v2841;
                    while ( 1 )
                    {
                      LODWORD(v1805) = FsRtlPrivateResetHighestLockOffset(v1805, HIDWORD(v1805), 31);
                      if ( !v1805 )
                        break;
                      v1808 ^= v1805;
                    }
                    v1787[3] = v1808 & 0x7FFFFFFF;
                    v1618[214] += v1823;
                  }
                  else
                  {
                    *v1787 = 14;
                    v1618 = v1286;
                  }
                  v1787[4] = 1;
                  if ( !v1618 )
                    goto LABEL_2644;
                  v1824 = v2874;
                  *(_DWORD *)(v1786 + 120) = 35;
                  v140 = (unsigned int)v1618;
                  *(_DWORD *)(v1786 + 144) |= 1u;
                  if ( *(_DWORD *)(v1786 + 128) >= 0x5Cu )
                  {
                    v1825 = *(_DWORD *)(v1786 + 124);
                    v1826 = ((int (__fastcall *)(unsigned int))v1618[81])(v1824);
                    if ( v1826 )
                    {
                      v1827 = *(_DWORD *)(v1826 + 80) + v1824;
                      *(_DWORD *)(v1786 + 144) |= 2u;
                      v1828 = *(_DWORD **)(v1825 + 72);
                      if ( (unsigned int)v1828 >= v1824 && (unsigned int)v1828 < v1827 )
                      {
                        *(_DWORD *)(v1786 + 136) = *v1828;
                        *(_DWORD *)(v1786 + 144) |= 4u;
                      }
                      v1829 = *(_DWORD **)(v1825 + 76);
                      if ( (unsigned int)v1829 >= v1824 && (unsigned int)v1829 < v1827 )
                      {
                        *(_DWORD *)(v1786 + 140) = *v1829;
                        *(_DWORD *)(v1786 + 144) |= 8u;
                      }
                      goto LABEL_2404;
                    }
LABEL_2641:
                    v1286 = v1618;
                    v2862 = -1073741670;
                    goto LABEL_2644;
                  }
LABEL_2404:
                  v1830 = v2874;
                  v1831 = v1618[248];
                  v2826 = v2874;
                  v140 = (unsigned int)v1618;
                  v2869 = (BOOL)v1618;
                  if ( (v1831 & 0x400000) == 0 )
                    goto LABEL_2640;
                  v1832 = ((int (__fastcall *)(int))v1618[81])(v2874);
                  v1833 = v1832;
                  v2780 = v1832;
                  if ( !v1832 )
                    goto LABEL_2143;
                  v1834 = *(unsigned __int16 *)(v1832 + 6);
                  v2855 = v2836 >> 3;
                  if ( !v1834 )
                  {
                    if ( (v1618[248] & 0x200000) == 0 )
                    {
                      v1835 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                      if ( v1835 )
                      {
                        if ( v1835 == 1 )
                        {
                          v2890 = -2147483490;
                          v1836 = -2147483490;
                          v1837 = 31;
                        }
                        else
                        {
                          v2890 = 634;
                          v1836 = 634;
                          v1837 = 1;
                        }
                      }
                      else
                      {
                        v2890 = 154817;
                        v1836 = 162304;
                        v1837 = 9;
                      }
                      KeBugCheckEx(__ROR4__(v1836, v1837), 10, v1830, 0, 0);
                    }
                    goto LABEL_2412;
                  }
                  v1838 = 0;
                  v1839 = v2844;
                  v1840 = &v2844[2 * (v2836 >> 3)];
                  v1841 = *(unsigned __int16 *)(v1833 + 20);
                  v2854 = v1840;
                  v1842 = (_DWORD *)(v1841 + v1833 + 24);
                  v2852 = (unsigned int)v1842;
                  do
                  {
                    v1843 = v1842[4];
                    v1844 = v1842[3];
                    if ( v1843 <= v1842[2] )
                      v1843 = v1842[2];
                    v1845 = v1843 + v1844;
                    if ( v1838 && v1845 < *(v1842 - 7) )
                    {
                      if ( (v1618[248] & 0x200000) == 0 )
                      {
                        v1846 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                        if ( v1846 )
                        {
                          if ( v1846 == 1 )
                          {
                            v2893 = -2147483490;
                            v1847 = -2147483490;
                            v1848 = 31;
                          }
                          else
                          {
                            v2893 = 634;
                            v1847 = 634;
                            v1848 = 1;
                          }
                        }
                        else
                        {
                          v2893 = 154817;
                          v1847 = 162304;
                          v1848 = 9;
                        }
                        KeBugCheckEx(__ROR4__(v1847, v1848), 10, v1830, 1, 0);
                      }
                      goto LABEL_2412;
                    }
                    while ( 1 )
                    {
                      if ( v1839 == v1840 )
                        goto LABEL_2431;
                      v1830 = v2826;
                      v1849 = *v1839 & 0xFFFFFFFE;
                      v1850 = (*v1839 + 2 * v1839[1]) & 0xFFFFFFFE;
                      if ( v1849 >= v1845 || v1850 <= v1844 )
                        break;
                      if ( v1849 < v1844 || v1850 > v1845 )
                      {
                        if ( (v1618[248] & 0x200000) == 0 )
                        {
                          v1855 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                          if ( v1855 )
                          {
                            if ( v1855 == 1 )
                            {
                              v2882 = -2147483490;
                              v1856 = -2147483490;
                              v1857 = 31;
                            }
                            else
                            {
                              v2882 = 634;
                              v1856 = 634;
                              v1857 = 1;
                            }
                          }
                          else
                          {
                            v2882 = 154817;
                            v1856 = 162304;
                            v1857 = 9;
                          }
                          KeBugCheckEx(__ROR4__(v1856, v1857), 10, v2826, 2, 0);
                        }
                        if ( !v1618[220] )
                        {
LABEL_2413:
                          v1618[222] = v1618 - 462279366;
                          v1618[223] = 0;
                          v1618[224] = 0;
                          v1618[225] = 0;
                          v1618[226] = 271;
                          v1618[227] = 0;
                          v1618[228] = v1830;
                          v1618[229] = 0;
                          v1618[220] = 1;
                        }
LABEL_2143:
                        v1611 = -1073741701;
LABEL_2643:
                        v2862 = v1611;
                        v1286 = (_BYTE *)v140;
                        if ( v1611 < 0 )
                        {
LABEL_2644:
                          v2016 = v2862;
                          goto LABEL_2656;
                        }
LABEL_2645:
                        v2017 = (*(int (__fastcall **)(unsigned int))(v140 + 324))(v2896);
                        v2018 = *(_DWORD *)(v2017 + 132);
                        if ( v2018 >= 0x14 )
                        {
                          v2019 = *(_DWORD *)(v2017 + 128);
                          v2020 = v2896;
                          v2021 = v2896 + v2019 + v2018;
                          for ( ll = v2896 + v2019; ll != v2021; ll += 20 )
                          {
                            if ( !*(_DWORD *)(ll + 12) )
                              break;
                            v2023 = *(_DWORD *)(ll + 16);
                            if ( !v2023 )
                              break;
                            v2024 = *(_DWORD *)(v2020 + v2023);
                            if ( v2024 )
                            {
                              v2025 = sub_5FB5E4((unsigned int *)&v2869, v2024, -2147483641);
                              v140 = v2869;
                              v2016 = v2025;
                              v1286 = (_BYTE *)v2869;
                              if ( v2025 < 0 )
                              {
                                LODWORD(v1289) = -1073741554;
                                if ( v2025 != -1073741554 )
                                  goto LABEL_2657;
                              }
                              v2020 = v2896;
                            }
                          }
                          v2016 = 0;
LABEL_2656:
                          LODWORD(v1289) = -1073741554;
LABEL_2657:
                          if ( v2016 >= 0 || v2016 == -1073741554 )
                          {
LABEL_2659:
                            if ( (*((int (__fastcall **)(_DWORD, _BYTE *, char *))v1286 + 82))(
                                   *(_DWORD *)(*((_DWORD *)v1286 + 169) + 16),
                                   v1286 + 984,
                                   v2952) )
                            {
                              v2026 = (*((int (__fastcall **)(_DWORD))v1286 + 81))(*((_DWORD *)v1286 + 246));
                              if ( v2026 )
                              {
                                *((_DWORD *)v1286 + 245) = *(_DWORD *)(v2026 + 80);
                                *((_DWORD *)v1286 + 238) = 5;
                                goto LABEL_2662;
                              }
                            }
                            if ( !*((_DWORD *)v1286 + 220) )
                            {
                              *((_DWORD *)v1286 + 222) = v1286 - 1849117464;
                              *((_DWORD *)v1286 + 223) = 0;
                              *((_DWORD *)v1286 + 224) = 0;
                              *((_DWORD *)v1286 + 225) = 0;
                              *((_DWORD *)v1286 + 226) = 261;
                              *((_DWORD *)v1286 + 227) = 0;
                              *((_DWORD *)v1286 + 228) = -1073741701;
                              *((_DWORD *)v1286 + 229) = 0;
                              *((_DWORD *)v1286 + 220) = 1;
                            }
                          }
LABEL_2033:
                          if ( (*((_DWORD *)v1286 + 248) & 0x8000) != 0 || !*((_DWORD *)v1286 + 220) )
                          {
                            v1570 = *((_DWORD *)v1286 + 247);
                            *((_DWORD *)v1286 + 247) = 0;
                            (*((void (__fastcall **)(int, char *, _DWORD))v1286 + 100))(v1570, v2954, v1289);
                            v1571 = *((_DWORD *)v1286 + 248);
                            if ( (v1571 & 1) != 0 )
                            {
                              *((_DWORD *)v1286 + 248) = v1571 & 0xFFFFFFFE;
                              v1570 = (*((int (__fastcall **)(int))v1286 + 97))(v1570);
                              if ( v1570 )
                                *((_DWORD *)v1286 + 244) = (*((int (**)(void))v1286 + 101))();
                              else
                                *((_DWORD *)v1286 + 244) = -1;
                            }
                            if ( v1570 )
                              (*((void (__fastcall **)(int))v1286 + 98))(v1570);
                          }
LABEL_2668:
                          v2734 = (_BYTE *)v140;
                          goto LABEL_2669;
                        }
LABEL_2090:
                        v140 = (unsigned int)v1286;
                        goto LABEL_2659;
                      }
                      v1840 = v2854;
                      v1839 += 2;
                    }
                    v1840 = v2854;
LABEL_2431:
                    ++v1838;
                    v1842 += 10;
                  }
                  while ( v1838 < v1834 );
                  v1851 = v2780;
                  if ( v1839 != v1840 )
                  {
                    if ( (v1618[248] & 0x200000) == 0 )
                    {
                      v1852 = FsRtlRemovePerStreamContextEx(3i64, 0x26C1ui64);
                      if ( v1852 )
                      {
                        if ( v1852 == 1 )
                        {
                          v2879 = -2147483490;
                          v1853 = -2147483490;
                          v1854 = 31;
                        }
                        else
                        {
                          v2879 = 634;
                          v1853 = 634;
                          v1854 = 1;
                        }
                      }
                      else
                      {
                        v2879 = 154817;
                        v1853 = 162304;
                        v1854 = 9;
                      }
                      KeBugCheckEx(__ROR4__(v1853, v1854), 10, v1830, 3, 0);
                    }
LABEL_2412:
                    if ( !v1618[220] )
                      goto LABEL_2413;
                    goto LABEL_2143;
                  }
                  v1858 = v1618[248];
                  v2781 = v1618[199];
                  v1859 = v1618;
                  if ( (v1858 & 0x20000000) == 0 )
                    v1859 = 0;
                  if ( (int)v1618[232] <= 1 )
                  {
                    if ( v1859 )
                    {
                      v1860 = v1859[203];
LABEL_2454:
                      v1861 = (_DWORD *(__fastcall *)(int, int))((char *)v1859 + (v1860 | 1));
                    }
                    else
                    {
                      v1861 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                    }
                  }
                  else
                  {
                    if ( v1859 )
                    {
                      v1860 = v1859[204];
                      goto LABEL_2454;
                    }
                    v1861 = sub_5FD658;
                  }
                  if ( (v1858 & 4) == 0 )
                    v1861 = (_DWORD *(__fastcall *)(int, int))v1618[270];
                  v1862 = v1861((int)v1618, v1618[199] + ((v2855 + 6) & 0xFFFFFFF8) + 24 * v1834 + 40);
                  v2857 = (unsigned int)v1862;
                  if ( !v1862 )
                  {
LABEL_2642:
                    v1611 = -1073741670;
                    goto LABEL_2643;
                  }
                  v1863 = v1618[248];
                  if ( (v1863 & 4) == 0 )
                  {
                    v1864 = v1618[199];
                    v1865 = v1618[232];
                    v1866 = v1618[195];
                    if ( (v1863 & 0x20000000) == 0 )
                      v1865 = 0;
                    if ( v1864 >= 4 )
                    {
                      v1867 = v1864 >> 2;
                      do
                      {
                        v1864 -= 4;
                        --v1867;
                        *v1618++ = 0;
                      }
                      while ( v1867 );
                    }
                    for ( ; v1864; --v1864 )
                    {
                      *(_BYTE *)v1618 = 0;
                      v1618 = (_DWORD *)((char *)v1618 + 1);
                    }
                    v1868 = v1862[232];
                    v1862[232] = v1865;
                    if ( v1865 == 3 )
                    {
                      v1869 = (void (__fastcall *)(_DWORD))v1862[124];
                    }
                    else
                    {
                      v1869 = (void (__fastcall *)(_DWORD))v1862[55];
                      if ( v1865 && v1865 == 1 )
                      {
                        ((void (__fastcall *)(int, _DWORD, int, void (__fastcall *)(int)))v1862[87])(
                          v1866 - 4,
                          *(_DWORD *)(v1866 - 4),
                          1,
                          v1869);
                        goto LABEL_2473;
                      }
                    }
                    v1869(v1866);
LABEL_2473:
                    v1862[232] = v1868;
                  }
                  v1870 = 10;
                  v1862[248] &= 0xFFFFFFFB;
                  ++v1862[207];
                  v1871 = (char *)v1862 + v2781;
                  v1872 = 40;
                  v1873 = (_DWORD *)((char *)v1862 + v2781);
                  do
                  {
                    v1872 -= 4;
                    --v1870;
                    *v1873++ = 0;
                  }
                  while ( v1870 );
                  for ( ; v1872; --v1872 )
                  {
                    *(_BYTE *)v1873 = 0;
                    v1873 = (_DWORD *)((char *)v1873 + 1);
                  }
                  *(_DWORD *)v1871 = 30;
                  *((_DWORD *)v1871 + 1) = v2844;
                  *((_DWORD *)v1871 + 2) = 0;
                  HIDWORD(v1875) = v1862[211];
                  v1874 = v1862[210];
                  LODWORD(v1875) = v1874;
                  while ( 1 )
                  {
                    LODWORD(v1875) = FsRtlPrivateResetHighestLockOffset(v1875, HIDWORD(v1875), 31);
                    if ( !v1875 )
                      break;
                    v1874 ^= v1875;
                  }
                  *((_DWORD *)v1871 + 3) = v1874 & 0x7FFFFFFF;
                  *((_DWORD *)v1871 + 4) = v1830;
                  v1876 = v2855;
                  *((_DWORD *)v1871 + 5) = *(_DWORD *)(v1851 + 80);
                  v2853 = v1871 + 40;
                  *((_DWORD *)v1871 + 6) = v2836;
                  *((_WORD *)v1871 + 14) = v1834;
                  v1877 = *((_WORD *)v1871 + 15);
                  v1618 = v1862;
                  v2846 = (unsigned int)v1862;
                  *((_WORD *)v1871 + 15) = v1877 | 1;
                  v1878 = (int *)&v1871[((v1876 + 6) & 0xFFFFFFF8) + 40];
                  v1879 = *((unsigned __int16 *)v1871 + 14);
                  v2851 = v1878;
                  v1880 = (unsigned int)&v1878[6 * v1879];
                  v2859 = v1880;
                  if ( v1876 )
                    v1881 = v2844 + 2;
                  else
                    v1881 = v2854;
                  v2837 = v1881;
                  v1882 = &v1871[((v1876 + 6) & 0xFFFFFFF8) + 40];
                  do
                  {
                    v1883 = 2;
                    do
                    {
                      *(_DWORD *)v1882 = 0;
                      *((_DWORD *)v1882 + 1) = 0;
                      *((_DWORD *)v1882 + 2) = 0x80000000;
                      v1882 += 12;
                      --v1883;
                    }
                    while ( v1883 );
                    --v1834;
                  }
                  while ( v1834 );
                  if ( v1878 == (int *)v1880 )
                  {
LABEL_2640:
                    v140 = (unsigned int)v1618;
                    v2869 = (BOOL)v1618;
                    v1611 = 0;
                    goto LABEL_2643;
                  }
                  v1884 = (int *)v2852;
                  while ( 2 )
                  {
                    v2745 = 0;
                    if ( (v1884[9] & v2871) != 0
                      || *v1884 == 1414090313 && v1884[1] == 1195525195
                      || *v1884 == 1162297680
                      && ((v1885 = *((unsigned __int16 *)v1884 + 2), v1885 == 30839) || v1885 == 29303 || v1885 == 30583) )
                    {
                      v1922 = 1;
                      v2745 = 1;
                    }
                    else
                    {
                      v1887 = (int *)v1862[235];
                      v1886 = (int *)v1862[234];
                      v1888 = (int *)v1862[237];
                      v1889 = (int *)v1862[236];
                      v1890 = 7;
                      v1891 = v1884;
                      while ( 1 )
                      {
                        v1893 = *v1891++;
                        v1892 = v1893;
                        v1894 = *v1886++;
                        if ( v1892 != v1894 )
                          break;
                        v1890 -= 4;
                        if ( v1890 < 4 )
                        {
                          if ( !v1890 )
                          {
LABEL_2524:
                            v1922 = 1;
                            v2745 = 1;
                            goto LABEL_2527;
                          }
                          while ( 1 )
                          {
                            v1896 = *(unsigned __int8 *)v1891;
                            v1891 = (int *)((char *)v1891 + 1);
                            v1895 = v1896;
                            v1897 = *(unsigned __int8 *)v1886;
                            v1886 = (int *)((char *)v1886 + 1);
                            if ( v1895 != v1897 )
                              goto LABEL_2504;
                            if ( !--v1890 )
                              goto LABEL_2524;
                          }
                        }
                      }
LABEL_2504:
                      v1898 = 8;
                      v1899 = v1884;
                      while ( 1 )
                      {
                        v1901 = *v1899++;
                        v1900 = v1901;
                        v1902 = *v1887++;
                        if ( v1900 != v1902 )
                          break;
                        v1898 -= 4;
                        if ( v1898 < 4 )
                        {
                          if ( !v1898 )
                            goto LABEL_2524;
                          while ( 1 )
                          {
                            v1904 = *(unsigned __int8 *)v1899;
                            v1899 = (int *)((char *)v1899 + 1);
                            v1903 = v1904;
                            v1905 = *(unsigned __int8 *)v1887;
                            v1887 = (int *)((char *)v1887 + 1);
                            if ( v1903 != v1905 )
                              goto LABEL_2511;
                            if ( !--v1898 )
                              goto LABEL_2524;
                          }
                        }
                      }
LABEL_2511:
                      v1906 = 4;
                      v1907 = v1884;
                      while ( 1 )
                      {
                        v1909 = *v1907++;
                        v1908 = v1909;
                        v1910 = *v1889++;
                        if ( v1908 != v1910 )
                          break;
                        v1906 -= 4;
                        if ( v1906 < 4 )
                        {
                          if ( !v1906 )
                            goto LABEL_2524;
                          while ( 1 )
                          {
                            v1912 = *(unsigned __int8 *)v1907;
                            v1907 = (int *)((char *)v1907 + 1);
                            v1911 = v1912;
                            v1913 = *(unsigned __int8 *)v1889;
                            v1889 = (int *)((char *)v1889 + 1);
                            if ( v1911 != v1913 )
                              goto LABEL_2518;
                            if ( !--v1906 )
                              goto LABEL_2524;
                          }
                        }
                      }
LABEL_2518:
                      v1914 = 6;
                      v1915 = v1884;
                      while ( 1 )
                      {
                        v1917 = *v1915++;
                        v1916 = v1917;
                        v1918 = *v1888++;
                        if ( v1916 != v1918 )
                          break;
                        v1914 -= 4;
                        if ( v1914 < 4 )
                        {
                          if ( !v1914 )
                            goto LABEL_2524;
                          while ( 1 )
                          {
                            v1920 = *(unsigned __int8 *)v1915;
                            v1915 = (int *)((char *)v1915 + 1);
                            v1919 = v1920;
                            v1921 = *(unsigned __int8 *)v1888;
                            v1888 = (int *)((char *)v1888 + 1);
                            if ( v1919 != v1921 )
                              goto LABEL_2526;
                            if ( !--v1914 )
                              goto LABEL_2524;
                          }
                        }
                      }
LABEL_2526:
                      v1922 = 0;
                    }
LABEL_2527:
                    if ( v1884[9] < 0 )
                    {
                      v1922 = 1;
                      v2745 = 1;
                    }
                    if ( v1922 && *v1884 == 1414090313 && v1884[1] == 1195525195 && (v1862[248] & v2873) != 0 )
                    {
                      v1922 = 0;
                      v2745 = 0;
                    }
                    v1923 = v1884[4];
                    v1924 = v1884[3];
                    v1925 = v2844;
                    v2727 = v1924;
                    if ( v1923 <= v1884[2] )
                      v1923 = v1884[2];
                    v1926 = v2854;
                    v1927 = v1923 + v1924;
                    v2758 = v1923 + v1924;
                    if ( v2844 == v2854 )
                    {
                      v1929 = 0;
                      v2817 = 0;
                      v1931 = 0;
                    }
                    else
                    {
                      v1928 = *(_QWORD *)v2844;
                      v1929 = *v2844 & 0xFFFFFFFE;
                      v2817 = v1929;
                      if ( (v2844[1] & 3) != 0 )
                        HIDWORD(v1928) = (HIDWORD(v1928) >> 2) & 0x7FF;
                      else
                        HIDWORD(v1928) = *(_DWORD *)(HIDWORD(v1928) + v1830) & 0x3FFFF;
                      v1930 = v1928 + 2 * HIDWORD(v1928);
                      v1926 = v2854;
                      v1931 = v1930 & 0xFFFFFFFE;
                    }
                    v1932 = v1884[3];
                    v2841 = v1932;
                    v2855 = v1931;
                    if ( v2844 == v1926 )
                    {
LABEL_2565:
                      _CF = v1929 >= v1924;
                    }
                    else
                    {
                      _CF = v1929 >= v1924;
                      if ( v1929 > v1924 )
                      {
                        if ( v1931 <= v1927 && !v1922 )
                        {
                          *v1878 = v1924;
                          v1878[1] = v1929;
                          v1934 = *v1878;
                          v1932 = v1929;
                          v2841 = v1929;
                          v1935 = (_DWORD *)(v1830 + v1934);
                          LODWORD(v1936) = v1929 - v1934;
                          v2782 = v1929 - v1934;
                          HIDWORD(v1936) = v1929 + v1830;
                          v1937 = 0;
                          while ( 1 )
                          {
                            v1938 = v2939[v1937];
                            if ( (unsigned int)v1935 < v2938[v1937] + v1938 && HIDWORD(v1936) > v1938 )
                              break;
                            if ( (unsigned int)++v1937 >= 4 )
                            {
                              v1939 = (char *)(v1830 + v1934);
                              if ( (unsigned int)v1935 < HIDWORD(v1936) )
                              {
                                do
                                {
                                  __pld(v1939);
                                  v1939 += 128;
                                }
                                while ( (unsigned int)v1939 < HIDWORD(v1936) );
                              }
                              v1940 = v1936;
                              HIDWORD(v1936) = v1862[211];
                              v1941 = v1862[210];
                              v2700 = v1936;
                              if ( (unsigned int)v1936 >= 8 )
                              {
                                v1942 = v1936;
                                v1943 = (unsigned int)v1936 >> 3;
                                v1944 = v1862[209] & 0x3F;
                                v1945 = 64 - v1944;
                                LOBYTE(v1936) = 32 - v1944;
                                do
                                {
                                  v1942 -= 8;
                                  v1946 = v1941 ^ *v1935;
                                  v1947 = v1935[1];
                                  v1935 += 2;
                                  HIDWORD(v1936) ^= v1947;
                                  v1948 = __PAIR64__(HIDWORD(v1936), v1946) << v1944;
                                  v1941 = (v1946 >> v1945) | (HIDWORD(v1936) << (v1944 - 32)) | (HIDWORD(v1936) >> v1936) | (v1946 << v1944);
                                  HIDWORD(v1936) = (HIDWORD(v1936) >> v1945) | HIDWORD(v1948);
                                  --v1943;
                                  LOBYTE(v1936) = 32 - v1944;
                                }
                                while ( v1943 );
                                v1862 = (_DWORD *)v2857;
                                v1929 = v2817;
                                v1884 = (int *)v2852;
                                v2700 = v1942;
                                v1830 = v2826;
                                v1940 = v2700;
                              }
                              if ( v1940 )
                              {
                                v1949 = v2700;
                                v1950 = v1862[209] & 0x3F;
                                v1951 = 64 - v1950;
                                do
                                {
                                  v1952 = *(unsigned __int8 *)v1935;
                                  v1935 = (_DWORD *)((char *)v1935 + 1);
                                  v1953 = v1941 ^ v1952;
                                  LODWORD(v1936) = (v1953 >> v1951) | (HIDWORD(v1936) << (v1950 - 32)) | (HIDWORD(v1936) >> (32 - v1950));
                                  HIDWORD(v1936) = (HIDWORD(v1936) >> v1951) | (__PAIR64__(HIDWORD(v1936), v1953) << v1950 >> 32);
                                  v1941 = v1936 | (v1953 << v1950);
                                  --v1949;
                                }
                                while ( v1949 );
                                v1862 = (_DWORD *)v2857;
                                v1830 = v2826;
                                v1929 = v2817;
                                v1884 = (int *)v2852;
                              }
                              LODWORD(v1936) = v1941;
                              v1862[214] += v2782;
                              while ( 1 )
                              {
                                LODWORD(v1936) = FsRtlPrivateResetHighestLockOffset(v1936, HIDWORD(v1936), 31);
                                if ( !v1936 )
                                  break;
                                v1941 ^= v1936;
                              }
                              v1954 = v1941 & 0x7FFFFFFF;
                              v1932 = v2841;
                              v2851[2] = v1954;
                              break;
                            }
                          }
                          v1925 = v2844;
                          v1926 = v2854;
                          v1924 = v2727;
                          v1927 = v2758;
                        }
                        goto LABEL_2565;
                      }
                    }
                    if ( _CF && v2855 <= v1927 && v1925 != v1926 )
                    {
                      v1955 = v2837;
                      v1956 = v2837[1];
                      v1957 = (v1956 & 3) != 0 ? (v1956 >> 2) & 0x7FF : *(_DWORD *)(v1956 + v1830) & 0x3FFFF;
                      v1958 = (*v2837 + 2 * v1957) & 0xFFFFFFFE;
                      v2806 = v1958;
                      if ( v1958 <= v1927 )
                      {
                        v1960 = v2853;
                        v1959 = v2854;
                        do
                        {
                          if ( v1955 == v1959 )
                            break;
                          if ( v2745 )
                          {
                            *v1960 = 0x80;
                          }
                          else
                          {
                            v1961 = v1925[1];
                            v1962 = (v1961 & 3) != 0 ? (v1961 >> 2) & 0x7FF : *(_DWORD *)(v1961 + v1830) & 0x3FFFF;
                            v1963 = (*v1925 + 2 * v1962) & 0xFFFFFFFE;
                            v1964 = (_DWORD *)(v1963 + v1830);
                            v1965 = *v1955 & 0xFFFFFFFE;
                            v1966 = v1965 - v1963;
                            v2855 = v1965 - v1963;
                            v1967 = v1965 + v1830;
                            v2841 = v1965;
                            for ( mm = 0; mm < 4; ++mm )
                            {
                              v1969 = v2939[mm];
                              if ( (unsigned int)v1964 < v2938[mm] + v1969 && v1967 > v1969 )
                                goto LABEL_2600;
                            }
                            if ( v1966 < 4 )
                            {
LABEL_2600:
                              v1988 = 0x80;
                              goto LABEL_2601;
                            }
                            v1970 = (char *)v1964;
                            if ( (unsigned int)v1964 < v1967 )
                            {
                              do
                              {
                                __pld(v1970);
                                v1970 += 128;
                              }
                              while ( (unsigned int)v1970 < v1967 );
                            }
                            v1971 = v1966;
                            v1972 = *((_QWORD *)v1862 + 105);
                            v2701 = v1966;
                            if ( v1966 >= 8 )
                            {
                              v1973 = v1966;
                              v1974 = v1966 >> 3;
                              v1975 = v1862[209] & 0x3F;
                              v1976 = 64 - v1975;
                              v1977 = 32 - v1975;
                              do
                              {
                                v1973 -= 8;
                                v1978 = v1972 ^ *v1964;
                                v1979 = v1964[1];
                                v1964 += 2;
                                v1980 = HIDWORD(v1972) ^ v1979;
                                v1981 = (v1978 >> v1976) | (v1980 << (v1975 - 32)) | (v1980 >> v1977);
                                HIDWORD(v1972) = (v1980 >> v1976) | (__PAIR64__(v1980, v1978) << v1975 >> 32);
                                LODWORD(v1972) = v1981 | (v1978 << v1975);
                                v1977 = 32 - v1975;
                                --v1974;
                              }
                              while ( v1974 );
                              v1862 = (_DWORD *)v2857;
                              v1966 = v2855;
                              v2701 = v1973;
                              v1830 = v2826;
                              v1971 = v2701;
                            }
                            if ( v1971 )
                            {
                              v1982 = v2701;
                              v1983 = v1862[209] & 0x3F;
                              v1984 = 64 - v1983;
                              do
                              {
                                v1985 = *(unsigned __int8 *)v1964;
                                v1964 = (_DWORD *)((char *)v1964 + 1);
                                v1986 = (v1972 ^ v1985) << v1983;
                                LODWORD(v1972) = ((v1985 ^ (unsigned int)v1972) >> v1984) | (HIDWORD(v1972) << (v1983 - 32)) | (HIDWORD(v1972) >> (32 - v1983)) | ((v1985 ^ (unsigned int)v1972) << v1983);
                                HIDWORD(v1972) = (HIDWORD(v1972) >> v1984) | HIDWORD(v1986);
                                --v1982;
                              }
                              while ( v1982 );
                              v1862 = (_DWORD *)v2857;
                              v1830 = v2826;
                              v1966 = v2855;
                            }
                            v1987 = v1972;
                            v1862[214] += v1966;
                            while ( 1 )
                            {
                              LODWORD(v1972) = FsRtlPrivateResetHighestLockOffset(v1972, HIDWORD(v1972), 7);
                              if ( !v1972 )
                                break;
                              v1987 ^= v1972;
                            }
                            v1960 = v2853;
                            v1988 = v1987 & 0x7F;
                            v1955 = v2837;
LABEL_2601:
                            v1927 = v2758;
                            v1925 = v2844;
                            *v1960 = v1988;
                            v1958 = v2806;
                          }
                          v1959 = v2854;
                          v1925 += 2;
                          ++v1960;
                          v1955 += 2;
                          v2844 = v1925;
                          v2853 = v1960;
                          v2837 = v1955;
                          if ( v1955 != v2854 )
                          {
                            v1989 = v1955[1];
                            if ( (v1989 & 3) != 0 )
                              v1990 = (v1989 >> 2) & 0x7FF;
                            else
                              v1990 = *(_DWORD *)(v1989 + v1830) & 0x3FFFF;
                            v1958 = (*v1955 + 2 * v1990) & 0xFFFFFFFE;
                            v1959 = v2854;
                            v2806 = v1958;
                          }
                        }
                        while ( v1958 <= v1927 );
                        v1884 = (int *)v2852;
                        v1932 = v2841;
                      }
                    }
                    v1991 = v2851;
                    if ( !v2745 && v1932 != v1927 )
                    {
                      v2851[3] = v1932;
                      v1991[4] = v1927;
                      v1992 = v1991[3];
                      v1993 = (_DWORD *)(v1992 + v1830);
                      LODWORD(v1994) = v1927 - v1992;
                      v2783 = v1927 - v1992;
                      HIDWORD(v1994) = v1927 + v1830;
                      v1995 = 0;
                      while ( 1 )
                      {
                        v1996 = v2939[v1995];
                        if ( (unsigned int)v1993 < v2938[v1995] + v1996 && HIDWORD(v1994) > v1996 )
                          break;
                        if ( (unsigned int)++v1995 >= 4 )
                        {
                          v1997 = (char *)(v1992 + v1830);
                          if ( (unsigned int)v1993 < HIDWORD(v1994) )
                          {
                            do
                            {
                              __pld(v1997);
                              v1997 += 128;
                            }
                            while ( (unsigned int)v1997 < HIDWORD(v1994) );
                          }
                          HIDWORD(v1994) = v1862[211];
                          v1998 = v1862[210];
                          v1999 = v1994;
                          if ( (unsigned int)v1994 >= 8 )
                          {
                            v2000 = v1862[209];
                            v2001 = (unsigned int)v1994 >> 3;
                            v2002 = v2000 & 0x3F;
                            v2003 = 64 - (v2000 & 0x3F);
                            v2004 = (v2000 & 0x3F) - 32;
                            LOBYTE(v1994) = 32 - (v2000 & 0x3F);
                            do
                            {
                              v1999 -= 8;
                              v2005 = v1998 ^ *v1993;
                              v2006 = v1993[1];
                              v1993 += 2;
                              HIDWORD(v1994) ^= v2006;
                              v2007 = __PAIR64__(HIDWORD(v1994), v2005) << v2002;
                              v1998 = (v2005 >> v2003) | (HIDWORD(v1994) << v2004) | (HIDWORD(v1994) >> v1994) | (v2005 << v2002);
                              HIDWORD(v1994) = (HIDWORD(v1994) >> v2003) | HIDWORD(v2007);
                              --v2001;
                              LOBYTE(v1994) = v2003 - 32;
                            }
                            while ( v2001 );
                            v1862 = (_DWORD *)v2857;
                            v1830 = v2826;
                            v1884 = (int *)v2852;
                          }
                          if ( v1999 )
                          {
                            v2008 = v1862[209] & 0x3F;
                            v2009 = 64 - v2008;
                            do
                            {
                              v2010 = *(unsigned __int8 *)v1993;
                              v1993 = (_DWORD *)((char *)v1993 + 1);
                              v2011 = v1998 ^ v2010;
                              LODWORD(v1994) = (v2011 >> v2009) | (HIDWORD(v1994) << (v2008 - 32)) | (HIDWORD(v1994) >> (32 - v2008));
                              HIDWORD(v1994) = (HIDWORD(v1994) >> v2009) | (__PAIR64__(HIDWORD(v1994), v2011) << v2008 >> 32);
                              v1998 = v1994 | (v2011 << v2008);
                              --v1999;
                            }
                            while ( v1999 );
                            v1862 = (_DWORD *)v2857;
                            v1830 = v2826;
                            v1884 = (int *)v2852;
                          }
                          LODWORD(v1994) = v1998;
                          v1862[214] += v2783;
                          while ( 1 )
                          {
                            LODWORD(v1994) = FsRtlPrivateResetHighestLockOffset(v1994, HIDWORD(v1994), 31);
                            if ( !v1994 )
                              break;
                            v1998 ^= v1994;
                          }
                          v1991 = v2851;
                          v2851[5] = v1998 & 0x7FFFFFFF;
                          break;
                        }
                      }
                    }
                    v2012 = v2844;
                    if ( v2844 != v2854 )
                    {
                      v2013 = *(_QWORD *)v2844;
                      HIDWORD(v2013) = (v2844[1] & 3) != 0 ? (HIDWORD(v2013) >> 2) & 0x7FF : *(_DWORD *)(HIDWORD(v2013) + v1830) & 0x3FFFF;
                      v2014 = (v2013 + 2 * HIDWORD(v2013)) & 0xFFFFFFFE;
                      if ( (*v2844 & 0xFFFFFFFE) >= v2727 && v2014 <= v2758 )
                      {
                        if ( v2837 != v2854 )
                        {
                          v2015 = v2853;
                          *v2853 = 0x80;
                          v2837 += 2;
                          v2853 = v2015 + 1;
                        }
                        v2844 = v2012 + 2;
                      }
                    }
                    v1878 = v1991 + 6;
                    v1884 += 10;
                    v2851 = v1878;
                    v2852 = (unsigned int)v1884;
                    if ( v1878 == (int *)v2859 )
                    {
                      v1618 = (_DWORD *)v2846;
                      goto LABEL_2640;
                    }
                    continue;
                  }
                }
                v2857 = 0;
                v1462 = (_BYTE *)v140;
                v2803 = (char *)(*(_DWORD *)(v140 + 676) + 16);
                if ( (int)v1289 < 2 )
                {
                  v1463 = *(_DWORD *)(*(_DWORD *)(v140 + 676) + 24);
                  v1464 = *(_DWORD **)(*(_DWORD *)(v140 + 676) + 16);
                  v1465 = *(_DWORD *)(v140 + 992);
                  v1466 = *(_DWORD *)(v140 + 796);
                  v1467 = *(_DWORD *)(v140 + 928);
                  v1468 = 4 * v1463;
                  v1469 = v140;
                  if ( (v1465 & 0x20000000) == 0 )
                    v1469 = 0;
                  v2842 = 4 * v1463;
                  if ( v1467 <= 1 )
                  {
                    if ( v1469 )
                    {
                      v1470 = *(_DWORD *)(v1469 + 812);
LABEL_1894:
                      v1471 = (_DWORD *(__fastcall *)(int, int))((v1470 | 1) + v1469);
                    }
                    else
                    {
                      v1471 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                    }
                  }
                  else
                  {
                    if ( v1469 )
                    {
                      v1470 = *(_DWORD *)(v1469 + 816);
                      goto LABEL_1894;
                    }
                    v1471 = sub_5FD658;
                  }
                  if ( (v1465 & 4) == 0 )
                    v1471 = *(_DWORD *(__fastcall **)(int, int))(v140 + 1080);
                  v1462 = v1471(v140, v1466 + 40);
                  if ( v1462 )
                  {
                    v1472 = *(_DWORD *)(v140 + 992);
                    if ( (v1472 & 4) == 0 )
                    {
                      v1473 = *(_DWORD *)(v140 + 796);
                      v1474 = *(_DWORD *)(v140 + 928);
                      v1475 = *(_DWORD *)(v140 + 780);
                      if ( (v1472 & 0x20000000) == 0 )
                        v1474 = 0;
                      if ( v1473 >= 4 )
                      {
                        v1476 = v1473 >> 2;
                        do
                        {
                          v1473 -= 4;
                          --v1476;
                          *(_DWORD *)v140 = 0;
                          v140 += 4;
                        }
                        while ( v1476 );
                      }
                      for ( ; v1473; --v1473 )
                        *(_BYTE *)v140++ = 0;
                      v1477 = *((_DWORD *)v1462 + 232);
                      *((_DWORD *)v1462 + 232) = v1474;
                      if ( v1474 == 3 )
                      {
                        (*((void (__fastcall **)(int))v1462 + 124))(v1475);
                      }
                      else
                      {
                        v1478 = (void (__fastcall *)(_DWORD))*((_DWORD *)v1462 + 55);
                        if ( v1474 && v1474 == 1 )
                          (*((void (__fastcall **)(int, _DWORD, int, void (__fastcall *)(_DWORD)))v1462 + 87))(
                            v1475 - 4,
                            *(_DWORD *)(v1475 - 4),
                            1,
                            v1478);
                        else
                          v1478(v1475);
                      }
                      *((_DWORD *)v1462 + 232) = v1477;
                    }
                    v1479 = &v1462[v1466];
                    v1480 = 10;
                    *((_DWORD *)v1462 + 248) &= 0xFFFFFFFB;
                    v1481 = &v1462[v1466];
                    ++*((_DWORD *)v1462 + 207);
                    v1482 = 40;
                    do
                    {
                      v1482 -= 4;
                      --v1480;
                      *v1481++ = 0;
                    }
                    while ( v1480 );
                    for ( ; v1482; --v1482 )
                    {
                      *(_BYTE *)v1481 = 0;
                      v1481 = (_DWORD *)((char *)v1481 + 1);
                    }
                    *v1479 = 11;
                    v1479[1] = v1464;
                    v1479[2] = v1468;
                    v1483 = (char *)v1464;
                    if ( v1464 < (_DWORD *)((char *)v1464 + v1468) )
                    {
                      do
                      {
                        __pld(v1483);
                        v1483 += 128;
                      }
                      while ( v1483 < (char *)v1464 + v1468 );
                    }
                    HIDWORD(v1484) = *((_DWORD *)v1462 + 211);
                    v1485 = *((_DWORD *)v1462 + 210);
                    v1486 = v1468;
                    if ( v1468 >= 8 )
                    {
                      v1487 = *((_DWORD *)v1462 + 209) & 0x3F;
                      v1488 = 64 - v1487;
                      LOBYTE(v1484) = 32 - v1487;
                      v1489 = v1468 >> 3;
                      do
                      {
                        v1486 -= 8;
                        v1490 = v1485 ^ *v1464;
                        v1491 = v1464[1];
                        v1464 += 2;
                        HIDWORD(v1484) ^= v1491;
                        v1492 = __PAIR64__(HIDWORD(v1484), v1490) << v1487;
                        v1485 = (v1490 >> v1488) | (HIDWORD(v1484) << (v1487 - 32)) | (HIDWORD(v1484) >> v1484) | (v1490 << v1487);
                        HIDWORD(v1484) = (HIDWORD(v1484) >> v1488) | HIDWORD(v1492);
                        --v1489;
                        LOBYTE(v1484) = 32 - v1487;
                      }
                      while ( v1489 );
                      v1468 = v2842;
                    }
                    if ( v1486 )
                    {
                      v1493 = *((_DWORD *)v1462 + 209) & 0x3F;
                      v1494 = 64 - v1493;
                      do
                      {
                        v1495 = *(unsigned __int8 *)v1464;
                        v1464 = (_DWORD *)((char *)v1464 + 1);
                        v1496 = v1485 ^ v1495;
                        LODWORD(v1484) = (v1496 >> v1494) | (HIDWORD(v1484) << (v1493 - 32)) | (HIDWORD(v1484) >> (32 - v1493));
                        HIDWORD(v1484) = (HIDWORD(v1484) >> v1494) | (__PAIR64__(HIDWORD(v1484), v1496) << v1493 >> 32);
                        v1485 = v1484 | (v1496 << v1493);
                        --v1486;
                      }
                      while ( v1486 );
                      v1468 = v2842;
                    }
                    LODWORD(v1484) = v1485;
                    *((_DWORD *)v1462 + 214) += v1468;
                    while ( 1 )
                    {
                      LODWORD(v1484) = FsRtlPrivateResetHighestLockOffset(v1484, HIDWORD(v1484), 31);
                      if ( !v1484 )
                        break;
                      v1485 ^= v1484;
                    }
                    v1286 = v1462;
                    LODWORD(v1289) = &v1462[v1466];
                    *(_DWORD *)&v1462[v1466 + 12] = v1485 & 0x7FFFFFFF;
                    HIDWORD(v1289) = *((_DWORD *)v1462 + 214);
                    v2850 = v1462;
                    *((_DWORD *)v1462 + 214) = HIDWORD(v1289) + v1468;
                    *((_DWORD *)v1462 + 238) = 2;
                    goto LABEL_1932;
                  }
LABEL_2038:
                  v1572 = -1073741267;
LABEL_2040:
                  v140 = (unsigned int)v1286;
                  if ( v1572 < 0 )
                    goto LABEL_2033;
                  goto LABEL_2041;
                }
LABEL_1932:
                if ( *((int *)v1462 + 238) < 3 )
                {
                  v1497 = *((_DWORD *)v1462 + 248);
                  v1498 = *((_DWORD *)v1462 + 199);
                  v1499 = v1462;
                  if ( (v1497 & 0x20000000) == 0 )
                    v1499 = 0;
                  if ( *((int *)v1462 + 232) <= 1 )
                  {
                    if ( v1499 )
                    {
                      v1500 = *((_DWORD *)v1499 + 203);
LABEL_1941:
                      v1501 = (_DWORD *(__fastcall *)(int, int))&v1499[v1500 | 1];
                    }
                    else
                    {
                      v1501 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                    }
                  }
                  else
                  {
                    if ( v1499 )
                    {
                      v1500 = *((_DWORD *)v1499 + 204);
                      goto LABEL_1941;
                    }
                    v1501 = sub_5FD658;
                  }
                  if ( (v1497 & 4) == 0 )
                    v1501 = (_DWORD *(__fastcall *)(int, int))*((_DWORD *)v1462 + 270);
                  v1502 = v1501((int)v1462, v1498 + 40);
                  v2842 = (unsigned int)v1502;
                  if ( !v1502 )
                    goto LABEL_2038;
                  v1503 = *((_DWORD *)v1462 + 248);
                  if ( (v1503 & 4) == 0 )
                  {
                    v1504 = *((_DWORD *)v1462 + 199);
                    v1505 = *((_DWORD *)v1462 + 232);
                    v1506 = *((_DWORD *)v1462 + 195);
                    if ( (v1503 & 0x20000000) == 0 )
                      v1505 = 0;
                    if ( v1504 >= 4 )
                    {
                      v1507 = v1504 >> 2;
                      do
                      {
                        v1504 -= 4;
                        --v1507;
                        *(_DWORD *)v1462 = 0;
                        v1462 += 4;
                      }
                      while ( v1507 );
                    }
                    for ( ; v1504; --v1504 )
                      *v1462++ = 0;
                    v1508 = v1502[232];
                    v1502[232] = v1505;
                    if ( v1505 == 3 )
                    {
                      v1509 = (void (__fastcall *)(_DWORD))v1502[124];
                    }
                    else
                    {
                      v1509 = (void (__fastcall *)(_DWORD))v1502[55];
                      if ( v1505 && v1505 == 1 )
                      {
                        ((void (__fastcall *)(int, _DWORD, int, void (__fastcall *)(int)))v1502[87])(
                          v1506 - 4,
                          *(_DWORD *)(v1506 - 4),
                          1,
                          v1509);
                        goto LABEL_1960;
                      }
                    }
                    v1509(v1506);
LABEL_1960:
                    v1502[232] = v1508;
                  }
                  v1502[248] &= 0xFFFFFFFB;
                  v1510 = v1502[207];
                  v1511 = (char *)v1502 + v1498;
                  jj = (unsigned int)v1502 + v1498;
                  v1502[207] = v1510 + 1;
                  v1512 = 40;
                  v1513 = 0xA00000000i64;
                  v1514 = (_DWORD *)((char *)v1502 + v1498);
                  do
                  {
                    v1512 -= 4;
                    --HIDWORD(v1513);
                    *v1514++ = 0;
                  }
                  while ( HIDWORD(v1513) );
                  for ( ; v1512; --v1512 )
                  {
                    *(_BYTE *)v1514 = 0;
                    v1514 = (_DWORD *)((char *)v1514 + 1);
                  }
                  HIDWORD(v1513) = v2803;
                  *(_QWORD *)v1511 = v1513;
                  *((_DWORD *)v1511 + 2) = 16;
                  v1515 = v2803;
                  v1516 = v2803;
                  if ( HIDWORD(v1513) < HIDWORD(v1513) + 16 )
                  {
                    do
                    {
                      __pld(v1515);
                      v1515 += 128;
                    }
                    while ( v1515 < v2803 + 16 );
                  }
                  v1517 = v1502[210];
                  HIDWORD(v1521) = v1502[211];
                  v1518 = 16;
                  v1519 = *(_QWORD *)(v1502 + 209) & 0x3F;
                  v1520 = 64 - v1519;
                  LOBYTE(v1521) = 32 - v1519;
                  v1522 = 2;
                  do
                  {
                    v1518 -= 8;
                    v1523 = v1517 ^ *v1516;
                    v1524 = v1516[1];
                    v1516 += 2;
                    HIDWORD(v1521) ^= v1524;
                    v1525 = __PAIR64__(HIDWORD(v1521), v1523) << v1519;
                    v1517 = (v1523 >> v1520) | (HIDWORD(v1521) << (v1519 - 32)) | (HIDWORD(v1521) >> v1521) | (v1523 << v1519);
                    HIDWORD(v1521) = (HIDWORD(v1521) >> v1520) | HIDWORD(v1525);
                    --v1522;
                    LOBYTE(v1521) = 32 - v1519;
                  }
                  while ( v1522 );
                  v1526 = (_DWORD *)v2842;
                  v1527 = jj;
                  if ( v1518 )
                  {
                    do
                    {
                      v1528 = *(unsigned __int8 *)v1516;
                      v1516 = (_DWORD *)((char *)v1516 + 1);
                      v1529 = v1517 ^ v1528;
                      LODWORD(v1521) = __PAIR64__(HIDWORD(v1521), v1529) >> v1520;
                      HIDWORD(v1521) = (HIDWORD(v1521) >> v1520) | (__PAIR64__(HIDWORD(v1521), v1529) << v1519 >> 32);
                      v1517 = v1521 | (v1529 << v1519);
                      --v1518;
                    }
                    while ( v1518 );
                    v1526 = (_DWORD *)v2842;
                    v1527 = jj;
                  }
                  LODWORD(v1521) = v1517;
                  v1526[214] += 16;
                  while ( 1 )
                  {
                    LODWORD(v1521) = FsRtlPrivateResetHighestLockOffset(v1521, HIDWORD(v1521), 31);
                    if ( !v1521 )
                      break;
                    v1517 ^= v1521;
                  }
                  *(_DWORD *)(v1527 + 12) = v1517 & 0x7FFFFFFF;
                  v1462 = v1526;
                  v1286 = v1526;
                  v1526[214] += 16;
                  v1526[238] = 3;
                  v2850 = v1526;
                }
                v1530 = 0;
                v2814 = *(int **)v2803;
                if ( *((_DWORD *)v2803 + 2) )
                {
                  v1531 = *(int **)v2803;
                  do
                  {
                    v1532 = *v1531++;
                    v1533 = (*((int (__fastcall **)(int, char *, _DWORD))v1462 + 93))(
                              (int)v2814 + (v1532 >> 4),
                              v2947,
                              0);
                    v1534 = v2857;
                    if ( !v1533 )
                      v1534 = ++v2857;
                    ++v1530;
                  }
                  while ( v1530 < *((_DWORD *)v2803 + 2) );
                  v1286 = v2850;
                  if ( v1534 )
                  {
                    v1535 = *((_DWORD *)v1462 + 248);
                    v1536 = *((_DWORD *)v1462 + 199);
                    v1537 = v1462;
                    if ( (v1535 & 0x20000000) == 0 )
                      v1537 = 0;
                    if ( *((int *)v1462 + 232) <= 1 )
                    {
                      if ( v1537 )
                      {
                        v1538 = *((_DWORD *)v1537 + 203);
LABEL_1990:
                        v1539 = (_DWORD *(__fastcall *)(int, int))&v1537[v1538 | 1];
                      }
                      else
                      {
                        v1539 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
                      }
                    }
                    else
                    {
                      if ( v1537 )
                      {
                        v1538 = *((_DWORD *)v1537 + 204);
                        goto LABEL_1990;
                      }
                      v1539 = sub_5FD658;
                    }
                    if ( (v1535 & 4) == 0 )
                      v1539 = (_DWORD *(__fastcall *)(int, int))*((_DWORD *)v1462 + 270);
                    v140 = (unsigned int)v1539((int)v1462, v1536 + 12 * v1534 + 40);
                    v2735 = v140;
                    if ( !v140 )
                      goto LABEL_2038;
                    v1540 = *((_DWORD *)v1462 + 248);
                    if ( (v1540 & 4) == 0 )
                    {
                      v1541 = *((_DWORD *)v1462 + 199);
                      v1542 = *((_DWORD *)v1462 + 232);
                      v1543 = *((_DWORD *)v1462 + 195);
                      if ( (v1540 & 0x20000000) == 0 )
                        v1542 = 0;
                      if ( v1541 >= 4 )
                      {
                        v1544 = v1541 >> 2;
                        do
                        {
                          v1541 -= 4;
                          --v1544;
                          *(_DWORD *)v1462 = 0;
                          v1462 += 4;
                        }
                        while ( v1544 );
                      }
                      for ( ; v1541; --v1541 )
                        *v1462++ = 0;
                      v1545 = *(_DWORD *)(v140 + 928);
                      *(_DWORD *)(v140 + 928) = v1542;
                      if ( v1542 == 3 )
                      {
                        v1546 = *(void (__fastcall **)(_DWORD))(v140 + 496);
                      }
                      else
                      {
                        v1546 = *(void (__fastcall **)(_DWORD))(v140 + 220);
                        if ( v1542 && v1542 == 1 )
                        {
                          (*(void (__fastcall **)(int, _DWORD, int, void (__fastcall *)(int)))(v140 + 348))(
                            v1543 - 4,
                            *(_DWORD *)(v1543 - 4),
                            1,
                            v1546);
                          goto LABEL_2009;
                        }
                      }
                      v1546(v1543);
LABEL_2009:
                      *(_DWORD *)(v140 + 928) = v1545;
                    }
                    v1547 = (int *)(v1536 + v140);
                    v1548 = 10;
                    *(_DWORD *)(v140 + 992) &= 0xFFFFFFFB;
                    v1549 = *(_DWORD *)(v140 + 828);
                    v2859 = (unsigned int)v1547;
                    v1550 = v1547;
                    *(_DWORD *)(v140 + 828) = v1549 + 1;
                    v1551 = 40;
                    do
                    {
                      v1551 -= 4;
                      --v1548;
                      *v1550++ = 0;
                    }
                    while ( v1548 );
                    for ( ; v1551; --v1551 )
                    {
                      *(_BYTE *)v1550 = 0;
                      v1550 = (_DWORD *)((char *)v1550 + 1);
                    }
                    *v1547 = 10;
                    v1547[1] = 0;
                    v1547[2] = 0;
                    HIDWORD(v1553) = *(_DWORD *)(v140 + 844);
                    v1552 = *(_DWORD *)(v140 + 840);
                    LODWORD(v1553) = v1552;
                    while ( 1 )
                    {
                      LODWORD(v1553) = FsRtlPrivateResetHighestLockOffset(v1553, HIDWORD(v1553), 31);
                      if ( !v1553 )
                        break;
                      v1552 ^= v1553;
                    }
                    v1547[3] = v1552 & 0x7FFFFFFF;
                    v1547[4] = 1;
                    v1547[5] = v1534;
                    v1554 = *((_DWORD *)v2803 + 2);
                    v1462 = (_BYTE *)v140;
                    v1555 = 0;
                    v2697 = (_BYTE *)v140;
                    v1286 = (_BYTE *)v140;
                    v2850 = (_DWORD *)v140;
                    v2842 = (unsigned int)(v1547 + 10);
                    jj = 0;
                    if ( v1554 )
                    {
                      v1556 = v2814;
                      LODWORD(v1289) = v2814;
                      do
                      {
                        v1557 = (unsigned int)v1556 + (*(int *)v1289 >> 4);
                        HIDWORD(v1289) = *(_DWORD *)(v140 + 372);
                        v2847 = v1289 + 4;
                        v2845 = v1557;
                        if ( !((int (__fastcall *)(unsigned int, char *, _DWORD))HIDWORD(v1289))(v1557, v2947, 0) )
                        {
                          v1558 = (v1557 & 0xFFFFFFFE) + 4;
                          v1559 = (char *)(v1557 & 0xFFFFFFFE);
                          if ( (v1557 & 0xFFFFFFFE) < v1558 )
                          {
                            do
                            {
                              __pld(v1559);
                              v1559 += 128;
                            }
                            while ( (unsigned int)v1559 < v1558 );
                          }
                          v1561 = *(_DWORD *)(v140 + 840);
                          v1560 = *(_DWORD *)(v140 + 836);
                          HIDWORD(v1562) = *(_DWORD *)(v140 + 844);
                          v1563 = (unsigned __int8 *)(v1557 & 0xFFFFFFFE);
                          v1564 = v1560 & 0x3F;
                          v1565 = 64 - (v1560 & 0x3F);
                          v1566 = 4;
                          do
                          {
                            v1567 = *v1563++;
                            v1568 = v1561 ^ v1567;
                            LODWORD(v1562) = (v1568 >> v1565) | (HIDWORD(v1562) << ((v1560 & 0x3F) - 32)) | (HIDWORD(v1562) >> (32 - (v1560 & 0x3F)));
                            HIDWORD(v1562) = (HIDWORD(v1562) >> v1565) | (__PAIR64__(HIDWORD(v1562), v1568) << v1564 >> 32);
                            v1561 = v1562 | (v1568 << v1564);
                            --v1566;
                          }
                          while ( v1566 );
                          v140 = v2735;
                          v1286 = v2850;
                          v1462 = v2697;
                          v1547 = (int *)v2859;
                          v1569 = (_DWORD *)v2842;
                          *(_DWORD *)(v2735 + 856) += 4;
                          LODWORD(v1562) = v1561;
                          while ( 1 )
                          {
                            LODWORD(v1562) = FsRtlPrivateResetHighestLockOffset(v1562, HIDWORD(v1562), 31);
                            if ( !v1562 )
                              break;
                            v1561 ^= v1562;
                          }
                          LODWORD(v1289) = v2845;
                          *v1569 = *v1569 & 0x80000000 | v1561 & 0x7FFFFFFF;
                          v1569[1] = 4;
                          v1569[2] = v1289 & 0xFFFFFFFE;
                          v2842 = (unsigned int)(v1569 + 3);
                          if ( !--v2857 )
                            goto LABEL_2039;
                          v1555 = jj;
                        }
                        v1556 = v2814;
                        ++v1555;
                        LODWORD(v1289) = v2847;
                        HIDWORD(v1289) = *((_DWORD *)v2803 + 2);
                        jj = v1555;
                      }
                      while ( v1555 < HIDWORD(v1289) );
                    }
                    if ( v2857 )
                    {
                      if ( !*(_DWORD *)(v140 + 880) )
                      {
                        *(_DWORD *)(v140 + 888) = v140 - 1849117464;
                        *(_DWORD *)(v140 + 892) = 0;
                        *(_DWORD *)(v140 + 896) = (char *)v1547 - 465226731;
                        *(_DWORD *)(v140 + 900) = 0;
                        v1289 = *v1547;
                        *(_QWORD *)(v140 + 904) = v1289;
                        *(_DWORD *)(v140 + 912) = 0;
                        *(_DWORD *)(v140 + 916) = 0;
                        *(_DWORD *)(v140 + 880) = 1;
                      }
                      goto LABEL_2033;
                    }
                  }
                }
LABEL_2039:
                *((_DWORD *)v1462 + 238) = 4;
                v1572 = 0;
                goto LABEL_2040;
              }
            }
          }
          v2883 = -2036429648;
          v1352 = -2036429648;
LABEL_1731:
          v1353 = 9;
        }
        else
        {
          v2883 = -1333354875;
          v1352 = -1333354868;
LABEL_1775:
          v1353 = 1;
        }
LABEL_1725:
        v1351 = __ROR4__(v1352, v1353);
        goto LABEL_1779;
      case 0xAu:
        v1365 = __mrc(15, 0, 9, 13, 0);
        v1366 = v1365 << 29;
        v1367 = v1365 ^ (v1365 >> 3);
        v1368 = 67117057i64 * (unsigned int)v1367;
        v1369 = 1880096896 * v1366 + ((67117057i64 * v1366 + 1880096896 * (unsigned __int64)(unsigned int)v1367) >> 32);
        if ( (0x7010008004002001i64 * __PAIR64__(v1366, v1367)) >> 32 < HIDWORD(v1368) )
          ++v1369;
        v1370 = ((unsigned int)v1368 ^ v1369) >> 5;
        v1371 = FsRtlRemovePerStreamContextEx(26i64, (unsigned int)v1368 ^ (unsigned __int64)v1369);
        v1372 = FsRtlRemovePerStreamContextEx(26i64, v1370);
        v1370 >>= 5;
        v1373 = v1372;
        v1374 = FsRtlRemovePerStreamContextEx(26i64, v1370);
        v1351 = ((v1371 + 97) << 24) | ((v1374 + 97) << 8) | ((v1373 + 65) << 16) | (FsRtlRemovePerStreamContextEx(
                                                                                       26i64,
                                                                                       v1370 >> 5)
                                                                                   + 65);
        goto LABEL_1779;
    }
  }
LABEL_2669:
  if ( (*(_DWORD *)(v140 + 992) & v2871) != 0 )
  {
    v2027 = *(_DWORD *)(v140 + 1000);
    if ( (*(int (__fastcall **)(int))(v140 + 516))(v2027) && !*(_DWORD *)(v140 + 880) )
    {
      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
      *(_DWORD *)(v140 + 892) = 0;
      *(_DWORD *)(v140 + 896) = 0;
      *(_DWORD *)(v140 + 900) = 0;
      *(_DWORD *)(v140 + 904) = 272;
      *(_DWORD *)(v140 + 908) = 0;
      *(_DWORD *)(v140 + 912) = 0;
      *(_DWORD *)(v140 + 916) = 0;
      *(_DWORD *)(v140 + 880) = 1;
    }
    (*(void (__fastcall **)(int, int (__fastcall *)(int, int, _DWORD *), unsigned int, _DWORD))(v140 + 512))(
      v2027,
      sub_5FEC3C,
      v140,
      0);
  }
  if ( (*(_DWORD *)(v140 + 992) & 0x40000) != 0 )
  {
    v2028 = __mrc(15, 0, 9, 13, 0);
    v2029 = v2028 << 29;
    v2030 = v2028 ^ (v2028 >> 3);
    v2031 = 67117057i64 * (unsigned int)v2030;
    v2032 = 67117057i64 * v2029 + 1880096896i64 * (unsigned int)v2030;
    v2033 = (1880096896i64 * v2029 + (unsigned __int64)HIDWORD(v2032)) >> 32;
    v2034 = 1880096896 * v2029 + HIDWORD(v2032);
    if ( (unsigned int)(v2032 + HIDWORD(v2031)) < HIDWORD(v2031) )
      v2033 = (__PAIR64__(v2033, v2034++) + 1) >> 32;
    LODWORD(v2035) = v2031 ^ v2034;
    HIDWORD(v2035) = (v2032 + HIDWORD(v2031)) ^ v2033;
    if ( (unsigned __int64)FsRtlRemovePerStreamContextEx(10i64, v2035) < 2 && !*(_DWORD *)(v140 + 880) )
    {
      *(_DWORD *)(v140 + 888) = v140 - 1849117464;
      *(_DWORD *)(v140 + 892) = 0;
      *(_DWORD *)(v140 + 896) = 0;
      *(_DWORD *)(v140 + 900) = 0;
      *(_DWORD *)(v140 + 904) = 264;
      *(_DWORD *)(v140 + 908) = 0;
      *(_DWORD *)(v140 + 912) = 0;
      *(_DWORD *)(v140 + 916) = 0;
      *(_DWORD *)(v140 + 880) = 1;
    }
  }
  if ( (*(_DWORD *)(v140 + 992) & 0x8000) != 0 || !*(_DWORD *)(v140 + 880) )
  {
    v2036 = *(_DWORD *)(v140 + 1072);
    if ( v2036 )
    {
      v2037 = (int *)(v140 + v2036);
      v2038 = *(_DWORD **)(v140 + v2036 + 4);
      v2843 = (unsigned int *)(v140 + v2036);
      if ( v2038 )
      {
        if ( *v2037 != 11 || *(_DWORD *)(v140 + 988) )
        {
          v2040 = (char *)v2038;
          v2855 = v2037[2];
          v2039 = v2855;
          if ( v2038 < (_DWORD *)((char *)v2038 + v2855) )
          {
            do
            {
              __pld(v2040);
              v2040 += 128;
            }
            while ( v2040 < (char *)v2038 + v2855 );
          }
          HIDWORD(v2041) = *(_DWORD *)(v140 + 844);
          v2042 = *(_DWORD *)(v140 + 840);
          v2043 = v2855;
          if ( v2855 >= 8 )
          {
            v2044 = *(_DWORD *)(v140 + 836) & 0x3F;
            v2045 = 64 - v2044;
            LOBYTE(v2041) = 32 - v2044;
            v2046 = v2855 >> 3;
            do
            {
              v2043 -= 8;
              v2047 = v2042 ^ *v2038;
              v2048 = v2038[1];
              v2038 += 2;
              HIDWORD(v2041) ^= v2048;
              v2049 = __PAIR64__(HIDWORD(v2041), v2047) << v2044;
              v2042 = (v2047 >> v2045) | (HIDWORD(v2041) << (v2044 - 32)) | (HIDWORD(v2041) >> v2041) | (v2047 << v2044);
              HIDWORD(v2041) = (HIDWORD(v2041) >> v2045) | HIDWORD(v2049);
              --v2046;
              LOBYTE(v2041) = 32 - v2044;
            }
            while ( v2046 );
            v140 = (unsigned int)v2734;
            v2037 = (int *)v2843;
            v2039 = v2855;
          }
          if ( v2043 )
          {
            v2050 = *(_DWORD *)(v140 + 836) & 0x3F;
            v2051 = 64 - v2050;
            do
            {
              v2052 = *(unsigned __int8 *)v2038;
              v2038 = (_DWORD *)((char *)v2038 + 1);
              v2053 = v2042 ^ v2052;
              LODWORD(v2041) = (v2053 >> v2051) | (HIDWORD(v2041) << (v2050 - 32)) | (HIDWORD(v2041) >> (32 - v2050));
              HIDWORD(v2041) = (HIDWORD(v2041) >> v2051) | (__PAIR64__(HIDWORD(v2041), v2053) << v2050 >> 32);
              v2042 = v2041 | (v2053 << v2050);
              --v2043;
            }
            while ( v2043 );
            v140 = (unsigned int)v2734;
            v2037 = (int *)v2843;
            v2039 = v2855;
          }
          LODWORD(v2041) = v2042;
          *(_DWORD *)(v140 + 856) += v2039;
          while ( 1 )
          {
            LODWORD(v2041) = FsRtlPrivateResetHighestLockOffset(v2041, HIDWORD(v2041), 31);
            if ( !v2041 )
              break;
            v2042 ^= v2041;
          }
          v2054 = v2037[3];
          if ( (v2042 & 0x7FFFFFFF) != v2054 )
          {
            if ( !*(_DWORD *)(v140 + 880) )
            {
              v2055 = *(_DWORD *)(v140 + 688);
              *(_DWORD *)(v2055 + 16) = v2042 & 0x7FFFFFFF ^ v2054;
              *(_DWORD *)(v2055 + 20) = 0;
            }
            v2056 = v2037[1];
            if ( !*(_DWORD *)(v140 + 880) )
            {
              *(_DWORD *)(v140 + 888) = v140 - 1849117464;
              *(_DWORD *)(v140 + 892) = 0;
              *(_DWORD *)(v140 + 896) = (char *)v2037 - 465226731;
              *(_DWORD *)(v140 + 900) = 0;
              *(_QWORD *)(v140 + 904) = *v2037;
              *(_DWORD *)(v140 + 912) = v2056;
              *(_DWORD *)(v140 + 916) = 0;
              *(_DWORD *)(v140 + 880) = 1;
            }
          }
        }
        v2057 = *(_DWORD *)(v140 + 928);
        v2058 = v2037[4];
        v2059 = *(void (__fastcall **)(_DWORD))(v140 + 220);
        if ( v2057 && v2057 == 1 )
          (*(void (__fastcall **)(int, _DWORD, void (__fastcall *)(int)))(v140 + 348))(
            v2058 - 4,
            *(_DWORD *)(v2058 - 4),
            v2059);
        else
          v2059(v2058);
        v2037[1] = 0;
        v2037[2] = 0;
        HIDWORD(v2061) = *(_DWORD *)(v140 + 844);
        v2060 = *(_DWORD *)(v140 + 840);
        LODWORD(v2061) = v2060;
        while ( 1 )
        {
          LODWORD(v2061) = FsRtlPrivateResetHighestLockOffset(v2061, HIDWORD(v2061), 31);
          if ( !v2061 )
            break;
          v2060 ^= v2061;
        }
        v2037[3] = v2060 & 0x7FFFFFFF;
      }
      v2062 = __mrc(15, 0, 9, 13, 0);
      v2063 = v2062 << 29;
      v2064 = v2062 ^ (v2062 >> 3);
      v2065 = 67117057i64 * (unsigned int)v2064;
      v2066 = 1880096896i64 * (unsigned int)v2064 + 67117057i64 * v2063;
      v2067 = (1880096896i64 * v2063 + (unsigned __int64)HIDWORD(v2066)) >> 32;
      v2068 = 1880096896 * v2063 + HIDWORD(v2066);
      if ( (unsigned int)(v2066 + HIDWORD(v2065)) < HIDWORD(v2065) )
        v2067 = (__PAIR64__(v2067, v2068++) + 1) >> 32;
      LODWORD(v2069) = v2065 ^ v2068;
      HIDWORD(v2069) = (v2066 + HIDWORD(v2065)) ^ v2067;
      if ( !FsRtlRemovePerStreamContextEx(3i64, v2069) )
      {
        v2070 = __mrc(15, 0, 9, 13, 0);
        v2071 = v2070 << 29;
        v2072 = v2070 ^ (v2070 >> 3);
        v2073 = 67117057i64 * (unsigned int)v2072;
        v2074 = 1880096896i64 * (unsigned int)v2072 + 67117057i64 * v2071;
        v2075 = (1880096896i64 * v2071 + (unsigned __int64)HIDWORD(v2074)) >> 32;
        v2076 = 1880096896 * v2071 + HIDWORD(v2074);
        if ( (unsigned int)(v2074 + HIDWORD(v2073)) < HIDWORD(v2073) )
          v2075 = (__PAIR64__(v2075, v2076++) + 1) >> 32;
        LODWORD(v2077) = v2073 ^ v2076;
        HIDWORD(v2077) = (v2074 + HIDWORD(v2073)) ^ v2075;
        v2078 = FsRtlRemovePerStreamContextEx(2048i64, v2077);
        v2079 = v2078 + 3;
        v2853 = (_BYTE *)(v2078 + 3);
        v2080 = __mrc(15, 0, 9, 13, 0);
        v2081 = v2080 << 29;
        v2082 = v2080 ^ (v2080 >> 3);
        v2083 = 67117057i64 * (unsigned int)v2082;
        v2084 = 1880096896i64 * (unsigned int)v2082 + 67117057i64 * v2081;
        v2085 = (1880096896i64 * v2081 + (unsigned __int64)HIDWORD(v2084)) >> 32;
        v2086 = 1880096896 * v2081 + HIDWORD(v2084);
        if ( (unsigned int)(v2084 + HIDWORD(v2083)) < HIDWORD(v2083) )
          v2085 = (__PAIR64__(v2085, v2086++) + 1) >> 32;
        LODWORD(v2087) = v2083 ^ v2086;
        HIDWORD(v2087) = (v2084 + HIDWORD(v2083)) ^ v2085;
        v2088 = FsRtlRemovePerStreamContextEx((unsigned int)(v2078 + 4), v2087) & 0xFFFFFFFC;
        v2784 = *(int (__fastcall **)(_DWORD, _DWORD))(v140 + 344);
        v2089 = *(_DWORD *)(v140 + 928);
        v2090 = *(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v140 + 216);
        v2842 = *(_DWORD *)(v140 + 348);
        v2091 = *(_DWORD *)(v140 + 352);
        v2092 = *(_DWORD *)(v140 + 832);
        v2855 = v2088;
        v2859 = v2091;
        if ( (*(_DWORD *)(v140 + 992) & v2873) != 0 )
        {
          v2093 = 0;
          v2089 = 0;
        }
        else
        {
          v2093 = 1;
        }
        if ( v2089 && v2089 == 1 )
        {
          v2094 = __mrc(15, 0, 9, 13, 0);
          v2095 = v2094 << 29;
          v2096 = v2094 ^ (v2094 >> 3);
          v2097 = 67117057i64 * (unsigned int)v2096;
          v2098 = 1880096896i64 * (unsigned int)v2096 + 67117057i64 * v2095;
          v2099 = (1880096896i64 * v2095 + (unsigned __int64)HIDWORD(v2098)) >> 32;
          v2100 = 1880096896 * v2095 + HIDWORD(v2098);
          if ( (unsigned int)(v2098 + HIDWORD(v2097)) < HIDWORD(v2097) )
            v2099 = (__PAIR64__(v2099, v2100++) + 1) >> 32;
          LODWORD(v2101) = v2097 ^ v2100;
          HIDWORD(v2101) = (v2098 + HIDWORD(v2097)) ^ v2099;
          v2102 = FsRtlRemovePerStreamContextEx(2i64, v2101);
          v2103 = (_BYTE *)(v2079 + (((_DWORD)v2102 + 1) << 12));
          v2104 = v2103 + 1108;
          v2849 = HIDWORD(v2102);
          v2853 = v2103;
          v2105 = v2784(v2103 + 1108, -1);
          v2106 = (_DWORD *)v2105;
          if ( !v2105 )
            goto LABEL_2735;
          v2107 = v2853;
          if ( !((int (__fastcall *)(int, unsigned int, int))v2859)(v2105, (unsigned int)(v2853 + 5199) >> 12 << 12, 64) )
          {
            ((void (__fastcall *)(_DWORD *, _BYTE *))v2842)(v2106, v2107 + 1104);
LABEL_2735:
            ++*(_DWORD *)(v140 + 1056);
            goto LABEL_2824;
          }
          *v2106 = v2104;
          v2108 = v2106 + 1;
          v2088 = v2855;
        }
        else
        {
          v2109 = v2093 ? 0 : 512;
          v2110 = v2090(v2109, v2079 + 1104, v2092);
          v2107 = v2853;
          v2108 = (int *)v2110;
        }
        if ( !v2108 )
          goto LABEL_2735;
        v2111 = v2088;
        v2702 = v2088;
        v2112 = v2108;
        if ( v2088 >= 8 )
        {
          v2113 = v2088 >> 3;
          v2114 = v2088;
          do
          {
            v2115 = __mrc(15, 0, 9, 13, 0);
            v2116 = v2115 << 29;
            v2117 = v2115 ^ (v2115 >> 3);
            v2118 = (67117057 * (unsigned __int64)(unsigned int)v2117) >> 32;
            v2785 = 67117057 * v2117;
            v2119 = 1880096896 * v2117 + 67117057 * v2116;
            v2120 = (1880096896i64 * v2116
                   + ((1880096896i64 * (unsigned int)v2117 + 67117057 * (unsigned __int64)v2116) >> 32)) >> 32;
            v2121 = 1880096896 * v2116
                  + ((1880096896i64 * (unsigned int)v2117 + 67117057 * (unsigned __int64)v2116) >> 32);
            if ( v2119 + v2118 < v2118 )
              v2120 = (__PAIR64__(v2120, v2121++) + 1) >> 32;
            v2114 -= 8;
            *v2112 = v2121 ^ v2785;
            v2112[1] = v2120 ^ (v2119 + v2118);
            v2112 += 2;
            --v2113;
          }
          while ( v2113 );
          v140 = (unsigned int)v2734;
          v2107 = v2853;
          v2702 = v2114;
          v2037 = (int *)v2843;
          v2111 = v2702;
        }
        if ( v2111 )
        {
          v2122 = __mrc(15, 0, 9, 13, 0);
          v2123 = v2122 << 29;
          v2124 = v2122 ^ (v2122 >> 3);
          v2125 = (67117057 * (unsigned __int64)(unsigned int)v2124) >> 32;
          v2786 = 67117057 * v2124;
          v2126 = 1880096896 * v2124 + 67117057 * v2123;
          v2127 = (1880096896i64 * v2123
                 + ((1880096896i64 * (unsigned int)v2124 + 67117057 * (unsigned __int64)v2123) >> 32)) >> 32;
          v2128 = 1880096896 * v2123
                + ((1880096896i64 * (unsigned int)v2124 + 67117057 * (unsigned __int64)v2123) >> 32);
          if ( v2126 + v2125 < v2125 )
            v2127 = (__PAIR64__(v2127, v2128++) + 1) >> 32;
          v2129 = v2702;
          v2130 = v2786 ^ v2128;
          v2131 = (v2126 + v2125) ^ v2127;
          do
          {
            *(_BYTE *)v2112 = v2130;
            v2130 = FsRtlPrivateResetHighestLockOffset(v2130, v2131, 8);
            v2112 = (int *)((char *)v2112 + 1);
            --v2129;
          }
          while ( v2129 );
          v2107 = v2853;
        }
        v2132 = (unsigned int)&v2107[-v2855];
        v2133 = (int *)((char *)v2108 + v2855);
        v2134 = (int)v2108 + v2855 + 1104;
        v2703 = (int *)((char *)v2108 + v2855);
        v2728 = (int *)v2134;
        v2855 = v2132;
        if ( v2132 >= 8 )
        {
          v2135 = v2132 >> 3;
          v2136 = (int *)v2134;
          do
          {
            v2137 = __mrc(15, 0, 9, 13, 0);
            v2138 = v2137 << 29;
            v2139 = v2137 ^ (v2137 >> 3);
            v2140 = (67117057 * (unsigned __int64)(unsigned int)v2139) >> 32;
            v2787 = 67117057 * v2139;
            v2141 = 1880096896 * v2139 + 67117057 * v2138;
            v2142 = (1880096896i64 * v2138
                   + ((1880096896i64 * (unsigned int)v2139 + 67117057 * (unsigned __int64)v2138) >> 32)) >> 32;
            v2143 = 1880096896 * v2138
                  + ((1880096896i64 * (unsigned int)v2139 + 67117057 * (unsigned __int64)v2138) >> 32);
            if ( v2141 + v2140 < v2140 )
              v2142 = (__PAIR64__(v2142, v2143++) + 1) >> 32;
            v2132 -= 8;
            *v2136 = v2143 ^ v2787;
            v2136[1] = v2142 ^ (v2141 + v2140);
            v2136 += 2;
            --v2135;
          }
          while ( v2135 );
          v140 = (unsigned int)v2734;
          v2133 = v2703;
          v2728 = v2136;
          v2037 = (int *)v2843;
          v2855 = v2132;
        }
        if ( v2132 )
        {
          v2144 = __mrc(15, 0, 9, 13, 0);
          v2145 = v2144 << 29;
          v2146 = v2144 ^ (v2144 >> 3);
          v2147 = 67117057i64 * (unsigned int)v2146;
          v2148 = 1880096896 * v2146 + 67117057 * v2145;
          v2149 = (1880096896i64 * v2145
                 + ((1880096896i64 * (unsigned int)v2146 + 67117057 * (unsigned __int64)v2145) >> 32)) >> 32;
          v2150 = 1880096896 * v2145
                + ((1880096896i64 * (unsigned int)v2146 + 67117057 * (unsigned __int64)v2145) >> 32);
          v2151 = v2148 + HIDWORD(v2147);
          if ( (unsigned int)(v2148 + HIDWORD(v2147)) < HIDWORD(v2147) )
            v2149 = (__PAIR64__(v2149, v2150++) + 1) >> 32;
          v2152 = v2855;
          v2153 = v2728;
          v2154 = v2147 ^ v2150;
          v2155 = v2151 ^ v2149;
          do
          {
            *(_BYTE *)v2153 = v2154;
            v2153 = (int *)((char *)v2153 + 1);
            v2154 = FsRtlPrivateResetHighestLockOffset(v2154, v2155, 8);
            --v2152;
          }
          while ( v2152 );
          v2037 = (int *)v2843;
        }
        if ( v2037 != (int *)-16 )
          v2037[4] = (int)v2108;
        if ( v2133 )
        {
          v2037[1] = (int)v2133;
          v2037[2] = 1104;
          v2156 = 276;
          v2157 = 1104;
          v2158 = (char *)v140;
          v2159 = v2133;
          do
          {
            v2160 = *(_DWORD *)v2158;
            v2158 += 4;
            v2157 -= 4;
            --v2156;
            *v2159++ = v2160;
          }
          while ( v2156 );
          for ( nn = (int)v2843; v2157; v2159 = (_DWORD *)((char *)v2159 + 1) )
          {
            v2162 = *v2158++;
            --v2157;
            *(_BYTE *)v2159 = v2162;
          }
          v2133[248] |= 0x80000u;
          v2133[199] = 1104;
          v2133[206] = 1104;
          v2163 = v2133[248] & 0xFFFFFFFD;
          v2847 = (v2163 >> 19) & 1;
          v2133[248] = v2163;
          v2729 = (v2163 >> 8) & 1;
          v2164 = v2133[206];
          v2807 = (v2163 >> 9) & 1;
          v2846 = v2133[152];
          v2841 = v2133[178];
          v2845 = (unsigned int)(v2164 - 200) >> 2;
          v2133[49] = v2845;
          v2165 = __mrc(15, 0, 9, 13, 0);
          v2166 = v2165 << 29;
          v2167 = v2165 ^ (v2165 >> 3);
          v2168 = 67117057i64 * (unsigned int)v2167;
          v2169 = 1880096896 * v2166
                + ((67117057i64 * v2166 + 1880096896 * (unsigned __int64)(unsigned int)v2167) >> 32);
          if ( (0x7010008004002001i64 * __PAIR64__(v2166, v2167)) >> 32 < HIDWORD(v2168) )
            ++v2169;
          jj = v2168 ^ v2169;
          v2170 = 16;
          v2859 = v2133[192];
          v2171 = (char *)(v2133 + 188);
          v2172 = v2971;
          v2855 = v2133[193];
          v2173 = 4;
          v2842 = v2133[214];
          do
          {
            v2174 = *(_DWORD *)v2171;
            v2171 += 4;
            v2170 -= 4;
            --v2173;
            *(_DWORD *)v2172 = v2174;
            v2172 += 4;
          }
          while ( v2173 );
          for ( ; v2170; ++v2172 )
          {
            v2175 = *v2171++;
            --v2170;
            *v2172 = v2175;
          }
          v2133[192] = 0;
          v2133[193] = 0;
          v2176 = 16;
          v2177 = v2133 + 188;
          v2133[214] = 0;
          v2178 = 4;
          do
          {
            v2176 -= 4;
            --v2178;
            *v2177++ = 0;
          }
          while ( v2178 );
          for ( ; v2176; --v2176 )
          {
            *(_BYTE *)v2177 = 0;
            v2177 = (_DWORD *)((char *)v2177 + 1);
          }
          v2179 = v2133[199];
          v2180 = v2133;
          v2181 = (char *)v2133;
          v2788 = v2179;
          if ( v2133 < (_DWORD *)((char *)v2133 + v2179) )
          {
            do
            {
              __pld(v2181);
              v2181 += 128;
            }
            while ( v2181 < (char *)v2133 + v2179 );
          }
          v2182 = v2133[199];
          v2183 = v2133[211];
          v2184 = v2133[210];
          v2818 = v2182;
          if ( v2179 >= 8 )
          {
            v2185 = v2179 >> 3;
            v2186 = v2133[199];
            v2187 = v2133[209] & 0x3F;
            v2188 = 64 - v2187;
            v2189 = v2187 - 32;
            v2190 = 32 - v2187;
            do
            {
              v2186 -= 8;
              v2191 = v2184 ^ *v2180;
              v2192 = v2180[1];
              v2180 += 2;
              v2193 = v2183 ^ v2192;
              v2194 = (v2191 >> v2188) | (v2193 << v2189) | (v2193 >> v2190);
              v2183 = (v2193 >> v2188) | (__PAIR64__(v2193, v2191) << v2187 >> 32);
              v2184 = v2194 | (v2191 << v2187);
              v2190 = 32 - v2187;
              --v2185;
              v2189 = v2187 - 32;
            }
            while ( v2185 );
            v2818 = v2186;
            v140 = (unsigned int)v2734;
            v2182 = v2186;
            v2133 = v2703;
            nn = (int)v2843;
          }
          if ( v2182 )
          {
            v2195 = v2818;
            v2196 = v2133[209] & 0x3F;
            v2197 = 64 - v2196;
            do
            {
              v2198 = *(unsigned __int8 *)v2180;
              v2180 = (_DWORD *)((char *)v2180 + 1);
              v2199 = v2184 ^ v2198;
              v2200 = (v2199 >> v2197) | (v2183 << (v2196 - 32)) | (v2183 >> (32 - v2196));
              v2183 = (v2183 >> v2197) | (__PAIR64__(v2183, v2199) << v2196 >> 32);
              v2184 = v2200 | (v2199 << v2196);
              --v2195;
            }
            while ( v2195 );
            v140 = (unsigned int)v2734;
            v2133 = v2703;
            nn = (int)v2843;
            v2179 = v2788;
          }
          v2201 = v2842;
          v2202 = v2971;
          v2133[214] += v2179;
          v2203 = v2133 + 188;
          v2133[192] = v2859;
          v2133[193] = v2855;
          v2204 = v2133[214] + v2201;
          v2205 = 16;
          v2133[214] = v2204;
          v2206 = 4;
          do
          {
            v2207 = *(_DWORD *)v2202;
            v2202 += 4;
            v2205 -= 4;
            --v2206;
            *v2203++ = v2207;
          }
          while ( v2206 );
          for ( ; v2205; v2203 = (_DWORD *)((char *)v2203 + 1) )
          {
            v2208 = *v2202++;
            --v2205;
            *(_BYTE *)v2203 = v2208;
          }
          v2133[192] = v2184;
          v2133[193] = v2183;
          v2209 = jj;
          v2210 = v2133;
          v2211 = 50;
          do
          {
            *v2210++ ^= v2209;
            --v2211;
          }
          while ( v2211 );
          v2212 = v2845;
          if ( v2845 )
          {
            v2213 = &v2210[v2845];
            do
            {
              v2214 = *--v2213;
              v2215 = v2214 ^ v2209;
              v2209 = __ROR4__(v2209, v2212);
              *v2213 = v2215;
              --v2212;
            }
            while ( v2212 );
          }
          if ( v2847 )
          {
            v2216 = __mrc(15, 0, 9, 13, 0);
            v2217 = v2216 << 29;
            v2218 = v2216 ^ (v2216 >> 3);
            v2219 = 67117057i64 * (unsigned int)v2218;
            v2220 = 67117057i64 * v2217 + 1880096896i64 * (unsigned int)v2218;
            v2221 = (1880096896i64 * v2217 + (unsigned __int64)HIDWORD(v2220)) >> 32;
            v2222 = 1880096896 * v2217 + HIDWORD(v2220);
            if ( (unsigned int)(v2220 + HIDWORD(v2219)) < HIDWORD(v2219) )
              v2221 = (__PAIR64__(v2221, v2222++) + 1) >> 32;
            LODWORD(v2223) = v2219 ^ v2222;
            HIDWORD(v2223) = (v2220 + HIDWORD(v2219)) ^ v2221;
            if ( FsRtlRemovePerStreamContextEx(3i64, v2223) )
              goto LABEL_2810;
          }
          else if ( v2729 )
          {
LABEL_2810:
            v2235 = *(_QWORD *)(nn + 4);
            v2855 = *(_DWORD *)(nn + 8);
            v2236 = (char *)v2235;
            if ( (unsigned int)v2235 < HIDWORD(v2235) + (int)v2235 )
            {
              do
              {
                __pld(v2236);
                v2236 += 128;
              }
              while ( (unsigned int)v2236 < HIDWORD(v2235) + (int)v2235 );
            }
            HIDWORD(v2237) = *(_DWORD *)(v140 + 844);
            v2238 = *(_DWORD *)(v140 + 840);
            v2239 = HIDWORD(v2235);
            if ( HIDWORD(v2235) >= 8 )
            {
              v2240 = *(_DWORD *)(v140 + 836) & 0x3F;
              v2241 = 64 - v2240;
              LOBYTE(v2237) = 32 - v2240;
              HIDWORD(v2235) >>= 3;
              do
              {
                v2239 -= 8;
                v2242 = v2238 ^ *(_DWORD *)v2235;
                v2243 = *(_DWORD *)(v2235 + 4);
                LODWORD(v2235) = v2235 + 8;
                HIDWORD(v2237) ^= v2243;
                v2244 = __PAIR64__(HIDWORD(v2237), v2242) << v2240;
                v2238 = (v2242 >> v2241) | (HIDWORD(v2237) << (v2240 - 32)) | (HIDWORD(v2237) >> v2237) | (v2242 << v2240);
                HIDWORD(v2237) = (HIDWORD(v2237) >> v2241) | HIDWORD(v2244);
                --HIDWORD(v2235);
                LOBYTE(v2237) = 32 - v2240;
              }
              while ( HIDWORD(v2235) );
              v140 = (unsigned int)v2734;
              nn = (int)v2843;
              HIDWORD(v2235) = v2855;
            }
            if ( v2239 )
            {
              v2245 = *(_DWORD *)(v140 + 836) & 0x3F;
              v2246 = 64 - v2245;
              do
              {
                v2247 = *(unsigned __int8 *)v2235;
                LODWORD(v2235) = v2235 + 1;
                v2248 = v2238 ^ v2247;
                LODWORD(v2237) = (v2248 >> v2246) | (HIDWORD(v2237) << (v2245 - 32)) | (HIDWORD(v2237) >> (32 - v2245));
                HIDWORD(v2237) = (HIDWORD(v2237) >> v2246) | (__PAIR64__(HIDWORD(v2237), v2248) << v2245 >> 32);
                v2238 = v2237 | (v2248 << v2245);
                --v2239;
              }
              while ( v2239 );
              v140 = (unsigned int)v2734;
              nn = (int)v2843;
              HIDWORD(v2235) = v2855;
            }
            LODWORD(v2237) = v2238;
            *(_DWORD *)(v140 + 856) += HIDWORD(v2235);
            while ( 1 )
            {
              LODWORD(v2237) = FsRtlPrivateResetHighestLockOffset(v2237, HIDWORD(v2237), 31);
              if ( !v2237 )
                break;
              v2238 ^= v2237;
            }
            *(_DWORD *)(nn + 12) = v2238 & 0x7FFFFFFF;
            goto LABEL_2824;
          }
          v2906[0] = 0;
          v2906[3] = 1;
          v2906[5] = 2;
          v2906[8] = 3;
          v2906[6] = 4;
          v2906[9] = 5;
          v2906[12] = 6;
          v2906[7] = 7;
          v2906[13] = 8;
          v2906[10] = 9;
          v2906[14] = 10;
          v2906[4] = 11;
          v2906[1] = 12;
          v2906[15] = 13;
          v2906[11] = 14;
          v2224 = 0;
          v2225 = 0;
          v2906[2] = 15;
          v2226 = v2133;
          v2227 = __ROR4__(v2133, (char)v2133);
          do
          {
            v2228 = *v2226;
            v2229 = 8;
            do
            {
              v2228 = __ROR4__(v2228 & 0xFFFFFFF0 | (unsigned __int8)v2906[v2228 & 0xF], 4);
              --v2229;
            }
            while ( v2229 );
            v2230 = v2228 - v2225;
            v2231 = v2841;
            *v2226 = v2228;
            *v2226 = v2228 - v2225;
            if ( v2807 )
              v2232 = v2230 ^ v2227;
            else
              v2232 = __ROR4__(bswap32(v2230 ^ v2846) ^ v2227, v2231) ^ v2231;
            *v2226 = v2232;
            v2233 = *v2226++;
            v2234 = __ROR4__(__ROR4__((200 - v2224) * v2224, ~(_BYTE)v2233) ^ v2227, -(char)v2233);
            ++v2224;
            v2227 = (unsigned int)v2703 + v2234;
            v2225 += (int)v2703;
          }
          while ( v2224 < 0x32 );
          v140 = (unsigned int)v2734;
          nn = (int)v2843;
          goto LABEL_2810;
        }
      }
    }
  }
LABEL_2824:
  v2249 = v2858;
  v2250 = 0;
  v2251 = *(_DWORD *)(v140 + 992);
  v2704 = 0;
  v2252 = 0;
  v2843 = 0;
  if ( v140 != v2858 )
  {
    v2252 = *(_DWORD *)(v140 + 780);
    v2843 = (unsigned int *)v2252;
    if ( ((v2251 & v2863) == 0 || (v2251 & 0x100000) == 0) && (v2251 & 0x10) != 0 )
    {
      *(_DWORD *)(v140 + 992) = v2251 & 0xFFFFFFDF;
      *(_DWORD *)(v140 + 924) = -1;
    }
    v2331 = *(_DWORD *)(v140 + 992);
    if ( (v2331 & 2) != 0 )
      v2332 = *(_DWORD *)(v140 + 796);
    else
      v2332 = *(_DWORD *)(v140 + 824);
    v2847 = (v2331 >> 19) & 1;
    v2706 = (v2331 >> 9) & 1;
    v2732 = (v2331 >> 8) & 1;
    v2841 = *(_DWORD *)(v140 + 608);
    v2809 = *(_DWORD *)(v140 + 712);
    v2333 = (unsigned int)(v2332 - 200) >> 2;
    v2855 = v2333;
    *(_DWORD *)(v140 + 196) = v2333;
    v2334 = __mrc(15, 0, 9, 13, 0);
    v2335 = v2334 << 29;
    v2336 = v2334 ^ (v2334 >> 3);
    v2337 = 67117057i64 * (unsigned int)v2336;
    v2338 = 1880096896 * v2335 + ((1880096896i64 * (unsigned int)v2336 + 67117057 * (unsigned __int64)v2335) >> 32);
    if ( (0x7010008004002001i64 * __PAIR64__(v2335, v2336)) >> 32 < HIDWORD(v2337) )
      ++v2338;
    v2845 = v2337 ^ v2338;
    v2339 = 16;
    v2859 = *(_DWORD *)(v140 + 768);
    v2340 = v2974;
    v2341 = (char *)(v140 + 752);
    v2842 = *(_DWORD *)(v140 + 772);
    v2342 = 4;
    jj = *(_DWORD *)(v140 + 856);
    do
    {
      v2343 = *(_DWORD *)v2341;
      v2341 += 4;
      v2339 -= 4;
      --v2342;
      *(_DWORD *)v2340 = v2343;
      v2340 += 4;
    }
    while ( v2342 );
    for ( ; v2339; ++v2340 )
    {
      v2344 = *v2341++;
      --v2339;
      *v2340 = v2344;
    }
    *(_DWORD *)(v140 + 768) = 0;
    *(_DWORD *)(v140 + 772) = 0;
    v2345 = 16;
    *(_DWORD *)(v140 + 856) = 0;
    v2346 = (_DWORD *)(v140 + 752);
    v2347 = 4;
    do
    {
      v2345 -= 4;
      --v2347;
      *v2346++ = 0;
    }
    while ( v2347 );
    for ( ; v2345; --v2345 )
    {
      *(_BYTE *)v2346 = 0;
      v2346 = (_DWORD *)((char *)v2346 + 1);
    }
    v2348 = *(_DWORD *)(v140 + 796);
    v2349 = (_DWORD *)v140;
    v2350 = (char *)v140;
    v2790 = v2348;
    if ( v140 < v140 + v2348 )
    {
      do
      {
        __pld(v2350);
        v2350 += 128;
      }
      while ( (unsigned int)v2350 < v140 + v2348 );
    }
    v2351 = *(_DWORD *)(v140 + 796);
    v2352 = *(_DWORD *)(v140 + 844);
    v2353 = *(_DWORD *)(v140 + 840);
    v2820 = v2351;
    if ( v2348 >= 8 )
    {
      v2354 = *(_DWORD *)(v140 + 836);
      v2355 = v2348 >> 3;
      v2356 = v2348;
      v2357 = v2354 & 0x3F;
      v2358 = 64 - (v2354 & 0x3F);
      v2359 = (v2354 & 0x3F) - 32;
      v2360 = 32 - (v2354 & 0x3F);
      do
      {
        v2356 -= 8;
        v2361 = v2353 ^ *v2349;
        v2362 = v2349[1];
        v2349 += 2;
        v2363 = v2352 ^ v2362;
        v2364 = (v2361 >> v2358) | (v2363 << v2359) | (v2363 >> v2360);
        v2352 = (v2363 >> v2358) | (__PAIR64__(v2363, v2361) << v2357 >> 32);
        v2353 = v2364 | (v2361 << v2357);
        v2360 = v2358 - 32;
        --v2355;
        v2359 = 32 - v2358;
      }
      while ( v2355 );
      v2820 = v2356;
      v140 = (unsigned int)v2734;
      v2351 = v2356;
      v2252 = (int)v2843;
      v2333 = v2855;
    }
    if ( v2351 )
    {
      v2365 = v2820;
      v2366 = *(_DWORD *)(v140 + 836) & 0x3F;
      v2367 = 64 - v2366;
      do
      {
        v2368 = *(unsigned __int8 *)v2349;
        v2349 = (_DWORD *)((char *)v2349 + 1);
        v2369 = v2353 ^ v2368;
        v2370 = (v2369 >> v2367) | (v2352 << (v2366 - 32)) | (v2352 >> (32 - v2366));
        v2352 = (v2352 >> v2367) | (__PAIR64__(v2352, v2369) << v2366 >> 32);
        v2353 = v2370 | (v2369 << v2366);
        --v2365;
      }
      while ( v2365 );
      v140 = (unsigned int)v2734;
      v2252 = (int)v2843;
      v2348 = v2790;
      v2333 = v2855;
    }
    v2371 = jj;
    v2372 = v2974;
    *(_DWORD *)(v140 + 856) += v2348;
    v2373 = (_DWORD *)(v140 + 752);
    *(_DWORD *)(v140 + 768) = v2859;
    *(_DWORD *)(v140 + 772) = v2842;
    v2374 = *(_DWORD *)(v140 + 856) + v2371;
    v2375 = 16;
    *(_DWORD *)(v140 + 856) = v2374;
    v2376 = 4;
    do
    {
      v2377 = *(_DWORD *)v2372;
      v2372 += 4;
      v2375 -= 4;
      --v2376;
      *v2373++ = v2377;
    }
    while ( v2376 );
    for ( ; v2375; v2373 = (_DWORD *)((char *)v2373 + 1) )
    {
      v2378 = *v2372++;
      --v2375;
      *(_BYTE *)v2373 = v2378;
    }
    *(_DWORD *)(v140 + 768) = v2353;
    *(_DWORD *)(v140 + 772) = v2352;
    v2379 = v2845;
    v2380 = (_DWORD *)v140;
    v2381 = 50;
    do
    {
      *v2380++ ^= v2379;
      --v2381;
    }
    while ( v2381 );
    if ( v2333 )
    {
      v2382 = &v2380[v2333];
      do
      {
        v2383 = *--v2382;
        v2384 = v2383 ^ v2379;
        v2379 = __ROR4__(v2379, v2333);
        *v2382 = v2384;
        --v2333;
      }
      while ( v2333 );
    }
    if ( v2847 )
    {
      v2385 = __mrc(15, 0, 9, 13, 0);
      v2386 = v2385 << 29;
      v2387 = v2385 ^ (v2385 >> 3);
      v2388 = 67117057i64 * (unsigned int)v2387;
      v2389 = 67117057i64 * v2386 + 1880096896i64 * (unsigned int)v2387;
      v2390 = (1880096896i64 * v2386 + (unsigned __int64)HIDWORD(v2389)) >> 32;
      v2391 = 1880096896 * v2386 + HIDWORD(v2389);
      if ( (unsigned int)(v2389 + HIDWORD(v2388)) < HIDWORD(v2388) )
        v2390 = (__PAIR64__(v2390, v2391++) + 1) >> 32;
      LODWORD(v2392) = v2388 ^ v2391;
      HIDWORD(v2392) = (v2389 + HIDWORD(v2388)) ^ v2390;
      if ( FsRtlRemovePerStreamContextEx(3i64, v2392) )
        goto LABEL_2941;
    }
    else if ( v2732 )
    {
      goto LABEL_2941;
    }
    v2907[0] = 0;
    v2907[3] = 1;
    v2907[5] = 2;
    v2907[8] = 3;
    v2907[6] = 4;
    v2907[9] = 5;
    v2907[12] = 6;
    v2907[7] = 7;
    v2907[13] = 8;
    v2907[10] = 9;
    v2907[14] = 10;
    v2907[4] = 11;
    v2907[1] = 12;
    v2907[15] = 13;
    v2907[11] = 14;
    v2393 = 0;
    v2394 = 0;
    v2907[2] = 15;
    v2395 = (int *)v140;
    v2396 = __ROR4__(v140, v140);
    do
    {
      v2397 = *v2395;
      v2398 = 8;
      do
      {
        v2397 = __ROR4__(v2397 & 0xFFFFFFF0 | (unsigned __int8)v2907[v2397 & 0xF], 4);
        --v2398;
      }
      while ( v2398 );
      v2399 = v2397 - v2394;
      *v2395 = v2397;
      *v2395 = v2397 - v2394;
      if ( v2706 )
        v2400 = v2399 ^ v2396;
      else
        v2400 = __ROR4__(bswap32(v2399 ^ v2841) ^ v2396, v2809) ^ v2809;
      *v2395 = v2400;
      v2401 = *v2395++;
      v2402 = __ROR4__(__ROR4__((200 - v2393) * v2393, ~(_BYTE)v2401) ^ v2396, -(char)v2401);
      ++v2393;
      v2396 = v2402 + v140;
      v2394 += v140;
    }
    while ( v2393 < 0x32 );
    goto LABEL_2940;
  }
  if ( (v2251 & 0x8000) == 0 && *(_DWORD *)(v140 + 880) )
  {
LABEL_2890:
    *(_DWORD *)(v2249 + 196) = 1;
    v140 = v2249;
    v2731 = 0;
    v2734 = (_BYTE *)v2249;
    v2842 = v2249;
    goto LABEL_2944;
  }
  v2253 = *(_DWORD *)(v2858 + 992);
  v2254 = v2858;
  if ( (v2253 & 0x20000000) == 0 )
    v2254 = 0;
  if ( *(int *)(v2858 + 928) > 1 )
  {
    if ( !v2254 )
    {
      v2256 = sub_5FD658;
      goto LABEL_2837;
    }
    v2255 = *(_DWORD *)(v2254 + 816);
    goto LABEL_2835;
  }
  if ( v2254 )
  {
    v2255 = *(_DWORD *)(v2254 + 812);
LABEL_2835:
    v2256 = (_DWORD *(__fastcall *)(int, int))((v2255 | 1) + v2254);
    goto LABEL_2837;
  }
  v2256 = (_DWORD *(__fastcall *)(int, int))sub_5FD2A0;
LABEL_2837:
  if ( (v2253 & 4) == 0 )
    v2256 = *(_DWORD *(__fastcall **)(int, int))(v2858 + 1080);
  v2257 = v2256(v2858, *(_DWORD *)(v2858 + 796));
  v140 = (unsigned int)v2257;
  v2734 = v2257;
  if ( !v2257 )
    goto LABEL_2890;
  v2252 = v2257[195];
  v2258 = v2257[248];
  v2843 = (unsigned int *)v2252;
  if ( ((v2258 & v2863) == 0 || (v2258 & 0x100000) == 0) && (v2258 & 0x10) != 0 )
  {
    v2257[248] = v2258 & 0xFFFFFFDF;
    v2257[231] = -1;
  }
  v2259 = v2257[248];
  if ( (v2259 & 2) != 0 )
    v2260 = v2257[199];
  else
    v2260 = v2257[206];
  v2847 = (v2259 >> 19) & 1;
  v2705 = (v2259 >> 9) & 1;
  v2730 = (v2259 >> 8) & 1;
  v2841 = v2257[152];
  v2808 = v2257[178];
  v2261 = (unsigned int)(v2260 - 200) >> 2;
  v2855 = v2261;
  v2257[49] = v2261;
  v2262 = __mrc(15, 0, 9, 13, 0);
  v2263 = v2262 << 29;
  v2264 = v2262 ^ (v2262 >> 3);
  v2265 = 67117057i64 * (unsigned int)v2264;
  v2266 = 1880096896 * v2263 + ((1880096896i64 * (unsigned int)v2264 + 67117057 * (unsigned __int64)v2263) >> 32);
  if ( (0x7010008004002001i64 * __PAIR64__(v2263, v2264)) >> 32 < HIDWORD(v2265) )
    ++v2266;
  v2845 = v2265 ^ v2266;
  v2267 = 16;
  v2859 = v2257[192];
  v2268 = v2975;
  v2269 = (char *)(v140 + 752);
  v2842 = *(_DWORD *)(v140 + 772);
  v2270 = 4;
  jj = *(_DWORD *)(v140 + 856);
  do
  {
    v2271 = *(_DWORD *)v2269;
    v2269 += 4;
    v2267 -= 4;
    --v2270;
    *(_DWORD *)v2268 = v2271;
    v2268 += 4;
  }
  while ( v2270 );
  for ( ; v2267; ++v2268 )
  {
    v2272 = *v2269++;
    --v2267;
    *v2268 = v2272;
  }
  *(_DWORD *)(v140 + 768) = 0;
  *(_DWORD *)(v140 + 772) = 0;
  v2273 = 16;
  *(_DWORD *)(v140 + 856) = 0;
  v2274 = (_DWORD *)(v140 + 752);
  v2275 = 4;
  do
  {
    v2273 -= 4;
    --v2275;
    *v2274++ = 0;
  }
  while ( v2275 );
  for ( ; v2273; --v2273 )
  {
    *(_BYTE *)v2274 = 0;
    v2274 = (_DWORD *)((char *)v2274 + 1);
  }
  v2276 = *(_DWORD *)(v140 + 796);
  v2277 = (_DWORD *)v140;
  v2278 = (char *)v140;
  v2789 = v2276;
  if ( v140 < v140 + v2276 )
  {
    do
    {
      __pld(v2278);
      v2278 += 128;
    }
    while ( (unsigned int)v2278 < v140 + v2276 );
  }
  v2279 = *(_DWORD *)(v140 + 796);
  v2280 = *(_DWORD *)(v140 + 844);
  v2281 = *(_DWORD *)(v140 + 840);
  v2819 = v2279;
  if ( v2276 >= 8 )
  {
    v2282 = *(_DWORD *)(v140 + 836);
    v2283 = v2276 >> 3;
    v2284 = v2276;
    v2285 = v2282 & 0x3F;
    v2286 = 64 - (v2282 & 0x3F);
    v2287 = (v2282 & 0x3F) - 32;
    v2288 = 32 - (v2282 & 0x3F);
    do
    {
      v2284 -= 8;
      v2289 = v2281 ^ *v2277;
      v2290 = v2277[1];
      v2277 += 2;
      v2291 = v2280 ^ v2290;
      v2292 = (v2289 >> v2286) | (v2291 << v2287) | (v2291 >> v2288);
      v2280 = (v2291 >> v2286) | (__PAIR64__(v2291, v2289) << v2285 >> 32);
      v2281 = v2292 | (v2289 << v2285);
      v2288 = v2286 - 32;
      --v2283;
      v2287 = 32 - v2286;
    }
    while ( v2283 );
    v2819 = v2284;
    v140 = (unsigned int)v2734;
    v2279 = v2284;
    v2252 = (int)v2843;
    v2261 = v2855;
  }
  if ( v2279 )
  {
    v2293 = v2819;
    v2294 = *(_DWORD *)(v140 + 836) & 0x3F;
    v2295 = 64 - v2294;
    do
    {
      v2296 = *(unsigned __int8 *)v2277;
      v2277 = (_DWORD *)((char *)v2277 + 1);
      v2297 = v2281 ^ v2296;
      v2298 = (v2297 >> v2295) | (v2280 << (v2294 - 32)) | (v2280 >> (32 - v2294));
      v2280 = (v2280 >> v2295) | (__PAIR64__(v2280, v2297) << v2294 >> 32);
      v2281 = v2298 | (v2297 << v2294);
      --v2293;
    }
    while ( v2293 );
    v140 = (unsigned int)v2734;
    v2252 = (int)v2843;
    v2276 = v2789;
    v2261 = v2855;
  }
  v2299 = jj;
  v2300 = v2975;
  *(_DWORD *)(v140 + 856) += v2276;
  v2301 = (_DWORD *)(v140 + 752);
  *(_DWORD *)(v140 + 768) = v2859;
  *(_DWORD *)(v140 + 772) = v2842;
  v2302 = *(_DWORD *)(v140 + 856) + v2299;
  v2303 = 16;
  *(_DWORD *)(v140 + 856) = v2302;
  v2304 = 4;
  do
  {
    v2305 = *(_DWORD *)v2300;
    v2300 += 4;
    v2303 -= 4;
    --v2304;
    *v2301++ = v2305;
  }
  while ( v2304 );
  for ( ; v2303; v2301 = (_DWORD *)((char *)v2301 + 1) )
  {
    v2306 = *v2300++;
    --v2303;
    *(_BYTE *)v2301 = v2306;
  }
  *(_DWORD *)(v140 + 768) = v2281;
  *(_DWORD *)(v140 + 772) = v2280;
  v2307 = v2845;
  v2308 = (_DWORD *)v140;
  v2309 = 50;
  do
  {
    *v2308++ ^= v2307;
    --v2309;
  }
  while ( v2309 );
  if ( v2261 )
  {
    v2310 = &v2308[v2261];
    do
    {
      v2311 = *--v2310;
      v2312 = v2311 ^ v2307;
      v2307 = __ROR4__(v2307, v2261);
      *v2310 = v2312;
      --v2261;
    }
    while ( v2261 );
  }
  if ( v2847 )
  {
    v2313 = __mrc(15, 0, 9, 13, 0);
    v2314 = v2313 << 29;
    v2315 = v2313 ^ (v2313 >> 3);
    v2316 = 67117057i64 * (unsigned int)v2315;
    v2317 = 1880096896i64 * (unsigned int)v2315 + 67117057i64 * v2314;
    v2318 = (1880096896i64 * v2314 + (unsigned __int64)HIDWORD(v2317)) >> 32;
    v2319 = 1880096896 * v2314 + HIDWORD(v2317);
    if ( (unsigned int)(v2317 + HIDWORD(v2316)) < HIDWORD(v2316) )
      v2318 = (__PAIR64__(v2318, v2319++) + 1) >> 32;
    LODWORD(v2320) = v2316 ^ v2319;
    HIDWORD(v2320) = (v2317 + HIDWORD(v2316)) ^ v2318;
    if ( FsRtlRemovePerStreamContextEx(3i64, v2320) )
      goto LABEL_2941;
    goto LABEL_2882;
  }
  if ( !v2730 )
  {
LABEL_2882:
    v2905[0] = 0;
    v2905[3] = 1;
    v2905[5] = 2;
    v2905[8] = 3;
    v2905[6] = 4;
    v2905[9] = 5;
    v2905[12] = 6;
    v2905[7] = 7;
    v2905[13] = 8;
    v2905[10] = 9;
    v2905[14] = 10;
    v2905[4] = 11;
    v2905[1] = 12;
    v2905[15] = 13;
    v2905[11] = 14;
    v2321 = 0;
    v2322 = 0;
    v2905[2] = 15;
    v2323 = (int *)v140;
    v2324 = __ROR4__(v140, v140);
    do
    {
      v2325 = *v2323;
      v2326 = 8;
      do
      {
        v2325 = __ROR4__(v2325 & 0xFFFFFFF0 | (unsigned __int8)v2905[v2325 & 0xF], 4);
        --v2326;
      }
      while ( v2326 );
      v2327 = v2325 - v2322;
      *v2323 = v2325;
      *v2323 = v2325 - v2322;
      if ( v2705 )
        v2328 = v2327 ^ v2324;
      else
        v2328 = __ROR4__(bswap32(v2327 ^ v2841) ^ v2324, v2808) ^ v2808;
      *v2323 = v2328;
      v2329 = *v2323++;
      v2330 = __ROR4__(__ROR4__((200 - v2321) * v2321, ~(_BYTE)v2329) ^ v2324, -(char)v2329);
      ++v2321;
      v2324 = v2330 + v140;
      v2322 += v140;
    }
    while ( v2321 < 0x32 );
LABEL_2940:
    v2252 = (int)v2843;
  }
LABEL_2941:
  v2250 = 1;
  v2704 = 1;
  v2403 = __mrc(15, 0, 9, 13, 0);
  v2404 = v2403 << 29;
  v2405 = v2403 ^ (v2403 >> 3);
  v2406 = 67117057i64 * (unsigned int)v2405;
  v2407 = 1880096896i64 * (unsigned int)v2405 + 67117057i64 * v2404;
  v2408 = 1880096896 * v2404 + HIDWORD(v2407);
  if ( (unsigned int)(v2407 + HIDWORD(v2406)) < HIDWORD(v2406) )
    ++v2408;
  v2249 = v2858;
  v2731 = v2408 ^ v2406;
  v2842 = v140;
LABEL_2944:
  v2409 = *(_DWORD *)(v2249 + 992);
  if ( ((v2409 & v2863) == 0 || (v2409 & 0x100000) == 0) && (v2409 & 0x10) != 0 )
  {
    (*(void (__fastcall **)(char *, _DWORD))(v2249 + 300))(v2970, *(_DWORD *)(v2249 + 924));
    v2410 = (*(int (__fastcall **)(char *, _DWORD))(v2249 + 304))(v2970, 0);
    __disable_irq();
    v2411 = __mrc(14, 0, 0, 2, 2);
    if ( (*(_DWORD *)(v2249 + 992) & 0x20) != 0 )
      v2411 |= 0x8000u;
    __mcr(14, 0, v2411, 0, 2, 2);
    __enable_irq();
    (*(void (__fastcall **)(int))(v2249 + 296))(v2410);
    *(_DWORD *)(v2249 + 992) &= 0xFFFFFFDF;
    *(_DWORD *)(v2249 + 924) = -1;
  }
  if ( !v2250 )
  {
    v2412 = 16;
    v2791 = *(_DWORD *)(v140 + 768);
    v2413 = v2972;
    v2414 = (char *)(v140 + 752);
    v2859 = *(_DWORD *)(v140 + 772);
    v2415 = 4;
    jj = *(_DWORD *)(v140 + 856);
    do
    {
      v2416 = *(_DWORD *)v2414;
      v2414 += 4;
      v2412 -= 4;
      --v2415;
      *(_DWORD *)v2413 = v2416;
      v2413 += 4;
    }
    while ( v2415 );
    for ( ; v2412; ++v2413 )
    {
      v2417 = *v2414++;
      --v2412;
      *v2413 = v2417;
    }
    *(_DWORD *)(v140 + 768) = 0;
    *(_DWORD *)(v140 + 772) = 0;
    v2418 = 16;
    *(_DWORD *)(v140 + 856) = 0;
    v2419 = (_DWORD *)(v140 + 752);
    v2420 = 4;
    do
    {
      v2418 -= 4;
      --v2420;
      *v2419++ = 0;
    }
    while ( v2420 );
    for ( ; v2418; --v2418 )
    {
      *(_BYTE *)v2419 = 0;
      v2419 = (_DWORD *)((char *)v2419 + 1);
    }
    v2422 = (_DWORD *)v140;
    v2423 = (char *)v140;
    v2855 = *(_DWORD *)(v140 + 796);
    v2421 = v2855;
    if ( v140 < v140 + v2855 )
    {
      do
      {
        __pld(v2423);
        v2423 += 128;
      }
      while ( (unsigned int)v2423 < v140 + v2855 );
    }
    v2424 = *(_QWORD *)(v140 + 840);
    v2425 = v2855;
    if ( v2855 >= 8 )
    {
      v2426 = v2855 >> 3;
      v2427 = *(_DWORD *)(v140 + 836) & 0x3F;
      v2428 = 64 - v2427;
      v2429 = 32 - v2427;
      do
      {
        v2425 -= 8;
        v2430 = v2424 ^ *v2422;
        v2431 = v2422[1];
        v2422 += 2;
        v2432 = HIDWORD(v2424) ^ v2431;
        v2433 = (v2430 >> v2428) | (v2432 << (v2427 - 32)) | (v2432 >> v2429);
        HIDWORD(v2424) = (v2432 >> v2428) | (__PAIR64__(v2432, v2430) << v2427 >> 32);
        LODWORD(v2424) = v2433 | (v2430 << v2427);
        v2429 = 32 - v2427;
        --v2426;
      }
      while ( v2426 );
      v140 = (unsigned int)v2734;
      v2252 = (int)v2843;
      v2421 = v2855;
    }
    if ( v2425 )
    {
      v2434 = *(_DWORD *)(v140 + 836) & 0x3F;
      v2435 = 64 - v2434;
      do
      {
        v2436 = *(unsigned __int8 *)v2422;
        v2422 = (_DWORD *)((char *)v2422 + 1);
        v2437 = (v2424 ^ v2436) << v2434;
        LODWORD(v2424) = ((v2436 ^ (unsigned int)v2424) >> v2435) | (HIDWORD(v2424) << (v2434 - 32)) | (HIDWORD(v2424) >> (32 - v2434)) | ((v2436 ^ (unsigned int)v2424) << v2434);
        HIDWORD(v2424) = (HIDWORD(v2424) >> v2435) | HIDWORD(v2437);
        --v2425;
      }
      while ( v2425 );
      v140 = (unsigned int)v2734;
      v2252 = (int)v2843;
      v2421 = v2855;
    }
    v2438 = jj;
    v2439 = v2972;
    *(_DWORD *)(v140 + 856) += v2421;
    v2440 = (_DWORD *)(v140 + 752);
    *(_DWORD *)(v140 + 768) = v2791;
    *(_DWORD *)(v140 + 772) = v2859;
    v2441 = *(_DWORD *)(v140 + 856) + v2438;
    v2442 = 16;
    *(_DWORD *)(v140 + 856) = v2441;
    v2443 = 4;
    do
    {
      v2444 = *(_DWORD *)v2439;
      v2439 += 4;
      v2442 -= 4;
      --v2443;
      *v2440++ = v2444;
    }
    while ( v2443 );
    for ( ; v2442; v2440 = (_DWORD *)((char *)v2440 + 1) )
    {
      v2445 = *v2439++;
      --v2442;
      *(_BYTE *)v2440 = v2445;
    }
    *(_QWORD *)(v140 + 768) = v2424;
    v2446 = *(_DWORD *)(v140 + 992);
    if ( (v2446 & 0x100) == 0 )
    {
      v2447 = (v2446 >> 9) & 1;
      v2448 = *(_QWORD *)(v140 + 712);
      v2449 = 0;
      v2856 = *(_DWORD *)(v140 + 716);
      v2450 = *(_DWORD *)(v140 + 608);
      v2859 = v2448;
      v2451 = (int *)v140;
      v2855 = v2450;
      v2452 = __ROR4__(v140, v140);
      v2849 = *(_DWORD *)(v140 + 612);
      v2904[0] = 0;
      v2904[3] = 1;
      v2904[5] = 2;
      v2904[8] = 3;
      v2904[6] = 4;
      v2904[9] = 5;
      v2904[12] = 6;
      v2904[7] = 7;
      v2904[13] = 8;
      v2904[10] = 9;
      v2904[14] = 10;
      v2904[4] = 11;
      v2904[1] = 12;
      v2904[15] = 13;
      v2904[11] = 14;
      v2904[2] = 15;
      v2453 = 0;
      do
      {
        v2454 = *v2451;
        v2455 = 8;
        do
        {
          v2454 = __ROR4__(v2454 & 0xFFFFFFF0 | (unsigned __int8)v2904[v2454 & 0xF], 4);
          --v2455;
        }
        while ( v2455 );
        v2456 = v2454 - v2453;
        v2457 = v2859;
        v2458 = v2855;
        *v2451 = v2454;
        *v2451 = v2454 - v2453;
        if ( v2447 )
          v2459 = v2456 ^ v2452;
        else
          v2459 = __ROR4__(bswap32(v2456 ^ v2458) ^ v2452, v2457) ^ v2457;
        *v2451 = v2459;
        v2460 = *v2451++;
        v2461 = __ROR4__((200 - v2449) * v2449, ~(_BYTE)v2460) ^ v2452;
        ++v2449;
        v2452 = __ROR4__(v2461, -(char)v2460) + v140;
        v2453 += v140;
      }
      while ( v2449 < 0x32 );
      v2252 = (int)v2843;
    }
    (*(void (__fastcall **)(unsigned int))(v140 + 376))(v140 + 820);
    v2249 = v2858;
  }
  v2462 = *(_DWORD *)(v2249 + 788);
  v2463 = 40;
  v2464 = v2960;
  v2465 = 10;
  v2466 = (char *)(v2249 + 880);
  do
  {
    v2467 = *(_DWORD *)v2466;
    v2466 += 4;
    v2463 -= 4;
    --v2465;
    *v2464++ = v2467;
  }
  while ( v2465 );
  for ( ; v2463; v2464 = (int *)((char *)v2464 + 1) )
  {
    v2468 = *v2466++;
    --v2463;
    *(_BYTE *)v2464 = v2468;
  }
  if ( (*(_DWORD *)(v2249 + 992) & 0x8000) != 0 || !*(_DWORD *)(v2249 + 880) )
  {
    v2469 = v2731 ^ v2842;
    v2470 = __mrc(15, 0, 9, 13, 0);
    v2471 = v2470 << 29;
    v2472 = v2470 ^ (v2470 >> 3);
    v2473 = 67117057i64 * (unsigned int)v2472;
    v2474 = 67117057i64 * v2471 + 1880096896i64 * (unsigned int)v2472;
    v2475 = (1880096896i64 * v2471 + (unsigned __int64)HIDWORD(v2474)) >> 32;
    v2476 = 1880096896 * v2471 + HIDWORD(v2474);
    if ( (unsigned int)(v2474 + HIDWORD(v2473)) < HIDWORD(v2473) )
      v2475 = (__PAIR64__(v2475, v2476++) + 1) >> 32;
    LODWORD(v2477) = v2473 ^ v2476;
    HIDWORD(v2477) = (v2474 + HIDWORD(v2473)) ^ v2475;
    v2478 = FsRtlRemovePerStreamContextEx(2i64, v2477);
    v2249 = v2858;
    v2479 = *(_DWORD *)(v2858 + 744);
    v2480 = (1 << v2478) | v2469;
    v2481 = *(_DWORD *)(v2858 + 748);
    if ( (*(_DWORD *)(v2858 + 992) & 0x800000) != 0 && v2252 )
    {
      v2482 = *(_DWORD *)(v2858 + 500);
      *(_BYTE *)v2481 = 19;
      *(_BYTE *)(v2481 + 1) = 1;
      *(_WORD *)(v2481 + 2) = 0;
      *(_DWORD *)(v2481 + 12) = v2482;
      *(_DWORD *)(v2481 + 16) = v2252;
      *(_DWORD *)(v2481 + 28) = 0;
      *(_DWORD *)(v2481 + 8) = 0;
      *(_DWORD *)(v2481 + 20) = v2480;
      (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(v2249 + 492))(
        *(_DWORD *)(v2252 + 4),
        *(_DWORD *)(v2252 + 8),
        *(_DWORD *)v2252);
      HIDWORD(v2485) = ((v2252 << 17) | ((unsigned int)(v2252 >> 31) >> 15)) ^ v2252;
      v2483 = (v2252 >> 31) ^ ((unsigned __int64)v2252 >> 15);
      v2792 = 1284865837 * HIDWORD(v2485);
      v2484 = *(_DWORD *)v2252;
      LODWORD(v2485) = 1481765933 * v2483
                     + ((1284865837i64 * v2483 + 1481765933 * (unsigned __int64)HIDWORD(v2485)) >> 32);
      if ( (unsigned int)(1284865837 * v2483
                        + 1481765933 * HIDWORD(v2485)
                        + ((1284865837 * (unsigned __int64)HIDWORD(v2485)) >> 32)) < (1284865837
                                                                                    * (unsigned __int64)HIDWORD(v2485)) >> 32 )
      {
        v2485 = 1481765933i64 * v2483
              + ((1284865837i64 * v2483 + 1481765933 * (unsigned __int64)HIDWORD(v2485)) >> 32)
              + 1;
        v2860 = HIDWORD(v2485);
      }
      HIDWORD(v2478) = v2252 + 16;
      LOBYTE(v2478) = v2792 ^ v2485;
      v2486 = v2792 ^ v2485;
      v2487 = 4;
      do
      {
        v2488 = *(_DWORD *)(HIDWORD(v2478) - 4);
        HIDWORD(v2478) -= 4;
        *(_DWORD *)HIDWORD(v2478) = v2488 ^ v2486;
        v2486 = __ROR4__(v2486, -(char)v2487--);
      }
      while ( v2487 );
      if ( ((unsigned __int8)v2478 & 0xFu) < 7 )
      {
        HIDWORD(v2490) = ((v2484 << 17) | ((unsigned int)(v2484 >> 31) >> 15)) ^ v2484;
        v2489 = (v2484 >> 31) ^ ((unsigned __int64)v2484 >> 15);
        v2793 = 1284865837 * HIDWORD(v2490);
        LODWORD(v2490) = 1481765933 * v2489
                       + ((1284865837i64 * v2489 + 1481765933 * (unsigned __int64)HIDWORD(v2490)) >> 32);
        if ( (unsigned int)(1284865837 * v2489
                          + 1481765933 * HIDWORD(v2490)
                          + ((1284865837 * (unsigned __int64)HIDWORD(v2490)) >> 32)) < (1284865837
                                                                                      * (unsigned __int64)HIDWORD(v2490)) >> 32 )
        {
          v2490 = 1481765933i64 * v2489
                + ((1284865837i64 * v2489 + 1481765933 * (unsigned __int64)HIDWORD(v2490)) >> 32)
                + 1;
          v2860 = HIDWORD(v2490);
        }
        v2491 = *(__int16 *)(v2484 + 4);
        v2492 = (v2793 ^ v2490) + v2486;
        v2493 = 7;
        v2494 = (int *)(v2484 + 28);
        do
        {
          v2495 = *--v2494;
          *v2494 = v2495 ^ v2492;
          v2492 = __ROR4__(v2492, -(char)v2493--);
        }
        while ( v2493 );
        HIDWORD(v2478) = (unsigned int)(v2491 - 28) >> 2;
        if ( HIDWORD(v2478) )
        {
          LODWORD(v2478) = v2484 + 28 + 4 * HIDWORD(v2478);
          do
          {
            v2496 = *(_DWORD *)(v2478 - 4);
            LODWORD(v2478) = v2478 - 4;
            *(_DWORD *)v2478 = v2496 ^ v2492;
            v2492 = __ROR4__(v2492, -BYTE4(v2478));
            --HIDWORD(v2478);
          }
          while ( HIDWORD(v2478) );
        }
      }
      v2249 = v2858;
    }
    else
    {
      *(_BYTE *)v2481 = 19;
      *(_BYTE *)(v2481 + 1) = 1;
      *(_WORD *)(v2481 + 2) = 0;
      *(_DWORD *)(v2481 + 12) = v2462;
      *(_DWORD *)(v2481 + 16) = v2480;
      *(_DWORD *)(v2481 + 28) = 0;
      *(_DWORD *)(v2481 + 8) = 0;
    }
    *(_DWORD *)(v2481 + 32) = v2731;
    __dmb(0xFu);
    (*(void (__fastcall **)(int, _DWORD))(v2249 + 368))(1, HIDWORD(v2478));
    v2497 = *(_DWORD *)(v2249 + 872);
    if ( v2497 )
    {
      switch ( v2497 )
      {
        case 1:
          *(_DWORD *)(*(_DWORD *)(v2249 + 776) + 1044) = v2481;
          break;
        case 2:
          *(_DWORD *)(*(_DWORD *)(v2249 + 776) + 1032) = v2481;
          break;
        case 3:
          v2519 = *(_DWORD *)(v2249 + 1000);
          v2520 = *(_DWORD *)(v2519 + 860);
          if ( v2520 )
          {
            if ( !*(_DWORD *)(v2249 + 880) )
            {
              *(_QWORD *)(v2249 + 888) = (unsigned int)(v2249 - 1849117464);
              *(_DWORD *)(v2249 + 896) = 0;
              *(_DWORD *)(v2249 + 900) = 0;
              *(_QWORD *)(v2249 + 904) = 260i64;
              *(_DWORD *)(v2249 + 912) = v2520;
              *(_DWORD *)(v2249 + 916) = 0;
              *(_DWORD *)(v2249 + 880) = 1;
            }
            v2521 = 40;
            v2522 = v2960;
            v2523 = 10;
            v2524 = (char *)(v2249 + 880);
            do
            {
              v2525 = *(_DWORD *)v2524;
              v2524 += 4;
              v2521 -= 4;
              --v2523;
              *v2522++ = v2525;
            }
            while ( v2523 );
            for ( ; v2521; v2522 = (int *)((char *)v2522 + 1) )
            {
              v2526 = *v2524++;
              --v2521;
              *(_BYTE *)v2522 = v2526;
            }
          }
          __dmb(0xFu);
          *(_DWORD *)(v2519 + 860) = v2481;
          break;
        case 4:
          v2509 = *(_DWORD *)(v2249 + 1036);
          v2510 = *(_DWORD *)(v2249 + 1000);
          v2511 = *(_DWORD *)(v2249 + 1044);
          v2512 = *(_DWORD *)(v2249 + 1040);
          *(_BYTE *)v2509 = 18;
          *(_BYTE *)(v2509 + 2) = 48;
          *(_BYTE *)(v2509 + 44) = 0;
          *(_DWORD *)(v2509 + 8) = v2510;
          *(_QWORD *)(v2509 + 20) = v2512;
          *(_DWORD *)(v2509 + 28) = v2511;
          *(_BYTE *)(v2509 + 45) = 0;
          *(_DWORD *)(v2509 + 32) = 0;
          *(_BYTE *)(v2509 + 46) = 0;
          if ( !(*(int (__fastcall **)(_DWORD, int, _DWORD, _DWORD))(v2249 + 412))(
                  *(_DWORD *)(v2249 + 1036),
                  v2481,
                  0,
                  0) )
          {
            if ( !*(_DWORD *)(v2249 + 880) )
            {
              *(_DWORD *)(v2249 + 888) = v2249 - 1849117464;
              *(_DWORD *)(v2249 + 892) = 0;
              *(_DWORD *)(v2249 + 896) = 0;
              *(_DWORD *)(v2249 + 900) = 0;
              *(_DWORD *)(v2249 + 904) = 260;
              *(_DWORD *)(v2249 + 908) = 0;
              *(_DWORD *)(v2249 + 912) = v2510;
              *(_DWORD *)(v2249 + 916) = 0;
              *(_DWORD *)(v2249 + 880) = 1;
            }
            v2513 = 40;
            v2514 = v2960;
            v2515 = 10;
            v2516 = (char *)(v2249 + 880);
            do
            {
              v2517 = *(_DWORD *)v2516;
              v2516 += 4;
              v2513 -= 4;
              --v2515;
              *v2514++ = v2517;
            }
            while ( v2515 );
            for ( ; v2513; v2514 = (int *)((char *)v2514 + 1) )
            {
              v2518 = *v2516++;
              --v2513;
              *(_BYTE *)v2514 = v2518;
            }
          }
          break;
        default:
          v2498 = *(int **)(v2249 + 1000);
          v2498[9] = v2481;
          __dmb(0xFu);
          v2499 = __mrc(15, 0, 9, 13, 0);
          v2500 = v2499 << 29;
          v2501 = v2499 ^ (v2499 >> 3);
          v2502 = 67117057i64 * (unsigned int)v2501;
          v2503 = 1880096896i64 * (unsigned int)v2501 + 67117057i64 * v2500;
          v2504 = (1880096896i64 * v2500 + (unsigned __int64)HIDWORD(v2503)) >> 32;
          v2505 = 1880096896 * v2500 + HIDWORD(v2503);
          if ( (unsigned int)(v2503 + HIDWORD(v2502)) < HIDWORD(v2502) )
            v2504 = (__PAIR64__(v2504, v2505++) + 1) >> 32;
          LODWORD(v2506) = v2502 ^ v2505;
          HIDWORD(v2506) = (v2503 + HIDWORD(v2502)) ^ v2504;
          v2507 = FsRtlRemovePerStreamContextEx(100000000i64, v2506);
          v2508 = FsRtlReInitializeTunnelCache((unsigned int)dword_989680, v2507 + 6000000000i64);
          v2249 = v2858;
          *v2498 = v2508;
          break;
      }
    }
    else
    {
      v2527 = __mrc(15, 0, 9, 13, 0);
      v2528 = v2527 << 29;
      v2529 = v2527 ^ (v2527 >> 3);
      v2530 = 67117057i64 * (unsigned int)v2529;
      v2531 = 67117057i64 * v2528 + 1880096896i64 * (unsigned int)v2529;
      v2532 = (1880096896i64 * v2528 + (unsigned __int64)HIDWORD(v2531)) >> 32;
      v2533 = 1880096896 * v2528 + HIDWORD(v2531);
      if ( (unsigned int)(v2531 + HIDWORD(v2530)) < HIDWORD(v2530) )
        v2532 = (__PAIR64__(v2532, v2533++) + 1) >> 32;
      LODWORD(v2534) = v2530 ^ v2533;
      HIDWORD(v2534) = (v2531 + HIDWORD(v2530)) ^ v2532;
      v2535 = -6000000000i64 - FsRtlRemovePerStreamContextEx(100000000i64, v2534);
      v2536 = __mrc(15, 0, 9, 13, 0);
      v2537 = v2536 << 29;
      v2538 = v2536 ^ (v2536 >> 3);
      v2539 = 67117057i64 * (unsigned int)v2538;
      v2540 = 67117057 * v2537 + 1880096896 * v2538;
      v2543 = 1880096896 * v2537 + ((67117057i64 * v2537 + 1880096896 * (unsigned __int64)(unsigned int)v2538) >> 32);
      v2542 = (1880096896i64 * v2537 + ((67117057i64 * v2537 + 1880096896 * (unsigned __int64)(unsigned int)v2538) >> 32)) >> 32;
      v2541 = v2543;
      v2544 = v2540 + HIDWORD(v2539);
      if ( v2544 < HIDWORD(v2539) )
      {
        v2542 = (__PAIR64__(v2542, v2543) + 1) >> 32;
        v2541 = v2543 + 1;
      }
      LODWORD(v2545) = v2539 ^ v2541;
      HIDWORD(v2545) = v2544 ^ v2542;
      v2546 = FsRtlRemovePerStreamContextEx(60000i64, v2545);
      v2249 = v2858;
      (*(void (__fastcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, int, int))(v2858 + 308))(
        v2479,
        *(_DWORD *)(v2858 + 308),
        v2535,
        HIDWORD(v2535),
        0,
        v2546,
        v2481);
    }
  }
  if ( v2960[0] && (*(_DWORD *)(v2249 + 992) & 0x8000) == 0 )
  {
    v2547 = v2963;
    v2548 = v2964;
    v2549 = (int)v2962;
    v2550 = v2961;
    v2881 = v2249;
    v2846 = v2963;
    v2873 = v2964;
    v2853 = v2962;
    v2871 = v2961;
    __disable_irq();
    v2551 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v2552 = *(_DWORD *)(v2551 + 3136);
    v2845 = v2552;
    v2553 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v2554 = *(unsigned __int8 *)(v2551 + 3162);
    v2841 = (unsigned int)v2553;
    __dmb(0xBu);
    if ( !v2554 || (unsigned int)&v2881 > v2552 || (unsigned int)&v2881 < v2552 - 12288 )
      v2845 = v2553[8];
    v2555 = (_DWORD *)v2881;
    v2556 = *(_DWORD *)(v2881 + 992);
    jj = v2881;
    if ( (v2556 & 0x8000000) == 0 )
    {
      v2557 = v2881 + 1104;
      v2558 = (char **)(v2881 + 1112);
      v2842 = v2881 + 1112 + 8 * *(_DWORD *)(v2881 + 1104);
      v2559 = (int *)v2842;
      v2733 = v2842;
      v2821 = (char **)(v2881 + 1112);
      v2560 = 0;
      if ( *(_DWORD *)(v2881 + 1108) )
      {
        do
        {
          v2561 = v2559[1];
          v2563 = (int *)*v2559;
          v2559 += 2;
          v2562 = v2563;
          if ( (unsigned int)(v2563 + 0x10000000) > 0x3FFFFF )
          {
            *v2562 = v2561;
          }
          else
          {
            v2564 = *v2562;
            v2855 = 0;
            __dmb(0xBu);
            *v2562 = v2561;
            if ( (v2564 & 2) == 0 && (v2561 & 2) != 0 )
              v2855 = 1;
            if ( (unsigned int)(v2562 + 267649024) <= 0xFFF )
            {
              v2565 = (unsigned __int16)v2562 & 0xFFF;
              v2566 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              if ( (v2561 & 2) != 0 )
              {
                if ( (v2561 & 0x400) != 0 )
                {
                  v2573 = v2561 & 0xFFF0000E | ((v2561 & 0xFF0) << 6) | 2;
                  v2898 = v2573;
                  if ( (v2561 & 1) != 0 )
                  {
                    v2573 = v2561 & 0xFFF0000E | ((v2561 & 0xFF0) << 6) | 0x12;
                    v2898 = v2573;
                  }
                  v2574 = (unsigned int *)(v2566 + 4 * v2565);
                  v2575 = 4;
                  do
                  {
                    __dmb(0xBu);
                    *v2574++ = v2573;
                    v2573 = ((v2898 & 0xFFF00000) + 0x100000) ^ v2898 & 0xFFFFF;
                    v2898 = v2573;
                    --v2575;
                  }
                  while ( v2575 );
                }
                else
                {
                  v2570 = v2561 & 0xFFFFF001 | 1;
                  v2571 = (unsigned int *)(v2566 + 4 * v2565);
                  v2911 = v2570;
                  v2572 = 4;
                  do
                  {
                    __dmb(0xBu);
                    *v2571++ = v2570;
                    v2570 = ((v2911 & 0xFFFFFC00) + 1024) ^ v2911 & 0x3FF;
                    v2911 = v2570;
                    --v2572;
                  }
                  while ( v2572 );
                }
              }
              else
              {
                v2567 = 16;
                v2568 = (_DWORD *)(v2566 + 4 * v2565);
                v2569 = 4;
                do
                {
                  v2567 -= 4;
                  --v2569;
                  *v2568++ = 0;
                }
                while ( v2569 );
                for ( ; v2567; --v2567 )
                {
                  *(_BYTE *)v2568 = 0;
                  v2568 = (_DWORD *)((char *)v2568 + 1);
                }
              }
            }
            if ( v2855 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          __mcr(15, 0, 0, 8, 7, 0);
          __mcr(15, 0, 0, 7, 5, 6);
          __dsb(0xFu);
          __isb(0xFu);
          ++v2560;
        }
        while ( v2560 < *(_DWORD *)(v2557 + 4) );
        v2555 = (_DWORD *)jj;
        v2558 = v2821;
        v2733 = (unsigned int)v2559;
      }
      if ( (unsigned int)v2558 < v2842 )
      {
        do
        {
          v2576 = (unsigned int)v2558[1];
          v2578 = *v2558;
          v2558 += 2;
          v2577 = v2578;
          v2579 = v2576;
          v2859 = (((unsigned __int16)v2578 & 0xFFF) + v2576 + 4095) >> 12;
          v2855 = 0;
          v2847 = v2576;
          v2827 = v2576;
          if ( v2859 )
          {
            do
            {
              v2580 = (((unsigned int)v2577 >> 10) & 0x3FFFFC) - 0x40000000;
              if ( (*(_DWORD *)(((v2580 >> 10) & 0x3FFFFC) - 0x40000000) & 0x400) != 0 )
                v2580 = ((v2580 >> 10) & 0x3FFFFC) - 0x40000000;
              v2581 = *(_DWORD *)v2580;
              v2582 = *(_DWORD *)v2580 & 0xFFFFFDFF | 0x90;
              if ( v2580 + 0x40000000 > 0x3FFFFF )
              {
                *(_DWORD *)v2580 = v2582;
              }
              else
              {
                v2583 = 0;
                __dmb(0xBu);
                *(_DWORD *)v2580 = v2582;
                if ( (v2581 & 2) == 0 && (v2582 & 2) != 0 )
                  v2583 = 1;
                if ( v2580 + 1070596096 <= 0xFFF )
                {
                  v2584 = v2580 & 0xFFF;
                  v2585 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  if ( (v2582 & 2) != 0 )
                  {
                    if ( (v2582 & 0x400) != 0 )
                    {
                      v2592 = v2582 & 0xFFF0000E | ((v2582 & 0xFF0) << 6) | 2;
                      v2901 = v2592;
                      if ( (v2582 & 1) != 0 )
                      {
                        v2592 = v2582 & 0xFFF0000E | ((v2582 & 0xFF0) << 6) | 0x12;
                        v2901 = v2592;
                      }
                      v2593 = (unsigned int *)(v2585 + 4 * v2584);
                      v2594 = 4;
                      do
                      {
                        __dmb(0xBu);
                        *v2593++ = v2592;
                        v2592 = ((v2901 & 0xFFF00000) + 0x100000) ^ v2901 & 0xFFFFF;
                        v2901 = v2592;
                        --v2594;
                      }
                      while ( v2594 );
                    }
                    else
                    {
                      v2589 = (unsigned int *)(v2585 + 4 * v2584);
                      v2590 = v2582 & 0xFFFFF001 | 1;
                      v2913 = v2590;
                      v2591 = 4;
                      do
                      {
                        __dmb(0xBu);
                        *v2589++ = v2590;
                        v2590 = ((v2913 & 0xFFFFFC00) + 1024) ^ v2913 & 0x3FF;
                        v2913 = v2590;
                        --v2591;
                      }
                      while ( v2591 );
                    }
                  }
                  else
                  {
                    v2586 = (_DWORD *)(v2585 + 4 * v2584);
                    v2587 = 4;
                    v2588 = 16;
                    do
                    {
                      v2588 -= 4;
                      --v2587;
                      *v2586++ = 0;
                    }
                    while ( v2587 );
                    for ( ; v2588; --v2588 )
                    {
                      *(_BYTE *)v2586 = 0;
                      v2586 = (_DWORD *)((char *)v2586 + 1);
                    }
                  }
                  v2579 = v2827;
                }
                if ( v2583 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
              __mcr(15, 0, 0, 8, 7, 0);
              __mcr(15, 0, 0, 7, 5, 6);
              __dsb(0xFu);
              __isb(0xFu);
              v2595 = 4096 - ((unsigned __int16)v2577 & 0xFFF);
              if ( v2595 >= v2579 )
                v2595 = v2579;
              v2596 = v2595;
              v2597 = v2559;
              v2598 = v2577;
              if ( v2595 >= 4 )
              {
                v2599 = v2595 >> 2;
                do
                {
                  v2600 = *v2597++;
                  v2596 -= 4;
                  --v2599;
                  *(_DWORD *)v2598 = v2600;
                  v2598 += 4;
                }
                while ( v2599 );
              }
              if ( v2596 )
              {
                v2601 = v2598 - (char *)v2597;
                do
                {
                  *((_BYTE *)v2597 + v2601) = *(_BYTE *)v2597;
                  v2597 = (int *)((char *)v2597 + 1);
                  --v2596;
                }
                while ( v2596 );
              }
              v2579 = v2827 - v2595;
              v2827 -= v2595;
              v2577 += v2595;
              v2559 = (int *)((char *)v2559 + v2595);
              if ( v2580 + 0x40000000 > 0x3FFFFF )
              {
                *(_DWORD *)v2580 = v2582;
              }
              else
              {
                v2602 = *(_DWORD *)v2580;
                v2603 = 0;
                __dmb(0xBu);
                *(_DWORD *)v2580 = v2582;
                if ( (v2602 & 2) == 0 && (v2582 & 2) != 0 )
                  v2603 = 1;
                if ( v2580 + 1070596096 <= 0xFFF )
                {
                  v2604 = v2580 & 0xFFF;
                  v2605 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  if ( (v2582 & 2) != 0 )
                  {
                    if ( (v2582 & 0x400) != 0 )
                    {
                      v2612 = v2582 & 0xFFF0000E | ((v2582 & 0xFF0) << 6) | 2;
                      v2900 = v2612;
                      if ( (v2582 & 1) != 0 )
                      {
                        v2612 = v2582 & 0xFFF0000E | ((v2582 & 0xFF0) << 6) | 0x12;
                        v2900 = v2612;
                      }
                      v2613 = (unsigned int *)(v2605 + 4 * v2604);
                      v2614 = 4;
                      do
                      {
                        __dmb(0xBu);
                        *v2613++ = v2612;
                        v2612 = ((v2900 & 0xFFF00000) + 0x100000) ^ v2900 & 0xFFFFF;
                        v2900 = v2612;
                        --v2614;
                      }
                      while ( v2614 );
                    }
                    else
                    {
                      v2609 = v2582 & 0xFFFFF001 | 1;
                      v2610 = (unsigned int *)(v2605 + 4 * v2604);
                      v2915 = v2609;
                      v2611 = 4;
                      do
                      {
                        __dmb(0xBu);
                        *v2610++ = v2609;
                        v2609 = ((v2915 & 0xFFFFFC00) + 1024) ^ v2915 & 0x3FF;
                        v2915 = v2609;
                        --v2611;
                      }
                      while ( v2611 );
                    }
                  }
                  else
                  {
                    v2606 = 16;
                    v2607 = (_DWORD *)(v2605 + 4 * v2604);
                    v2608 = 4;
                    do
                    {
                      v2606 -= 4;
                      --v2608;
                      *v2607++ = 0;
                    }
                    while ( v2608 );
                    for ( ; v2606; --v2606 )
                    {
                      *(_BYTE *)v2607 = 0;
                      v2607 = (_DWORD *)((char *)v2607 + 1);
                    }
                  }
                  v2579 = v2827;
                }
                if ( v2603 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
              }
              ++v2855;
            }
            while ( v2855 < v2859 );
            v2559 = (int *)v2733;
            v2576 = v2847;
          }
          v2559 = (int *)((char *)v2559 + v2576);
          v2733 = (unsigned int)v2559;
        }
        while ( (unsigned int)v2558 < v2842 );
        v2555 = (_DWORD *)jj;
      }
      v2908[0] = 18288;
      v2615 = v2908;
      v2616 = 2;
      v2617 = v2555[85] & 0xFFFFFFFE;
      v2794 = ((v2555[85] & 0xFFEu) + 4097) >> 12;
      v2855 = 0;
      for ( i1 = v2908; v2855 < v2794; ++v2855 )
      {
        v2618 = ((v2617 >> 10) & 0x3FFFFC) - 0x40000000;
        if ( (*(_DWORD *)(((v2618 >> 10) & 0x3FFFFC) - 0x40000000) & 0x400) != 0 )
          v2618 = ((v2618 >> 10) & 0x3FFFFC) - 0x40000000;
        v2619 = *(_DWORD *)v2618;
        v2620 = *(_DWORD *)v2618 & 0xFFFFFDFF | 0x90;
        if ( v2618 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v2618 = v2620;
        }
        else
        {
          v2621 = 0;
          __dmb(0xBu);
          *(_DWORD *)v2618 = v2620;
          if ( (v2619 & 2) == 0 && (v2620 & 2) != 0 )
            v2621 = 1;
          if ( v2618 + 1070596096 <= 0xFFF )
          {
            v2622 = v2618 & 0xFFF;
            v2623 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            if ( (v2620 & 2) != 0 )
            {
              if ( (v2620 & 0x400) != 0 )
              {
                v2630 = v2620 & 0xFFF0000E | ((v2620 & 0xFF0) << 6) | 2;
                v2897 = v2630;
                if ( (v2620 & 1) != 0 )
                {
                  v2630 = v2620 & 0xFFF0000E | ((v2620 & 0xFF0) << 6) | 0x12;
                  v2897 = v2630;
                }
                v2631 = (unsigned int *)(v2623 + 4 * v2622);
                v2632 = 4;
                do
                {
                  __dmb(0xBu);
                  *v2631++ = v2630;
                  v2630 = ((v2897 & 0xFFF00000) + 0x100000) ^ v2897 & 0xFFFFF;
                  v2897 = v2630;
                  --v2632;
                }
                while ( v2632 );
              }
              else
              {
                v2627 = (unsigned int *)(v2623 + 4 * v2622);
                v2628 = v2620 & 0xFFFFF001 | 1;
                v2909 = v2628;
                v2629 = 4;
                do
                {
                  __dmb(0xBu);
                  *v2627++ = v2628;
                  v2628 = ((v2909 & 0xFFFFFC00) + 1024) ^ v2909 & 0x3FF;
                  v2909 = v2628;
                  --v2629;
                }
                while ( v2629 );
              }
            }
            else
            {
              v2624 = (_DWORD *)(v2623 + 4 * v2622);
              v2625 = 4;
              v2626 = 16;
              do
              {
                v2626 -= 4;
                --v2625;
                *v2624++ = 0;
              }
              while ( v2625 );
              for ( ; v2626; --v2626 )
              {
                *(_BYTE *)v2624 = 0;
                v2624 = (_DWORD *)((char *)v2624 + 1);
              }
            }
          }
          if ( v2621 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
          v2615 = i1;
        }
        __mcr(15, 0, 0, 8, 7, 0);
        __mcr(15, 0, 0, 7, 5, 6);
        __dsb(0xFu);
        __isb(0xFu);
        v2633 = 4096 - (v2617 & 0xFFF);
        if ( v2633 >= v2616 )
          v2633 = v2616;
        v2634 = v2615;
        v2635 = v2633;
        v2636 = (char *)v2617;
        if ( v2633 >= 4 )
        {
          v2637 = v2633 >> 2;
          do
          {
            v2638 = *(_DWORD *)v2634;
            v2634 += 2;
            v2635 -= 4;
            --v2637;
            *(_DWORD *)v2636 = v2638;
            v2636 += 4;
          }
          while ( v2637 );
        }
        if ( v2635 )
        {
          v2639 = v2636 - (char *)v2634;
          do
          {
            *((_BYTE *)v2634 + v2639) = *(_BYTE *)v2634;
            v2634 = (__int16 *)((char *)v2634 + 1);
            --v2635;
          }
          while ( v2635 );
        }
        v2617 += v2633;
        v2615 = (__int16 *)((char *)i1 + v2633);
        i1 = (__int16 *)((char *)i1 + v2633);
        v2616 -= v2633;
        if ( v2618 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v2618 = v2620;
        }
        else
        {
          v2640 = *(_DWORD *)v2618;
          v2641 = 0;
          __dmb(0xBu);
          *(_DWORD *)v2618 = v2620;
          if ( (v2640 & 2) == 0 && (v2620 & 2) != 0 )
            v2641 = 1;
          if ( v2618 + 1070596096 <= 0xFFF )
          {
            v2642 = v2618 & 0xFFF;
            v2643 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            if ( (v2620 & 2) != 0 )
            {
              if ( (v2620 & 0x400) != 0 )
              {
                v2650 = v2620 & 0xFFF0000E | ((v2620 & 0xFF0) << 6) | 2;
                v2899 = v2650;
                if ( (v2620 & 1) != 0 )
                {
                  v2650 = v2620 & 0xFFF0000E | ((v2620 & 0xFF0) << 6) | 0x12;
                  v2899 = v2650;
                }
                v2651 = (unsigned int *)(v2643 + 4 * v2642);
                v2652 = 4;
                do
                {
                  __dmb(0xBu);
                  *v2651++ = v2650;
                  v2650 = ((v2899 & 0xFFF00000) + 0x100000) ^ v2899 & 0xFFFFF;
                  v2899 = v2650;
                  --v2652;
                }
                while ( v2652 );
              }
              else
              {
                v2647 = v2620 & 0xFFFFF001 | 1;
                v2648 = (unsigned int *)(v2643 + 4 * v2642);
                v2914 = v2647;
                v2649 = 4;
                do
                {
                  __dmb(0xBu);
                  *v2648++ = v2647;
                  v2647 = ((v2914 & 0xFFFFFC00) + 1024) ^ v2914 & 0x3FF;
                  v2914 = v2647;
                  --v2649;
                }
                while ( v2649 );
              }
            }
            else
            {
              v2644 = 16;
              v2645 = (_DWORD *)(v2643 + 4 * v2642);
              v2646 = 4;
              do
              {
                v2644 -= 4;
                --v2646;
                *v2645++ = 0;
              }
              while ( v2646 );
              for ( ; v2644; --v2644 )
              {
                *(_BYTE *)v2645 = 0;
                v2645 = (_DWORD *)((char *)v2645 + 1);
              }
            }
          }
          if ( v2641 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
      }
      v2653 = __mrc(15, 1, 0, 0, 1);
      v2654 = __mrc(15, 0, 0, 0, 0);
      v2655 = (v2653 >> 21) & 7;
      if ( (v2654 & 0xFFF0) == 49296 && (v2654 & 0xFF000000) == 1090519040 && (v2870 & v2654) < 0x100000 )
        v2655 = (v2653 >> 27) & 7;
      for ( i2 = 0; i2 < v2655; ++i2 )
      {
        __mcr(15, 2, 2 * (i2 & 7), 0, 0, 0);
        __isb(0xFu);
        v2657 = __mrc(15, 1, 0, 0, 0);
        v2658 = ((v2657 >> 3) & 0x3FF) + 1;
        v2659 = 0;
        for ( i3 = v2658 >> 1; i3; i3 >>= 1 )
          ++v2659;
        if ( ((v2657 >> 3) & 0x3FF & (((v2657 >> 3) & 0x3FF) + 1)) != 0 )
          ++v2659;
        v2661 = 32 - v2659;
        do
        {
          --v2658;
          v2662 = ((v2657 >> 13) & 0x7FFF) + 1;
          do
            __mcr(15, 0, (--v2662 << ((v2657 & 7) + 4)) | (2 * i2) | (v2658 << v2661), 7, 10, 2);
          while ( v2662 );
        }
        while ( v2658 );
      }
      __dsb(0xFu);
      __mcr(15, 0, 0, 7, 5, 0);
      __mcr(15, 0, 0, 7, 5, 6);
      __dsb(0xFu);
      __isb(0xFu);
      v2555 = (_DWORD *)v2881;
      v2553 = (_DWORD *)v2841;
      v2547 = v2846;
      v2548 = v2873;
      v2549 = (int)v2853;
      v2550 = v2871;
    }
    if ( v2555[233] )
      __disable_irq();
    v2663 = v2555[233];
    if ( !v2663 )
    {
LABEL_3247:
      v2679 = (int *)v2845;
      v2553[214] = 0;
      v2553[231] = 0;
      PspInitDeferredResourceReservation(
        265,
        v2550,
        v2549,
        v2548,
        v2547,
        *(int (__fastcall **)(int))(v2881 + 264),
        v2679);
      __debugbreak();
    }
    if ( v2663 == 1 )
    {
      v2677 = (unsigned __int8 *)v2555[164];
      do
        v2678 = __ldrex(v2677);
      while ( __strex(v2678 | 1, v2677) );
    }
    else
    {
      if ( v2663 == 2 )
      {
        v2671 = (unsigned __int8 *)v2555[166];
      }
      else
      {
        if ( v2663 != 3 )
        {
          if ( v2663 == 4 )
          {
            v2670 = __mrc(15, 0, 13, 0, 3);
            v2667 = 1 << ((v2555[248] >> 10) & 7);
            v2668 = (unsigned __int8 *)(*(_DWORD *)((v2670 & 0xFFFFFFC0) + 0x74) + (((v2555[248] >> 10) & 0x1F) >> 3));
          }
          else
          {
            if ( v2663 != 5 )
            {
              v2664 = v2555[177];
              v2665 = *(_QWORD *)(v2664 + 832);
              *(_DWORD *)(v2664 + 832) = v2665 | 1;
              *(_DWORD *)(v2664 + 836) = HIDWORD(v2665);
              goto LABEL_3247;
            }
            v2666 = __mrc(15, 0, 13, 0, 3);
            v2667 = 1 << ((v2555[248] >> 10) & 7);
            v2668 = (unsigned __int8 *)((v2666 & 0xFFFFFFC0) + (((v2555[248] >> 10) & 0x1F) >> 3));
          }
          do
            v2669 = __ldrex(v2668);
          while ( __strex(v2669 | v2667, v2668) );
          goto LABEL_3246;
        }
        v2671 = (unsigned __int8 *)v2555[167];
      }
      do
        v2672 = __ldrex(v2671);
      while ( __strex(v2672 | 1, v2671) );
    }
LABEL_3246:
    __dmb(0xBu);
    goto LABEL_3247;
  }
  if ( v2704 )
  {
    v2673 = *(_DWORD *)(v2249 + 928);
    if ( v2673 == 1 )
    {
      v2675 = (_DWORD *)(*(_DWORD *)(v2249 + 780) - 4);
      *(_DWORD *)(v2249 + 780) = v2675;
      *(_DWORD *)(v2249 + 784) = *v2675;
      v2674 = *(_DWORD *)(v2249 + 348);
      goto LABEL_3226;
    }
    if ( v2673 == 3 )
    {
      v2674 = *(_DWORD *)(v2249 + 496);
LABEL_3226:
      *(_DWORD *)(v2249 + 220) = v2674;
      return v2249;
    }
  }
  return v2249;
}
