// NtGetCachedSigningLevel 
 
int __fastcall NtGetCachedSigningLevel(int a1, _DWORD *a2, _BYTE *a3, unsigned int a4, unsigned int *a5, unsigned int a6)
{
  int v10; // r6
  int v11; // r9
  int v12; // r4
  int v13; // r0
  char v14; // r2
  unsigned int v15; // r5
  _DWORD *v16; // r5
  char v18[4]; // [sp+8h] [bp-88h] BYREF
  int v19; // [sp+Ch] [bp-84h] BYREF
  unsigned int v20; // [sp+10h] [bp-80h] BYREF
  int v21; // [sp+14h] [bp-7Ch] BYREF
  int v22; // [sp+18h] [bp-78h] BYREF
  _DWORD *v23; // [sp+1Ch] [bp-74h]
  _DWORD *v24; // [sp+20h] [bp-70h]
  int v25; // [sp+24h] [bp-6Ch]
  int v26; // [sp+28h] [bp-68h]
  char v27; // [sp+30h] [bp-60h] BYREF
  _BYTE v28[63]; // [sp+31h] [bp-5Fh] BYREF

  v24 = a2;
  v25 = a1;
  v23 = (_DWORD *)a6;
  v10 = 0;
  v27 = 0;
  memset(v28, 0, sizeof(v28));
  v20 = 64;
  v22 = 0;
  v19 = 0;
  v18[0] = 0;
  if ( a1 && a2 && a3 )
  {
    v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v12 = ObReferenceObjectByHandle(v25, 1, (int)IoFileObjectType, v11, (int)&v21, 0);
    v10 = v21;
    if ( v12 >= 0 )
    {
      v13 = a4 ? SeGetCachedSigningLevel(v21, &v19, v18, &v27, &v20, &v22) : SeGetCachedSigningLevel(
                                                                               v21,
                                                                               &v19,
                                                                               v18,
                                                                               0,
                                                                               0,
                                                                               0);
      v12 = v13;
      if ( v13 >= 0 )
      {
        if ( v11 == 1 )
        {
          ProbeForWrite((unsigned int)v24, 4, 4);
          ProbeForWrite((unsigned int)a3, 1, 1);
        }
        v14 = v19;
        *v24 = v19;
        *a3 = v18[0];
        if ( a5 )
        {
          if ( v11 == 1 )
          {
            ProbeForWrite((unsigned int)a5, 4, 4);
            v14 = v19;
          }
          if ( (v14 & 2) != 0 )
          {
            v15 = v20;
            if ( *a5 >= v20 && a4 )
            {
              if ( v11 == 1 )
              {
                ProbeForWrite(a4, v20, 1);
                v15 = v20;
              }
              memmove(a4, (int)&v27, v15);
            }
            else
            {
              v12 = -1073741789;
              v26 = -1073741789;
            }
            *a5 = v15;
            v16 = v23;
            if ( v23 )
            {
              if ( v11 == 1 )
                ProbeForWrite((unsigned int)v23, 4, 4);
              *v16 = v22;
            }
          }
          else
          {
            *a5 = 0;
          }
        }
      }
    }
  }
  else
  {
    v12 = -1073741811;
  }
  if ( v10 )
    ObfDereferenceObject(v10);
  return v12;
}
