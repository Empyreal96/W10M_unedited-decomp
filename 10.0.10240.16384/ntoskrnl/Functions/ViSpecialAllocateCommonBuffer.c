// ViSpecialAllocateCommonBuffer 
 
_BYTE *__fastcall ViSpecialAllocateCommonBuffer(int (__fastcall *a1)(_DWORD, unsigned int, __int64 *, _DWORD), _DWORD *a2, int a3, unsigned int a4, _QWORD *a5, unsigned __int8 a6)
{
  __int64 v7; // kr08_8
  _BYTE *v10; // r4
  int v11; // r5
  __int16 v12; // r4
  int v13; // r9
  unsigned int v14; // r10
  _BYTE *v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r1
  int v19; // [sp+0h] [bp-38h] BYREF
  int v20; // [sp+4h] [bp-34h] BYREF
  int v21; // [sp+8h] [bp-30h]
  __int64 v22[5]; // [sp+10h] [bp-28h] BYREF

  v7 = *(_QWORD *)(a2 + 25);
  v21 = a3;
  if ( (unsigned int)(v7 - HIDWORD(v7)) >= 0x20 || a4 > 0xFFFFDFFF )
    return 0;
  v11 = ExAllocatePoolWithTag(512, 48, 1449943368);
  if ( !v11 )
  {
    VfUtilDbgPrint((int)"Couldn't track common buffer allocation\n");
    return 0;
  }
  ViCommonBufferCalculatePadding(a4, &v19, &v20);
  v13 = v19;
  v12 = v20;
  v14 = v19 + v20 + a4;
  v15 = (_BYTE *)a1(a2[2], v14, v22, a6);
  if ( !v15 )
  {
    ExFreePoolWithTag(v11);
    return 0;
  }
  *(_WORD *)(v11 + 2) = v12;
  v10 = &v15[v13];
  *(_DWORD *)(v11 + 12) = v15;
  *(_DWORD *)(v11 + 16) = &v15[v13];
  *(_WORD *)v11 = v13;
  *(_DWORD *)(v11 + 4) = v14;
  *(_DWORD *)(v11 + 8) = a4;
  *(_QWORD *)(v11 + 24) = v22[0];
  *(_DWORD *)(v11 + 32) = v21;
  ViInitializePadding(v15, v14, (unsigned int)&v15[v13], a4);
  *a5 = v22[0] + (unsigned int)v13;
  ExInterlockedInsertHeadList(a2 + 11, (int *)(v11 + 36), a2 + 13);
  __dmb(0xBu);
  v16 = a2 + 25;
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + 1, v16) );
  __dmb(0xBu);
  return v10;
}
