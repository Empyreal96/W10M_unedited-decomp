// EtwpApplyEventIdPayloadFilterOnUserEvent 
 
int __fastcall EtwpApplyEventIdPayloadFilterOnUserEvent(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return EtwpApplyEventIdPayloadFilter(
           a1,
           a2,
           *(unsigned __int16 *)(a4 + 40),
           a4 + 40,
           *(_WORD *)(a4 + 40),
           a5,
           a6,
           1u,
           0);
}
