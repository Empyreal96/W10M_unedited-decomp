// IopBusNumberScoreRequirement 
 
unsigned int __fastcall IopBusNumberScoreRequirement(int a1)
{
  __int64 v1; // kr00_8
  unsigned int v2; // r0

  v1 = *(_QWORD *)(a1 + 12);
  v2 = *(_DWORD *)(a1 + 8);
  if ( !v2 )
    __brkdiv0();
  return (HIDWORD(v1) - (int)v1) / v2;
}
