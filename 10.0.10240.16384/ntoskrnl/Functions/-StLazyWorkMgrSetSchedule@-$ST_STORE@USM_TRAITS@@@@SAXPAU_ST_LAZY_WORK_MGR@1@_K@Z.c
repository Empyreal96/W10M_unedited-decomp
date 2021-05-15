// -StLazyWorkMgrSetSchedule@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_LAZY_WORK_MGR@1@_K@Z 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall ST_STORE<SM_TRAITS>::StLazyWorkMgrSetSchedule(unsigned int result, __int64 a2)
{
  unsigned int v3; // r4
  unsigned int v4; // r5
  __int64 v5; // kr00_8
  unsigned int v6; // r6
  unsigned int v7; // r7
  _QWORD *v8; // lr
  unsigned int v9; // r7
  unsigned int v10; // r8
  unsigned int v11; // r1
  unsigned int v12; // r6
  unsigned int v13; // r9 OVERLAPPED
  unsigned int v14; // r10 OVERLAPPED
  unsigned __int64 v15; // kr18_8
  int v16; // r2
  unsigned int v17; // r3
  unsigned __int64 v18; // [sp+0h] [bp-28h]
  unsigned int v19; // [sp+8h] [bp-20h]

  v3 = HIDWORD(a2);
  v4 = a2;
  v19 = result;
  if ( !a2 )
  {
    do
    {
      v5 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v6 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v7 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v6 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v5 != MEMORY[0xFFFF93B0] );
    v3 = (__PAIR64__(v6, v7) - v5) >> 32;
    v4 = v7 - v5;
  }
  v8 = (_QWORD *)result;
  v9 = -1;
  v10 = -1;
  v11 = -1;
  v12 = -1;
  if ( result < result + 144 )
  {
    do
    {
      *(_QWORD *)&v13 = v8[1];
      if ( (v13 & v14) != -1 )
      {
        v18 = v8[2];
        if ( v18 < __PAIR64__(v3, v4) - *(_QWORD *)(result + 160) )
          v18 = __PAIR64__(v3, v4) - *(_QWORD *)(result + 160);
        v15 = *v8 + v18;
        result = v19;
        if ( v15 < __PAIR64__(v10, v9) )
        {
          v10 = HIDWORD(v15);
          v9 = v15;
        }
        if ( v14 <= v12 && (v14 < v12 || v13 < v11) )
        {
          v11 = v13;
          v12 = v14;
        }
      }
      v8 += 3;
    }
    while ( (unsigned int)v8 < result + 144 );
  }
  if ( v10 <= v3 && (v10 < v3 || v9 < v4) )
  {
    v9 = v4;
    v10 = v3;
  }
  if ( v12 <= v3 && (v12 < v3 || v11 < v4) )
  {
    v11 = v4;
    v12 = v3;
  }
  *(_DWORD *)(result + 144) = v11;
  *(_DWORD *)(result + 148) = v12;
  if ( (v11 & v12) == -1 )
  {
    *(_DWORD *)(result + 152) = 0;
LABEL_35:
    *(_DWORD *)(result + 156) = 0;
    goto LABEL_36;
  }
  if ( v12 > v10 || v12 >= v10 && v11 >= v9 )
  {
    v16 = (__PAIR64__(v10, v9) - __PAIR64__(v3, v4)) >> 32;
    v17 = v9 - v4;
  }
  else
  {
    v16 = (__PAIR64__(v12, v11) - __PAIR64__(v3, v4)) >> 32;
    v17 = v11 - v4;
  }
  *(_DWORD *)(result + 152) = v17;
  *(_DWORD *)(result + 156) = v16;
  if ( !(*(_DWORD *)(result + 156) | v17) )
  {
    *(_DWORD *)(result + 152) = 1;
    goto LABEL_35;
  }
LABEL_36:
  *(_QWORD *)(*(_DWORD *)(result - 3260) + 3872) = -*(_QWORD *)(result + 152);
  return result;
}
