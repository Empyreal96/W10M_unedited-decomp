// CmpDoReOpenTransKey 
 
int __fastcall CmpDoReOpenTransKey(int a1, int *a2, int a3, int *a4)
{
  int v8; // r4
  int v9; // r4
  int v10; // r4
  int v11; // r5
  unsigned int i; // r2
  int v13; // r0
  int v14; // r0
  int v16[2]; // [sp+10h] [bp-A8h] BYREF
  int v17; // [sp+18h] [bp-A0h] BYREF
  int v18; // [sp+1Ch] [bp-9Ch]
  __int16 v19; // [sp+20h] [bp-98h] BYREF
  _BYTE v20[6]; // [sp+22h] [bp-96h]
  int v21; // [sp+28h] [bp-90h] BYREF
  int v22; // [sp+30h] [bp-88h] BYREF
  int v23; // [sp+34h] [bp-84h]
  __int16 *v24; // [sp+38h] [bp-80h]
  int v25; // [sp+3Ch] [bp-7Ch]
  int v26; // [sp+40h] [bp-78h]
  int v27; // [sp+44h] [bp-74h]
  int v28; // [sp+48h] [bp-70h] BYREF
  char v29[76]; // [sp+4Ch] [bp-6Ch] BYREF

  v28 = 0;
  memset(v29, 0, sizeof(v29));
  v8 = *a2;
  v19 = 0;
  v17 = v8;
  v9 = a2[1];
  *(_DWORD *)v20 = 0;
  *(_WORD *)&v20[4] = 0;
  v21 = 0;
  v18 = v9;
  v10 = 0;
  v16[0] = 0;
  if ( (_WORD)v17 )
  {
    while ( 1 )
    {
      v22 = 24;
      v23 = 0;
      v24 = (__int16 *)&v17;
      v25 = 576;
      v26 = 0;
      v27 = 0;
      v11 = ObOpenObjectByName((int)&v22, (int)CmKeyObjectType, 0, 0, a3, (int)&v28, v16);
      if ( v11 >= 0 )
        break;
      for ( i = (unsigned __int16)v17; i && *(_WORD *)(v18 + 2 * (i >> 1) - 2) != 92; LOWORD(v17) = i )
        i = (unsigned __int16)(i - 2);
      v19 = *(_WORD *)a2 - i;
      *(_DWORD *)&v20[2] = v18 + 2 * (i >> 1);
      LOWORD(v17) = i - 2;
      if ( (_WORD)i == 2 )
        return v11;
    }
    v10 = v16[0];
  }
  v11 = ObReferenceObjectByHandle(v10, 0, (int)CmKeyObjectType, 0, (int)v16, 0);
  if ( v11 >= 0 )
  {
    v13 = v16[0];
    *(_DWORD *)(v16[0] + 32) = a1 + 40;
    ObfDereferenceObject(v13);
    if ( v19 )
    {
      v22 = 24;
      v23 = v10;
      v25 = 576;
      v24 = &v19;
      v26 = 0;
      v27 = 0;
      v11 = ObOpenObjectByName((int)&v22, (int)CmKeyObjectType, 0, 0, a3, (int)&v28, &v21);
      if ( v11 >= 0 )
      {
        v11 = ObReferenceObjectByHandle(v10, 0, (int)CmKeyObjectType, 0, (int)v16, 0);
        if ( v11 >= 0 )
        {
          v14 = v16[0];
          *(_DWORD *)(v16[0] + 32) = a1 + 40;
          ObfDereferenceObject(v14);
        }
      }
      ZwClose();
      v10 = v21;
    }
    *a4 = v10;
  }
  else
  {
    ZwClose();
  }
  return v11;
}
