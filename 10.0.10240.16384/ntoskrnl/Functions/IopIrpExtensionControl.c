// IopIrpExtensionControl 
 
void __fastcall __spoils<R1,R2,R3,R12> IopIrpExtensionControl(__int64 a1, int a2, int a3)
{
  BOOL v4; // r1
  int v5; // r1
  unsigned int v6; // r2
  __int64 v7; // [sp+0h] [bp-18h] BYREF
  int v8; // [sp+8h] [bp-10h]
  int v9; // [sp+Ch] [bp-Ch]

  v7 = a1;
  v8 = a2;
  v9 = a3;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&IopFunctionPointerLock, (unsigned int)&v7);
  if ( HIDWORD(a1) == 1 )
  {
    v4 = IopIrpExtensionStatus == 0;
    IopIrpExtensionStatus |= a1;
    if ( (a1 & 1) != 0 )
      ++dword_64A118;
    if ( (a1 & 2) != 0 )
      ++dword_64A11C;
    if ( v4 )
    {
      v5 = 1;
LABEL_17:
      IopUpdateFunctionPointers(4, v5, 1);
      goto LABEL_18;
    }
  }
  else
  {
    if ( (a1 & 1) == 0 || (--dword_64A118, dword_64A118) )
    {
      v6 = IopIrpExtensionStatus;
    }
    else
    {
      v6 = IopIrpExtensionStatus & 0xFFFFFFFE;
      IopIrpExtensionStatus &= 0xFFFFFFFE;
    }
    if ( (a1 & 2) != 0 && !--dword_64A11C )
    {
      v6 &= 0xFFFFFFFD;
      IopIrpExtensionStatus = v6;
    }
    if ( !v6 )
    {
      v5 = 0;
      goto LABEL_17;
    }
  }
LABEL_18:
  KeReleaseInStackQueuedSpinLock((int)&v7);
}
