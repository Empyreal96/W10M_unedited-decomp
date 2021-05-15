// PopFxInitializeSocSubsystemStaticInfo 
 
int __fastcall PopFxInitializeSocSubsystemStaticInfo(int a1)
{
  int result; // r0
  int v3[4]; // [sp+34h] [bp-B0h] BYREF
  __int16 v4; // [sp+44h] [bp-A0h]
  char v5[126]; // [sp+46h] [bp-9Eh] BYREF

  v4 = 0;
  memset(v5, 0, sizeof(v5));
  if ( PopFxProcessorPlugin
    && (v3[1] = 0, v3[2] = 0, v3[0] = a1, PopFxProcessorPlugin)
    && (*(int (__fastcall **)(int, int *))(PopFxProcessorPlugin + 64))(36, v3) )
  {
    result = sub_812330();
  }
  else
  {
    result = -1073741822;
  }
  return result;
}
