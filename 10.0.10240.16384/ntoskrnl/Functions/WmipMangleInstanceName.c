// WmipMangleInstanceName 
 
int __fastcall WmipMangleInstanceName(unsigned int a1, unsigned __int16 *a2, unsigned int a3, _WORD *a4)
{
  int v8; // r7
  int *v9; // r8
  int v10; // r6
  _WORD *v11; // r5
  int i; // r4
  _DWORD *v13; // r0
  int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = (int)a4;
  RtlStringCchLengthW(a2, 0x7FFFFFFFu, v15);
  RtlStringCchCopyW(a4, a3, (int)a2);
  v8 = 0;
  v9 = WmipFindGEByGuid(a1, 0);
  if ( v9 )
  {
    v10 = v15[0] - 1;
    v11 = &a4[v15[0] - 1];
    for ( i = 90; ; *v11 = i )
    {
      v13 = (_DWORD *)WmipFindISinGEbyName(v9, a4, v15);
      if ( !v13 )
        break;
      WmipUnreferenceEntry((int *)&WmipISChunkInfo, v13);
      if ( i == 90 )
      {
        ++v10;
        i = 65;
        ++v11;
        if ( v10 == a3 - 1 )
        {
          v8 = -1073741670;
          break;
        }
        v11[1] = 0;
      }
      else
      {
        i = (unsigned __int16)(i + 1);
      }
    }
    WmipUnreferenceEntry((int *)&WmipGEChunkInfo, v9);
  }
  return v8;
}
