// PiDmListRemoveObjectWorker 
 
int PiDmListRemoveObjectWorker(int a1, int a2, ...)
{
  int *v2; // r5
  int v3; // r7
  int v5; // r9
  _DWORD *v6; // r4
  int result; // r0
  char v8; // r8
  __int64 v9; // kr00_8
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int varg_r2; // [sp+28h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+28h] [bp+10h]
  int varg_r3; // [sp+2Ch] [bp+14h]
  _BYTE *v19; // [sp+30h] [bp+18h]
  va_list va1; // [sp+34h] [bp+1Ch] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v19 = va_arg(va1, _BYTE *);
  v2 = &PiDmListDefs[5 * a1];
  v3 = varg_r3;
  v5 = v2[1] + varg_r2;
  v6 = (_DWORD *)(v2[3] + varg_r3);
  result = PiDmListIsObjectInList(a1, a2, varg_r3);
  v8 = result;
  if ( result )
  {
    v9 = *(_QWORD *)v6;
    if ( *(_DWORD **)(*v6 + 4) != v6 || *(_DWORD **)HIDWORD(v9) != v6 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v9) = v9;
    *(_DWORD *)(v9 + 4) = HIDWORD(v9);
    --*(_DWORD *)(v5 + 8);
    *v6 = 0;
    v6[1] = 0;
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(__int16 *)(v10 + 0x134) - 1;
    *(_WORD *)(v10 + 308) = v11;
    ExAcquireResourceExclusiveLite(a2, 1, v10, v11);
    v12 = varg_r2;
    if ( !--*(_DWORD *)(varg_r2 + 8) )
    {
      RtlDeleteElementGenericTableAvl(a2 + 56, (int)varg_r2a, v12, 0);
      PiDmObjectRelease(varg_r2);
    }
    v13 = ExReleaseResourceLite(a2);
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = *(_WORD *)(v14 + 0x134) + 1;
    *(_WORD *)(v14 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      KiCheckForKernelApcDelivery(v13);
    result = PiDmListUpdateAggregationCountWorker(varg_r2, v3, -1);
  }
  if ( v19 )
    *v19 = v8;
  return result;
}
