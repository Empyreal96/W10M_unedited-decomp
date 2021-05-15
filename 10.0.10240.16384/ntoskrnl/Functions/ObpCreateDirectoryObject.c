// ObpCreateDirectoryObject 
 
_BYTE *__fastcall ObpCreateDirectoryObject(_BYTE *a1, _BYTE *a2, _BYTE *a3, _BYTE *a4, char a5)
{
  _DWORD *v5; // r8
  _BYTE *v6; // r5
  _DWORD *v7; // r2
  _BYTE *v8; // r4
  _DWORD *v9; // r4
  int v10; // r2
  char v12; // [sp+18h] [bp-38h]
  int v15; // [sp+24h] [bp-2Ch] BYREF
  _BYTE *_2C[15]; // [sp+2Ch] [bp-24h] BYREF

  _2C[14] = a4;
  _2C[13] = a3;
  _2C[12] = a2;
  v5 = a1;
  _2C[11] = a1;
  v15 = 0;
  v6 = 0;
  _2C[0] = 0;
  v12 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v12 )
  {
    v7 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
  }
  if ( !a4
    || (v8 = (_BYTE *)ObReferenceObjectByHandle(a4, 3, ObpDirectoryObjectType, v12, _2C), v6 = _2C[0], (int)v8 >= 0) )
  {
    v8 = (_BYTE *)ObCreateObject(v12, ObpDirectoryObjectType, a3, v12, 0, 172, 0, 0, _2C);
    if ( (int)v8 >= 0 )
    {
      v9 = _2C[0];
      memset(_2C[0], 0, 172);
      v9[37] = 0;
      v9[40] = -1;
      v10 = 0;
      if ( v6 )
      {
        v10 = 4;
        v9[39] = v6;
      }
      if ( (a5 & 1) != 0 )
        v10 |= 8u;
      v9[42] |= v10;
      v8 = (_BYTE *)ObInsertObject(v9, 0, a2, 0, 0, &v15);
      _2C[0] = v8;
      *v5 = v15;
    }
    else if ( v6 )
    {
      ObfDereferenceObject((int)v6);
    }
  }
  return v8;
}
