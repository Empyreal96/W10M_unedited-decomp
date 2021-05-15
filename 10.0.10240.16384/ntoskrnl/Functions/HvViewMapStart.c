// HvViewMapStart 
 
int __fastcall HvViewMapStart(int a1, int a2, int a3, unsigned int a4, char a5)
{
  int v7; // r5
  int v8; // r4
  int v9; // r3
  _BYTE *v11; // r0
  int v12; // r6
  _BYTE *v13; // r0
  unsigned int v14; // r7
  int v15; // r3
  unsigned int *v16; // r3
  unsigned int i; // r8
  unsigned int v18; // r7
  int *v19; // r8
  int v20; // r0
  int v21; // t1
  int v22; // [sp+4h] [bp-2Ch]
  int v23; // [sp+8h] [bp-28h] BYREF
  unsigned int *v24; // [sp+Ch] [bp-24h] BYREF

  v24 = (unsigned int *)a1;
  v22 = 0;
  v7 = ObReferenceObjectByHandle(a3, 3, *(_DWORD *)CmIoFileObjectType, 0, &v23);
  v8 = v23;
  if ( v7 >= 0 )
  {
    v9 = *(_DWORD *)(v23 + 20);
    if ( v9 && *(_DWORD *)(v9 + 4) || CmpTouchFile() >= 0 )
    {
      if ( !CcSetPrivateWriteFile(v8) )
        return sub_7F37C4();
      v11 = (_BYTE *)(*(int (__fastcall **)(int, _DWORD, int))(a2 + 12))(512, 0, 926240067);
      v12 = (int)v11;
      if ( v11 )
      {
        v13 = memset(v11, 0, 512);
        v14 = 0;
        if ( a4 )
        {
          while ( 1 )
          {
            v15 = a4 - v14;
            if ( a4 - v14 >= 0x40000 )
              v15 = 0x40000;
            v13 = (_BYTE *)HvpViewMapViewOfPrimaryFile(a2, v12, v8, v14, v15, v22);
            v7 = (int)v13;
            if ( (int)v13 < 0 )
              break;
            v14 += 0x40000;
            if ( v14 >= a4 )
              goto LABEL_12;
          }
        }
        else
        {
LABEL_12:
          if ( (a5 & 1) == 0 )
            v13 = (_BYTE *)HvpViewMapPrefetchFile(v8, a4);
          v16 = v24;
          v24[2] = v8;
          v16[3] = v12;
          v8 = 0;
          v12 = 0;
          v7 = 0;
          *v16 = a4;
        }
        if ( v12 )
        {
          for ( i = 0; i < v14; i += 0x40000 )
            v13 = (_BYTE *)HvpViewUnmapViewOfPrimaryFile((int)v13, v12, i, &v24);
          v18 = 0;
          v19 = (int *)v12;
          do
          {
            v21 = *v19++;
            v20 = v21;
            if ( !v21 )
              break;
            (*(void (__fastcall **)(int, int))(a2 + 16))(v20, 1536);
            ++v18;
          }
          while ( v18 < 0x80 );
          (*(void (__fastcall **)(int, int))(a2 + 16))(v12, 512);
        }
        if ( v7 >= 0 )
          goto LABEL_17;
      }
      else
      {
        v7 = -1073741670;
      }
      CcClearPrivateWriteFile(v8);
    }
    else
    {
      v7 = -1073741491;
    }
  }
LABEL_17:
  if ( v8 )
    ObfDereferenceObject(v8);
  return v7;
}
