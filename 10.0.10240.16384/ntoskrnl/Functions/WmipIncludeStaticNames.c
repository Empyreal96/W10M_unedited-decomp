// WmipIncludeStaticNames 
 
int __fastcall WmipIncludeStaticNames(_DWORD *a1, unsigned int a2)
{
  _DWORD *v3; // r6
  int v5; // r5
  int v6; // r7
  _DWORD *i; // r0
  int v8; // r0
  int v9; // r2
  unsigned int v10; // r1
  int v12; // r3

  v3 = 0;
  if ( (a1[11] & 7) != 0 )
  {
    v5 = WmipFindGEByGuid(a1 + 6, 0);
    if ( v5 )
    {
      v6 = a1[1];
      KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
      for ( i = *(_DWORD **)(v5 + 32); i != (_DWORD *)(v5 + 32); i = (_DWORD *)*i )
      {
        if ( i[11] == v6 )
        {
          v3 = i;
          WmipReferenceEntry();
          break;
        }
      }
      KeReleaseMutex((int)&WmipSMMutex);
      v8 = WmipUnreferenceEntry(&WmipGEChunkInfo, v5);
      if ( v3 )
      {
        v9 = v3[2];
        if ( (v9 & 3) != 0 )
        {
          v10 = v3[9];
          if ( (a1[11] & 1) != 0 )
            return sub_7D6018(v8, v10);
          if ( a1[13] < v10 )
          {
            if ( (v9 & 2) == 0 )
            {
              wcslen((unsigned __int16 *)(v3[12] + 4));
              JUMPOUT(0x7D6068);
            }
            JUMPOUT(0x7D605C);
          }
        }
      }
    }
  }
  v12 = a1[11];
  if ( (v12 & 1) != 0 && a2 >= 0x3C )
  {
    a1[14] = 0;
  }
  else if ( (v12 & 6) != 0 && a2 >= 0x34 )
  {
    a1[12] = 0;
  }
  if ( v3 )
    WmipUnreferenceEntry(&WmipISChunkInfo, v3);
  return (int)a1;
}
