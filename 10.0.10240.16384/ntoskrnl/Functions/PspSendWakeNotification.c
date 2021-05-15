// PspSendWakeNotification 
 
int __fastcall PspSendWakeNotification(unsigned int a1, char a2, _DWORD *a3, int a4, unsigned __int64 a5, char a6)
{
  int v8; // r1
  signed int v10; // r0

  v8 = 1 << a2;
  if ( ((a3[1] & (1 << a2)) == 0 || a5) && ((*a3 & v8) == 0 || (a6 & 2) == 0 || a5 != 1 && (a5 <= 1 || (a6 & 1) == 0)) )
    return 0;
  v10 = ObfReferenceObject(a1);
  if ( (dword_682610 & 0x400) != 0 )
    return sub_7C23BC(v10);
  if ( !PspRequestDeferredJobNotification(a1, 0x2000) )
    ObfDereferenceObject(a1);
  return 1;
}
