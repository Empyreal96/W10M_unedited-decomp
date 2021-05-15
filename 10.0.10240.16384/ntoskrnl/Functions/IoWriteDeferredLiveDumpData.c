// IoWriteDeferredLiveDumpData 
 
int __fastcall IoWriteDeferredLiveDumpData(_DWORD *a1)
{
  int v2; // r8
  unsigned int v3; // r1
  unsigned int v4; // r7
  int v5; // r5
  int v6; // r2
  __int64 v7; // r0
  int v8; // r1
  _DWORD v10[2]; // [sp+8h] [bp-68h] BYREF
  int v11[2]; // [sp+10h] [bp-60h] BYREF
  _DWORD v12[22]; // [sp+18h] [bp-58h] BYREF

  v2 = KeQueryInterruptTime();
  v4 = v3;
  IopLiveDumpTraceInterfaceStart();
  IopLiveDumpTrace();
  v5 = IopLiveDumpWriteDumpFile(a1);
  IopLiveDumpTraceDumpFileWriteEnd((int)a1, 1, v5);
  if ( v5 >= 0 && (a1[12] & 2) != 0 )
    v5 = 261;
  IopLiveDumpTraceInterfaceEnd();
  if ( (unsigned int)dword_617540 > 5 && TlgKeywordOn((int)&dword_617540, 0x400000000000i64) )
  {
    v6 = a1[57];
    v11[0] = *(_DWORD *)(v6 + 4000);
    v11[1] = *(_DWORD *)(v6 + 4004);
    LODWORD(v7) = KeQueryInterruptTime();
    v10[0] = _rt_udiv64(10000i64, v7 - __PAIR64__(v4, v2));
    v10[1] = v8;
    v12[8] = v11;
    v12[9] = 0;
    v12[10] = 8;
    v12[11] = 0;
    v12[12] = v10;
    v12[13] = 0;
    v12[14] = 8;
    v12[15] = 0;
    TlgWrite(&dword_617540, (unsigned __int8 *)&word_4137C2 + 1, (int)(a1 + 87), (int)(a1 + 83), 4, v12);
  }
  EtwActivityIdControl(2, a1 + 83);
  IopLiveDumpReleaseResources(a1);
  ExFreePoolWithTag((unsigned int)a1);
  return v5;
}
