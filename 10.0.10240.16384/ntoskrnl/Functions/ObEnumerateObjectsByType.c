// ObEnumerateObjectsByType 
 
int ObEnumerateObjectsByType()
{
  int v0; // r4
  _DWORD *v1; // r0
  _DWORD *v2; // r5
  int v3; // r6
  _DWORD *v4; // r7
  int v5; // r3
  int v6; // t1
  _DWORD *v7; // r0
  char v8; // r3
  int v9; // r2
  int v10; // r3
  int v12; // [sp+4h] [bp-24h]
  int v13[8]; // [sp+8h] [bp-20h] BYREF

  v0 = 0;
  v1 = (_DWORD *)ObpCreateTypeArray();
  v2 = v1;
  if ( v1 )
  {
    v3 = 0;
    if ( *v1 )
    {
      v4 = v1;
      while ( 1 )
      {
        v6 = v4[1];
        ++v4;
        v5 = v6;
        if ( v6 )
        {
          v7 = (_DWORD *)(v5 + 16);
          v8 = *(_BYTE *)(v5 + 30);
          v9 = (int)((v8 & 2) != 0 ? (_DWORD *)((char *)v7 - ObpInfoMaskToOffset[v8 & 3]) : 0);
          if ( v9 )
          {
            v13[0] = *(_DWORD *)(v9 + 4);
            v10 = *(_DWORD *)(v9 + 8);
          }
          else
          {
            v10 = 0;
            v13[0] = 0;
          }
          v13[1] = v10;
          if ( !((int (__fastcall *)(_DWORD *, int *, _DWORD, _DWORD, _DWORD, int))IovpBuildDriverObjectList)(
                  v7 + 6,
                  v13,
                  v7[1],
                  *v7,
                  0,
                  v12) )
            break;
        }
        if ( (unsigned int)++v3 >= *v2 )
          goto LABEL_15;
      }
      v0 = -2147483622;
    }
LABEL_15:
    ObpDestroyTypeArray(v2);
  }
  return v0;
}
