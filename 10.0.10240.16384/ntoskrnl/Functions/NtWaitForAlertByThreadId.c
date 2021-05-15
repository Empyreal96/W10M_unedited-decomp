// NtWaitForAlertByThreadId 
 
int __fastcall NtWaitForAlertByThreadId(int a1, __int64 *a2)
{
  unsigned int v2; // r3
  unsigned __int8 v3; // r4
  __int64 v5; // [sp+8h] [bp-20h] BYREF
  __int64 v6; // [sp+10h] [bp-18h]
  int vars8; // [sp+30h] [bp+8h]
  __int64 *varsC; // [sp+34h] [bp+Ch]

  varsC = a2;
  vars8 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_BYTE *)(v2 + 346);
  if ( a2 && *(_BYTE *)(v2 + 346) )
  {
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      a2 = (__int64 *)MmUserProbeAddress;
    v6 = *a2;
    v5 = v6;
    a2 = &v5;
    varsC = &v5;
  }
  return KeWaitForAlertByThreadId(v3, (int)a2, a1);
}
