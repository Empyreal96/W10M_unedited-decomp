// sub_5168F8 
 
// local variable allocation has failed, the output may be wrong!
void sub_5168F8(int a1, int a2, int a3, int a4, ...)
{
  unsigned int *v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r8
  int *v8; // r4
  int v9; // r3
  int *v10; // r1 OVERLAPPED
  int **v11; // r2 OVERLAPPED
  int *v12; // r1
  int *v13; // r2
  __int64 v14; // r0
  int *v15; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  va_list v17; // [sp+4h] [bp+4h]
  va_list va1; // [sp+8h] [bp+8h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v15 = va_arg(va1, int *);
  v17 = va_arg(va1, va_list);
  va_copy(v17, va);
  va_copy((va_list)v15, va);
  KeAcquireInStackQueuedSpinLock(v4 + 1920, (unsigned int)va1);
  while ( 1 )
  {
    v8 = (int *)v4[1924];
    if ( v8 == (int *)((char *)v4 + v5) )
      break;
    v9 = v8[4];
    if ( (unsigned int)(v6 - v9) <= 2 && ((v9 & v7) != 0 || (unsigned int)(v6 - v9) < 2) )
      break;
    *(_QWORD *)&v10 = *(_QWORD *)v8;
    if ( *(int **)(*v8 + 4) != v8 || *v11 != v8 )
      __fastfail(3u);
    *v11 = v10;
    v10[1] = (int)v11;
    RtlAvlRemoveNode((int)(v4 + 1923), (int)(v8 - 3));
    v12 = v15;
    --v4[1927];
    *v8 = (int)v12;
    v8[1] = (int)va;
    if ( (va_list)v12[1] != va )
      __fastfail(3u);
    v12[1] = (int)v8;
    v15 = v8;
  }
  KeReleaseInStackQueuedSpinLock((int)va1);
  while ( 1 )
  {
    v13 = v15;
    if ( v15 == (int *)va )
      break;
    v14 = *(_QWORD *)v15;
    if ( *(int **)(*v15 + 4) != v15 || *(int **)HIDWORD(v14) != v15 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v14) = v14;
    *(_DWORD *)(v14 + 4) = HIDWORD(v14);
    ExFreePoolWithTag(v13 - 3, 0);
  }
  JUMPOUT(0x435FA6);
}
