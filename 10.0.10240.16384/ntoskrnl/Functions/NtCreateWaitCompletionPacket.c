// NtCreateWaitCompletionPacket 
 
int __fastcall NtCreateWaitCompletionPacket(int *a1, int a2, int a3, int a4)
{
  int *v5; // r4
  int result; // r0
  int v7; // r0
  char v8; // [sp+18h] [bp-30h]
  int v9; // [sp+20h] [bp-28h] BYREF
  int v10; // [sp+24h] [bp-24h]
  int v11; // [sp+28h] [bp-20h]
  int *varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v5 = a1;
  varg_r0 = a1;
  v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (int *)MmUserProbeAddress;
    v11 = *a1;
    *a1 = v11;
  }
  result = ObCreateObjectEx(v8, IopWaitCompletionPacketObjectType, a3, v8);
  if ( result >= 0 )
  {
    v7 = v10;
    *(_DWORD *)(v10 + 48) = 0;
    __dmb(0xBu);
    *(_BYTE *)(v7 + 52) = 0;
    result = ObInsertObjectEx(v7, 0, a2, 0, 0, 0, &v9);
    v10 = result;
    if ( result >= 0 )
      *v5 = v9;
  }
  return result;
}
