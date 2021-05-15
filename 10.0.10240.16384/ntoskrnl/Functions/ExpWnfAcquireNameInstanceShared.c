// ExpWnfAcquireNameInstanceShared 
 
int __fastcall ExpWnfAcquireNameInstanceShared(int a1, int a2, int (*a3)(void))
{
  int v3; // r0
  int (__fastcall *v4)(int); // r2
  int v5; // r0
  int (__fastcall *v6)(int); // r2
  int v7; // r0
  int (__fastcall *v8)(int); // r2
  int v9; // r0
  int (__fastcall *v10)(int); // r2
  int v11; // r0
  int (__fastcall *v12)(int); // r2
  int v13; // r0
  int (__fastcall *v14)(int); // r2
  int v15; // r0
  int (__fastcall *v16)(int); // r2
  int v17; // r0
  int (__fastcall *v18)(int); // r2
  int v19; // r0
  int (__fastcall *v20)(int); // r2
  int v21; // r0
  int (__fastcall *v22)(int); // r2
  int v23; // r0
  int (__fastcall *v24)(int); // r2
  int v25; // r0
  int (__fastcall *v26)(int); // r2
  int v27; // r0
  int (__fastcall *v28)(int); // r2
  int v29; // r0
  int (__fastcall *v30)(int); // r2
  int v31; // r0
  int (__fastcall *v32)(int); // r2
  int v33; // r0
  int (__fastcall *v34)(int); // r2
  int v35; // r0
  int (__fastcall *v36)(int); // r2
  int v37; // r0
  int (__fastcall *v38)(int); // r2
  int v39; // r0
  int (__fastcall *v40)(int); // r2
  int v41; // r0
  int (__fastcall *v42)(int); // r2
  int v43; // r0
  int (__fastcall *v44)(int); // r2
  int v45; // r0
  int (__fastcall *v46)(int); // r2
  int v47; // r0
  int (__fastcall *v48)(int); // r2
  int v49; // r0
  int (__fastcall *v50)(int); // r2
  int v51; // r0
  int (__fastcall *v52)(int); // r2
  int v53; // r0
  int (__fastcall *v54)(int); // r2
  int v55; // r0
  int (__fastcall *v56)(int); // r2
  int v57; // r0
  int (__fastcall *v58)(int); // r2
  int v59; // r0
  int (__fastcall *v60)(int); // r2
  int v61; // r0
  int (__fastcall *v62)(int); // r2
  int v63; // r0
  int (__fastcall *v64)(int); // r2
  int v65; // r0
  int (__fastcall *v66)(int); // r2
  int v67; // r0
  int (__fastcall *v68)(int); // r2
  int v69; // r0
  int (__fastcall *v70)(int); // r2
  int v71; // r0
  int (__fastcall *v72)(int); // r2
  int v73; // r0
  int (__fastcall *v74)(int); // r2
  int v75; // r0
  int (__fastcall *v76)(int); // r2
  int v77; // r0
  int (__fastcall *v78)(int); // r2
  int v79; // r0
  int (__fastcall *v80)(int); // r2
  int v81; // r0
  int (__fastcall *v82)(int); // r2
  int v83; // r0
  int (__fastcall *v84)(int); // r2
  int v85; // r0
  int (__fastcall *v86)(int); // r2
  int v87; // r0
  int (__fastcall *v88)(int); // r2
  int v89; // r0
  int (__fastcall *v90)(int); // r2
  int v91; // r0
  int (__fastcall *v92)(int); // r2
  int v93; // r0
  int (__fastcall *v94)(int); // r2
  int v95; // r0
  int (__fastcall *v96)(int); // r2
  int v97; // r0
  int (__fastcall *v98)(int); // r2
  int v99; // r0
  int v100; // r1
  int (*v101)(void); // r2
  int v102; // r3
  int *v103; // r4
  int v104; // r12
  int v105; // r0
  int v106; // r0

  v3 = a3();
  v5 = v4(v3);
  v7 = v6(v5);
  v9 = v8(v7);
  v11 = v10(v9);
  v13 = v12(v11);
  v15 = v14(v13);
  v17 = v16(v15);
  v19 = v18(v17);
  v21 = v20(v19);
  v23 = v22(v21);
  v25 = v24(v23);
  v27 = v26(v25);
  v29 = v28(v27);
  v31 = v30(v29);
  v33 = v32(v31);
  v35 = v34(v33);
  v37 = v36(v35);
  v39 = v38(v37);
  v41 = v40(v39);
  v43 = v42(v41);
  v45 = v44(v43);
  v47 = v46(v45);
  v49 = v48(v47);
  v51 = v50(v49);
  v53 = v52(v51);
  v55 = v54(v53);
  v57 = v56(v55);
  v59 = v58(v57);
  v61 = v60(v59);
  v63 = v62(v61);
  v65 = v64(v63);
  v67 = v66(v65);
  v69 = v68(v67);
  v71 = v70(v69);
  v73 = v72(v71);
  v75 = v74(v73);
  v77 = v76(v75);
  v79 = v78(v77);
  v81 = v80(v79);
  v83 = v82(v81);
  v85 = v84(v83);
  v87 = v86(v85);
  v89 = v88(v87);
  v91 = v90(v89);
  v93 = v92(v91);
  v95 = v94(v93);
  v97 = v96(v95);
  v99 = v98(v97);
  v102 = *(_DWORD *)(v99 - 4);
  v103 = (int *)(v99 + 4 * v102 - 4);
  do
  {
    v104 = *v103 ^ v100;
    v100 = __ROR4__(v100, v102);
    *v103 = v104;
    --v102;
    --v103;
  }
  while ( v102 );
  v105 = v101();
  v106 = ((int (__fastcall *)(int, int))((*(_DWORD *)(v105 + 796) + v105 - 4) | 1))(v105 - 4, v105 - 4);
  return (*(int (__fastcall **)(int, int))(v106 + 228))(v106 + 752, 1);
}
