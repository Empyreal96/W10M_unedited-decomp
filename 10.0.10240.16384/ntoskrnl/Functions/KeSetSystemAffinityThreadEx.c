// KeSetSystemAffinityThreadEx 
 
int __fastcall KeSetSystemAffinityThreadEx(int a1)
{
  int v2; // [sp+0h] [bp-28h] BYREF
  int v3; // [sp+4h] [bp-24h]
  int v4; // [sp+8h] [bp-20h]
  int v5; // [sp+10h] [bp-18h] BYREF

  v3 = 0;
  v4 = 0;
  v2 = a1;
  if ( KeForceGroupAwareness )
    return sub_555C34();
  LOWORD(v3) = 0;
  KeSetSystemGroupAffinityThread((int)&v2, &v5);
  return v5;
}
