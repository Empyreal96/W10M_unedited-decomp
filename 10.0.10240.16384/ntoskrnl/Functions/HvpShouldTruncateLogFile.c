// HvpShouldTruncateLogFile 
 
BOOL __fastcall HvpShouldTruncateLogFile(int a1, int a2)
{
  int v3; // r4

  v3 = HvpLogTypeToLogArrayIndex(a2);
  return *(_QWORD *)(a1 + 8 * v3 + 1952) > (unsigned __int64)(unsigned int)HvGetEffectiveLogSizeCapForHive(a1);
}
