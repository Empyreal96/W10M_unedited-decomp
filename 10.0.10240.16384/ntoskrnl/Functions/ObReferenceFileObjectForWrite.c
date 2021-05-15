// ObReferenceFileObjectForWrite 
 
int __fastcall ObReferenceFileObjectForWrite(int a1, char a2, _DWORD *a3, int *a4)
{
  int v4; // r7
  unsigned int v6; // r8
  int v7; // r4
  int v9; // r3
  int v10; // r0
  int v11; // r10
  __int16 v12; // r3
  int v13; // r3
  int v14; // r4
  int v15; // r3
  int v16; // r4
  char v17; // r3
  int v18; // [sp+8h] [bp-38h]
  int v19; // [sp+Ch] [bp-34h]
  char v21; // [sp+18h] [bp-28h]
  int v22; // [sp+1Ch] [bp-24h]

  v4 = a2;
  v6 = a1;
  v7 = __mrc(15, 0, 13, 0, 3);
  if ( a1 >= 0 )
  {
    v9 = *(_DWORD *)((v7 & 0xFFFFFFC0) + 0x74);
    v18 = *(_DWORD *)(v9 + 336);
    if ( (*(_DWORD *)(v9 + 192) & 0x4000000) != 0 )
      goto LABEL_8;
    return -1073741816;
  }
  if ( a2 || a1 == -1 || a1 == -2 )
    return -1073741816;
  v6 = a1 ^ 0x80000000;
  v18 = ObpKernelHandleTable;
LABEL_8:
  --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
  v10 = ObpReferenceObjectByHandle();
  v11 = v10;
  v12 = *(_WORD *)((v7 & 0xFFFFFFC0) + 0x134);
  *(_WORD *)((v7 & 0xFFFFFFC0) + 0x134) = v12 + 1;
  if ( v12 == -1
    && *(_DWORD *)((v7 & 0xFFFFFFC0) + 0x64) != (v7 & 0xFFFFFFC0) + 100
    && !*(_WORD *)((v7 & 0xFFFFFFC0) + 0x136) )
  {
    KiCheckForKernelApcDelivery(v10);
  }
  if ( !v11 )
  {
    v14 = -1073741816;
LABEL_20:
    *a3 = 0;
    return v14;
  }
  if ( ObpTraceFlags )
    return sub_7FA3BC();
  if ( (void *)ObTypeIndexTable[BYTE1(v19) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v19 + 12)] != IoFileObjectType )
  {
    v14 = -1073741788;
    goto LABEL_38;
  }
  if ( (*(_DWORD *)(v19 + 68) & 0x80) != 0 )
    v13 = 0;
  else
    v13 = 4;
  v16 = v13 | 2;
  a4[1] = v22 & 0x1FFFFFF;
  v17 = v21 & 6;
  if ( (v22 & 0x4000000) != 0 )
    v17 |= 8u;
  if ( (v22 & 0x2000000) != 0 )
    v17 |= 1u;
  *a4 = v17 & 7;
  if ( (v22 & 0x1FFFFFF & v16) == 0 )
  {
    v14 = -1073741790;
LABEL_38:
    PspDereferenceSiloObject(v19 + 24);
    goto LABEL_20;
  }
  if ( v4 )
  {
    if ( (*(_BYTE *)(v19 + 14) & 0x40) != 0 )
    {
      v15 = v19 - ObpInfoMaskToOffset[*(_BYTE *)(v19 + 14) & 0x7F];
      if ( v15 )
      {
        if ( *(_DWORD *)(v15 + 8) == 1 )
        {
          v14 = -1073700858;
          goto LABEL_38;
        }
      }
    }
  }
  if ( (*a4 & 4) != 0 && v4 && !ObpAuditObjectAccess(v18, v6, v11, v19, v16) )
  {
    v14 = -1073741816;
    goto LABEL_38;
  }
  *a3 = v19 + 24;
  return 0;
}
