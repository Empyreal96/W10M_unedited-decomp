// FsFilterAllocateCompletionStack 
 
int __fastcall FsFilterAllocateCompletionStack(int a1, int a2, _DWORD *a3)
{
  int v4; // r3
  unsigned int *v6; // r5
  char *v7; // r6
  int v8; // r0
  int result; // r0
  int v10; // r3
  int *v11; // r3
  int v12; // r3

  v4 = *(unsigned __int16 *)(a1 + 44);
  *a3 = 16 * v4;
  v6 = 0;
  v7 = 0;
  v8 = ExAllocatePoolWithTag(512, 16 * v4);
  if ( v8 )
    goto LABEL_14;
  if ( a2 )
    return -1073741670;
  v10 = *(unsigned __int8 *)(a1 + 4);
  switch ( v10 )
  {
    case 250:
      goto LABEL_11;
    case 251:
      goto LABEL_10;
    case 252:
LABEL_11:
      v11 = &ReleaseOpsReservePool;
      v7 = &ReleaseOpsEvent;
      goto LABEL_12;
    case 253:
LABEL_10:
      v11 = &AcquireOpsReservePool;
      v7 = &AcquireOpsEvent;
LABEL_12:
      v6 = (unsigned int *)*v11;
      break;
    case 254:
      goto LABEL_11;
    case 255:
      goto LABEL_10;
  }
  KeWaitForSingleObject((unsigned int)v7, 0, 0, 0, 0);
  *v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = (int)(v6 + 1);
  *(_DWORD *)(a1 + 36) |= 2u;
LABEL_14:
  v12 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 48) = v8;
  result = 0;
  *(_DWORD *)(a1 + 36) = v12 | 1;
  return result;
}
