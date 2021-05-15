// BgpFwQueryBootGraphicsInformation 
 
int __fastcall BgpFwQueryBootGraphicsInformation(int a1, _DWORD *a2)
{
  int v2; // r4
  int v4; // r9
  int v5; // r2
  int v6; // r3
  int v7; // r4
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v12; // r10
  unsigned int v13; // r5
  int v14; // r0
  _DWORD *v15; // r0
  _DWORD *v16; // r6
  int v17; // r0

  v2 = 0;
  v4 = 0;
  if ( !a1 )
  {
    v5 = dword_618FFC;
    v6 = dword_619000;
    v7 = dword_619004;
    *a2 = dword_618FF8;
    a2[1] = v5;
    a2[2] = v6;
    a2[3] = v7;
    v8 = *(_DWORD *)algn_61900C;
    v9 = dword_619010;
    v10 = *(_DWORD *)algn_619014;
    a2[4] = dword_619008;
    a2[5] = v8;
    a2[6] = v9;
    a2[7] = v10;
    a2[5] = 0;
    if ( (dword_619018 & 2) != 0 )
      a2[5] = 1;
    return v4;
  }
  if ( a1 != 2 )
  {
    if ( a1 == 3 )
    {
      memmove((int)a2, (int)&unk_6190A4, 0x80u);
      return v4;
    }
    v12 = dword_619060;
    if ( !dword_61905C && !dword_619060 )
      JUMPOUT(0x54D858);
    v13 = dword_619064;
    if ( !dword_619060 )
    {
      v14 = BgpFwAllocateMemory(dword_619064);
      v2 = v14;
      if ( !v14 )
        return -1073741801;
      v12 = v14;
      memmove(v14, dword_61905C, v13);
    }
    if ( v13 + 8 < v13 )
    {
      v4 = -1073741675;
    }
    else
    {
      v4 = 0;
      BgpFwReleaseLock();
      v15 = (_DWORD *)ExAllocatePoolWithTag(1, v13 + 8);
      v16 = v15;
      if ( v15 )
      {
        *v15 = (dword_619018 & 0x800000) != 0;
        v15[1] = 8;
        v17 = memmove((int)(v15 + 2), v12, v13);
        BgpFwAcquireLock(v17);
        *a2 = v16;
      }
      else
      {
        BgpFwAcquireLock(0);
        v4 = -1073741801;
      }
    }
    if ( v2 )
      BgpFwFreeMemory(v2);
    return v4;
  }
  return sub_54D848();
}
