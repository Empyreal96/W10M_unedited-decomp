// WmipAllocateSingleInstanceWnode 
 
int __fastcall WmipAllocateSingleInstanceWnode(unsigned int a1, unsigned __int16 *a2, unsigned int a3, unsigned int *a4, unsigned int *a5, int *a6, _DWORD *a7)
{
  unsigned int v7; // r4
  int v8; // r6
  unsigned int v10; // r5
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r4
  int v15; // r7
  _BYTE *v16; // r0
  _BYTE *v17; // r8

  v7 = a1 + 1;
  v8 = -1073741670;
  if ( a1 + 1 >= a1 )
  {
    v10 = v7 & 0xFFFFFFFE;
    v11 = *a2 + 2;
    if ( v11 <= -1 - (v7 & 0xFFFFFFFE) )
    {
      v12 = v11 + v10;
      v13 = v11 + v10 + 7;
      if ( v13 >= v12 )
      {
        v14 = v13 & 0xFFFFFFF8;
        if ( a3 <= -1 - (v13 & 0xFFFFFFF8) )
        {
          v15 = v14 + a3;
          v16 = (_BYTE *)ExAllocatePoolWithTag(512, v14 + a3, 1885957463);
          v17 = v16;
          if ( v16 )
          {
            memset(v16, 0, v15);
            *a4 = v10;
            v8 = 0;
            *a5 = v14;
            *a6 = v15;
            *a7 = v17;
          }
        }
      }
    }
  }
  return v8;
}
