// MiCheckPoolForContiguousPages 
 
int __fastcall MiCheckPoolForContiguousPages(int *a1, unsigned int a2, unsigned int a3, _DWORD *a4, int a5, int a6)
{
  unsigned int v6; // r7
  unsigned int v7; // r6
  int v9; // r4
  unsigned int v10; // r9
  unsigned int v12; // r0
  unsigned int v13; // r6
  unsigned int v14; // [sp+10h] [bp-38h] BYREF
  _DWORD *v15; // [sp+14h] [bp-34h]
  unsigned int v16; // [sp+18h] [bp-30h]
  unsigned int v17[10]; // [sp+20h] [bp-28h] BYREF

  v6 = a1[1];
  v15 = a4;
  v7 = a3;
  v16 = *a1;
  v17[0] = 1024;
  v17[1] = v6;
  v9 = -1;
  if ( a3 >> 10 >= v16 >> 10 )
    return v9;
  while ( 1 )
  {
    v10 = RtlFindNextForwardRunClearCapped(v17, v7, 0xFFFFFFFF, &v14);
    if ( !v10 )
      return sub_5546C4();
    v12 = v14;
    if ( v10 >= a2 )
      break;
LABEL_9:
    v7 = v12 + v10;
  }
  v13 = MiPhysicalPoolCheck(v14, a5, v10, a2, v15[1], v15[2], v15[3], a6);
  if ( v13 == -1 )
  {
    v12 = v14;
    goto LABEL_9;
  }
  RtlSetBits(v17, v13, a2);
  return v13 + a5;
}
