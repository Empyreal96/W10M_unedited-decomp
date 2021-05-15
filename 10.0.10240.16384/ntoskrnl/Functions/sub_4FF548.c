// sub_4FF548 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_4FF548(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int *a14, int a15, int a16, unsigned int a17, _DWORD *a18)
{
  _DWORD *v18; // r3
  _DWORD *v19; // r9
  unsigned __int16 *v20; // r2
  unsigned __int16 *v21; // r10
  _DWORD *v22; // r1
  _DWORD *v23; // r8
  char v24; // r0
  char v25; // r7
  unsigned int v26; // r6
  _WORD *v27; // r5
  unsigned int i; // r3
  unsigned int v29; // r2
  unsigned int v30; // r0
  _BYTE v31[6098]; // [sp-17D2h] [bp-1FFCh] BYREF

  _chkstk();
  v19 = v18;
  v21 = v20;
  v23 = v22;
  v25 = v24;
  v26 = 0;
  memset(v31, 0, 0x2000);
  v27 = (_WORD *)(*v23 + 2);
  *v23 = v27;
  if ( *v27 == 94 )
  {
    ++v27;
    v25 |= 8u;
  }
  if ( *v27 == 93 )
  {
    v26 = 93;
    ++v27;
    v31[11] = 32;
  }
  for ( i = (unsigned __int16)*v27; i != 93; i = (unsigned __int16)*v27 )
  {
    ++v27;
    if ( i == 45 && v26 && (v29 = (unsigned __int16)*v27, v29 != 93) )
    {
      ++v27;
      if ( v26 >= v29 )
      {
        v30 = v26;
        v26 = v29;
      }
      else
      {
        v30 = v29;
      }
      for ( ; v26 <= v30; v26 = (unsigned __int16)(v26 + 1) )
        v31[v26 >> 3] |= 1 << (v26 & 7);
      v26 = 0;
    }
    else
    {
      v26 = i;
      v31[i >> 3] |= 1 << (i & 7);
    }
  }
  if ( *v27 )
  {
    *v23 = v27;
    sub_4FF3AC(v25, (int)v31, v21, v19, a14, a15, a16, a17, a18);
  }
  __asm { POP.W           {R4-R11,PC} }
}
