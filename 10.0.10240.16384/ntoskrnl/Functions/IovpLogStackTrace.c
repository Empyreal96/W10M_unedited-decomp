// IovpLogStackTrace 
 
int __fastcall IovpLogStackTrace(int a1)
{
  int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r1
  unsigned int v4; // r3
  unsigned int v5; // r0
  int v6; // r1
  int v7; // r2
  int v8; // r3

  if ( !IovIrpTraces )
    return 0;
  __dmb(0xBu);
  do
  {
    v2 = __ldrex(&IovIrpTracesIndex);
    v3 = v2 + 1;
  }
  while ( __strex(v3, &IovIrpTracesIndex) );
  __dmb(0xBu);
  v1 = IovIrpTraces + (((IovIrpTracesLength - 1) & v3) << 6);
  *(_DWORD *)v1 = a1;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v1 + 4) = v4;
  *(_DWORD *)(v1 + 8) = *(_DWORD *)(v4 + 308);
  v5 = KeGetCurrentIrql(a1);
  *(_BYTE *)(v1 + 12) = v5;
  if ( v5 > 1 || RtlEnoughStackSpaceForStackCapture(v5, v6, v7, v8) )
  {
    IovpLogStackCallout(v1);
  }
  else if ( KeExpandKernelStackAndCallout((int (__fastcall *)(int))IovpLogStackCallout, v1, 720) < 0 )
  {
    *(_DWORD *)(v1 + 16) = 0;
  }
  return v1;
}
