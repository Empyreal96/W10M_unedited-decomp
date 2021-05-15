// LogFwStat 
 
int __fastcall LogFwStat(_QWORD *a1, int a2, __int64 a3)
{
  int v5; // r6
  _DWORD *v6; // r0
  int v7; // r3
  __int64 v9; // kr00_8
  __int64 *v10; // r3
  __int64 *v11; // r2
  int *v12; // r2
  bool v13; // cf
  __int64 *v14; // r2
  __int64 v15[3]; // [sp+0h] [bp-18h] BYREF

  v15[0] = a3;
  v5 = a3;
  v6 = BgpFwQueryPerformanceCounter(v15, SHIDWORD(a3), a3, SHIDWORD(a3));
  qword_641968 = v15[0];
  if ( a2 )
    return sub_8DF3F0(v6);
  BgpFwQueryPerformanceCounter(v15, 0, v15[0], v7);
  v9 = v15[0] - qword_6462A0[v5];
  qword_641970 = v9;
  switch ( v5 )
  {
    case 0:
      if ( v9 < qword_6180E8 )
        qword_6180E8 = v9;
      if ( v9 > qword_64A5A0 )
        qword_64A5A0 = v9;
      v14 = &qword_64A5D8;
      goto LABEL_13;
    case 1:
      if ( v9 < qword_6180E8 )
        qword_6180E8 = v9;
      if ( v9 > qword_64A5A0 )
        qword_64A5A0 = v9;
      qword_64A5D8 += v9;
      v14 = (__int64 *)&dword_64A5B0;
LABEL_13:
      v13 = __CFADD__(*(_DWORD *)v14, (_DWORD)v9);
      *(_DWORD *)v14 += v9;
      *((_DWORD *)v14 + 1) += HIDWORD(v9) + v13;
      ++dword_64A5BC;
      goto LABEL_14;
    case 2:
      v10 = (__int64 *)&unk_64A5C0;
      v11 = &qword_64A5D8;
      goto LABEL_11;
    case 3:
      v12 = &dword_64A590;
      goto LABEL_15;
    case 4:
      v12 = &dword_64A598;
      goto LABEL_15;
    case 5:
      v10 = (__int64 *)&unk_64A5A8;
      v11 = &qword_64A588;
LABEL_11:
      *v10 = v9;
      v13 = __CFADD__(*(_DWORD *)v11, (_DWORD)v9);
      *(_DWORD *)v11 += v9;
      *((_DWORD *)v11 + 1) += HIDWORD(v9) + v13;
LABEL_14:
      v12 = (int *)&qword_64A5D0;
      goto LABEL_15;
    case 6:
      if ( v9 < qword_6180F0 )
        qword_6180F0 = v9;
      if ( v9 > qword_64A5C8 )
        qword_64A5C8 = v9;
      qword_64A588 += v9;
      qword_64A5D0 += v9;
      ++dword_64A5B8;
      break;
    case 7:
      qword_641978 = v9;
      break;
    case 8:
      v12 = &dword_64A5E8;
LABEL_15:
      v13 = __CFADD__(*v12, (_DWORD)v9);
      *v12 += v9;
      v12[1] += HIDWORD(v9) + v13;
      break;
    default:
      break;
  }
  *a1 = qword_641968;
  return (int)a1;
}
