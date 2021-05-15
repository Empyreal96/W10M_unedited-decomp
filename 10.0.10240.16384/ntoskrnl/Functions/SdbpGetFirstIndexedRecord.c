// SdbpGetFirstIndexedRecord 
 
int __fastcall SdbpGetFirstIndexedRecord(int a1, int a2, unsigned int a3, unsigned int a4, _DWORD *a5)
{
  int result; // r0
  unsigned int v9; // r8
  int v10; // r0
  int v11; // r9
  int v12; // r0
  int v13; // r7
  int v14; // r5
  int v15; // r6
  unsigned int v16; // r2
  unsigned __int64 v18; // [sp+10h] [bp-28h] BYREF

  if ( SdbGetTagFromTagID() != 38913 )
    return sub_7CCA4C();
  v9 = SdbGetTagDataSize(a1, a2) / 0xCu;
  v10 = SdbpGetMappedTagData(a1, a2);
  v11 = v10;
  if ( !v10 )
    JUMPOUT(0x7CCA54);
  if ( (a5[5] & 1) == 0 )
  {
    v12 = SdbpBinarySearchFirst(v10);
    goto LABEL_6;
  }
  v13 = 0;
  v14 = -1;
  v15 = v9 - 1;
  a5[4] = -1;
  if ( (int)(v9 - 1) >= 0 )
  {
    while ( 1 )
    {
      v14 = (v15 + v13) / 2;
      if ( v14 < 0 || v14 >= v9 )
        break;
      memmove((int)&v18, v11 + 12 * v14, 8u);
      if ( a4 > HIDWORD(v18) )
        goto LABEL_22;
      if ( a4 < HIDWORD(v18) || a3 <= (unsigned int)v18 )
        v15 = v14 - 1;
      if ( __PAIR64__(a4, a3) >= v18 )
LABEL_22:
        v13 = v14 + 1;
      if ( v15 < v13 )
        goto LABEL_9;
    }
    v12 = 0;
  }
  else
  {
LABEL_9:
    if ( v13 - v15 > 1 )
    {
      v12 = 1;
      a5[4] = v14;
    }
    else
    {
      v12 = 0;
    }
    if ( v12 )
    {
      v16 = a5[4];
      if ( v16 < v9 - 1 )
      {
        a5[2] = *(_DWORD *)(v11 + 12 * v16 + 20);
        goto LABEL_13;
      }
    }
  }
  a5[2] = 0;
LABEL_13:
  a5[1] = 0;
LABEL_6:
  if ( v12 )
    result = *(_DWORD *)(v11 + 12 * a5[4] + 8);
  else
    result = 0;
  return result;
}
