#include "eif_eiffel.h"
#include "libworld_calc.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef INLINE_F518_672
static void inline_F518_672 (EIF_NATURAL_16 arg1)
{
	eif_scoop_set_is_impersonation_allowed (arg1, EIF_FALSE)
	;
}
#define INLINE_F518_672
#endif
#ifndef INLINE_F518_671
static EIF_NATURAL_16 inline_F518_671 (EIF_POINTER arg1)
{
	return RTS_PID(arg1)
	;
}
#define INLINE_F518_671
#endif
#ifndef INLINE_F581_1696
static EIF_NATURAL_64 inline_F581_1696 (EIF_POINTER arg1)
{
	#ifdef EIF_WINDOWS
				return (EIF_NATURAL_64) wcslen(arg1) * sizeof(wchar_t);
			#else
				return (EIF_NATURAL_64) strlen(arg1) * sizeof(char);
			#endif
	;
}
#define INLINE_F581_1696
#endif
#ifndef INLINE_F631_4752
static int inline_F631_4752 (EIF_POINTER arg1, EIF_POINTER arg2)
{
	EIF_BOOLEAN Result = EIF_FALSE;
#ifdef EIF_WINDOWS
		/* To check this, we use `CreateFileW' to open both file, and then using the information
		 * returned by `GetFileInformationByHandle' we can check whether or not they are indeed
		 * the same.
		 * Note: it is important to use the W version of CreateFileW because arguments
		 * are Unicode, not ASCII. */
	BY_HANDLE_FILE_INFORMATION l_path1_info, l_path2_info;
	HANDLE l_path2_file = CreateFileW ((LPCWSTR) arg2, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE l_path1_file = CreateFileW ((LPCWSTR) arg1, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if ((l_path2_file == INVALID_HANDLE_VALUE) || (l_path1_file == INVALID_HANDLE_VALUE)) {
			/* We do not need the handles anymore, simply close them. Since Microsoft
			 * API accepts INVALID_HANDLE_VALUE we don't check the validity of arguments. */
		CloseHandle(l_path2_file);
		CloseHandle(l_path1_file);
	} else {
		BOOL success = GetFileInformationByHandle (l_path2_file, &l_path2_info);
		success = success && GetFileInformationByHandle (l_path1_file, &l_path1_info);
			/* We do not need the handles anymore, simply close them. */
		CloseHandle(l_path2_file);
		CloseHandle(l_path1_file);
		if (success) {
				/* Check that `path2' and `path1' do not represent the same file. */
			if
				((l_path2_info.dwVolumeSerialNumber == l_path1_info.dwVolumeSerialNumber) &&
				(l_path2_info.nFileIndexLow == l_path1_info.nFileIndexLow) &&
				(l_path2_info.nFileIndexHigh == l_path1_info.nFileIndexHigh))
			{
				Result = EIF_TRUE;
			}
		}
	}
#else
	struct stat buf1, buf2;
	int status;
	#ifdef HAS_LSTAT
		status = lstat(arg1, &buf1);
		if (status == 0) {
				/* We found a file, now let's check if it is not a symbolic link. If it is, we use `stat'
			 	 * to ensure the validity of the link. */
			if ((buf1.st_mode & S_IFLNK) == S_IFLNK) {
				status = stat (arg1, &buf1);
			}
		}
		
		if (status == 0) {
			status = lstat(arg2, &buf2);
			if (status == 0) {
					/* We found a file, now let's check if it is not a symbolic link. If it is, we use `stat'
				 	 * to ensure the validity of the link. */
				if ((buf2.st_mode & S_IFLNK) == S_IFLNK) {
					status = stat (arg2, &buf2);
				}
			}
		}
	#else
		status = stat (arg1, &buf1);
		if (status == 0) {
			status = stat (arg2, &buf2);
		}
	#endif
	if (status == 0) {
			/* Both files are present, check they represent the same one. */
		if ((buf1.st_dev == buf2.st_dev) && (buf1.st_ino == buf2.st_ino)) {
			Result = EIF_TRUE;
		}
	}
#endif
return Result;
	;
}
#define INLINE_F631_4752
#endif
#ifndef INLINE_F697_6544
static EIF_INTEGER_32 inline_F697_6544 (EIF_POINTER arg1)
{
	#ifdef EIF_WINDOWS
	return (EIF_INTEGER_32) _tcslen ((wchar_t *) arg1);
#else
	return 0;
#endif
	;
}
#define INLINE_F697_6544
#endif
#ifndef INLINE_F697_6541
static EIF_INTEGER_32 inline_F697_6541 (EIF_INTEGER_32 arg1)
{
	#ifdef EIF_WINDOWS
	return HRESULT_CODE(arg1);
#else
	return 0;
#endif
	;
}
#define INLINE_F697_6541
#endif
#ifndef INLINE_F697_6546
static void inline_F697_6546 (EIF_POINTER arg1)
{
	#ifdef EIF_WINDOWS
	LocalFree((HLOCAL) arg1);
#endif
	;
}
#define INLINE_F697_6546
#endif
#ifndef INLINE_F697_6543
static EIF_POINTER inline_F697_6543 (EIF_INTEGER_32 arg1)
{
	#ifdef EIF_WINDOWS
	LPVOID result;
	FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		arg1,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &result,
		0,
		NULL 
		);
	return result;
#else
	return 0;
#endif
	;
}
#define INLINE_F697_6543
#endif
#ifndef INLINE_F697_6540
static EIF_INTEGER_32 inline_F697_6540 (EIF_POINTER arg1)
{
	#ifdef EIF_WINDOWS
			char *stopstring = NULL;
			long result = 0, high_bits = 0, low_bits = 0;
			char high_str [7];
			char *exception_code = (char *)(arg1);
			  
			if (NULL != exception_code)
			{
				strncpy (high_str, exception_code, 6);
				high_str [6] = '\0';

				high_bits = strtol (high_str, &stopstring, 16);
				low_bits = strtol (exception_code + 6, &stopstring, 16);
				result = (high_bits << 16) + low_bits;
			}
			return (EIF_INTEGER)result;
		#else
			return 0;
		#endif
	;
}
#define INLINE_F697_6540
#endif
#ifndef INLINE_F697_6542
static EIF_INTEGER_32 inline_F697_6542 (EIF_INTEGER_32 arg1)
{
	#ifdef EIF_WINDOWS
	return HRESULT_FACILITY(arg1);
#else
	return 0;
#endif
	;
}
#define INLINE_F697_6542
#endif
#ifndef INLINE_F697_6545
static EIF_INTEGER_32 inline_F697_6545 (void)
{
	#ifdef EIF_WINDOWS
	return sizeof(TCHAR);
#else
	return 0;
#endif
	;
}
#define INLINE_F697_6545
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {ISE_SCOOP_RUNTIME}.c_disable_impersonation */
RT_IL void __stdcall F518_672 (EIF_NATURAL_16 arg1)
{
	inline_F518_672 ((EIF_NATURAL_16) arg1);
}
/* {ISE_SCOOP_RUNTIME}.c_region_id */
RT_IL EIF_NATURAL_16 __stdcall F518_671 (EIF_POINTER arg1)
{
	EIF_NATURAL_16 Result;
	Result = inline_F518_671 ((EIF_POINTER) arg1);
	return Result;
}
/* {ISE_SCOOP_RUNTIME}.invalid_region_id */
RT_IL EIF_NATURAL_16 __stdcall F518_667 (void)
{
	EIF_NATURAL_16 Result;
	Result = (EIF_NATURAL_16) EIF_NULL_PROCESSOR;
	return Result;
}

/* {C_STRING}.c_strlen */
RT_IL EIF_INTEGER_32 __stdcall F580_1694 (EIF_POINTER arg1)
{
	EIF_INTEGER_32 Result;Result = (EIF_INTEGER_32) strlen((char*) arg1);
	
	return Result;
}

/* {NATIVE_STRING_HANDLER}.c_pointer_length_in_bytes */
RT_IL EIF_NATURAL_64 __stdcall F581_1696 (EIF_POINTER arg1)
{
	EIF_NATURAL_64 Result;
	Result = inline_F581_1696 ((EIF_POINTER) arg1);
	return Result;
}

/* {FILE}.get_fd */
RT_IL EIF_INTEGER_32 __stdcall F627_4575 (EIF_INTEGER_32 arg1, EIF_INTEGER_32 arg2)
{
	EIF_INTEGER_32 Result;Result = (EIF_INTEGER_32) _open_osfhandle((EIF_INTEGER) arg1, (EIF_INTEGER) arg2);
	
	return Result;
}

/* {PATH}.c_same_files */
RT_IL EIF_BOOLEAN __stdcall F631_4752 (EIF_POINTER arg1, EIF_POINTER arg2)
{
	EIF_BOOLEAN Result;
	Result = EIF_TEST(inline_F631_4752 ((EIF_POINTER) arg1, (EIF_POINTER) arg2));
	return Result;
}

/* {POINTER_REF}.c_memset */
RT_IL void __stdcall F672_5905 (EIF_POINTER arg1, EIF_INTEGER_32 arg2, EIF_INTEGER_32 arg3)
{memset((void *) arg1, (int) arg2, (size_t) arg3);
	
}
/* {POINTER_REF}.c_malloc */
RT_IL EIF_POINTER __stdcall F672_5907 (EIF_INTEGER_32 arg1)
{
	EIF_POINTER Result;Result = (EIF_POINTER) malloc((size_t) arg1);
	
	return Result;
}
/* {POINTER_REF}.c_offset_pointer */
RT_IL EIF_POINTER __stdcall F672_5902 (EIF_POINTER arg1, EIF_INTEGER_32 arg2)
{
	EIF_POINTER Result;
	Result = (EIF_POINTER) RTPOF((arg1), (arg2));
	return Result;
}
/* {POINTER_REF}.c_calloc */
RT_IL EIF_POINTER __stdcall F672_5908 (EIF_INTEGER_32 arg1, EIF_INTEGER_32 arg2)
{
	EIF_POINTER Result;Result = (EIF_POINTER) calloc((size_t) arg1, (size_t) arg2);
	
	return Result;
}
/* {POINTER_REF}.c_memcpy */
RT_IL void __stdcall F672_5903 (EIF_POINTER arg1, EIF_POINTER arg2, EIF_INTEGER_32 arg3)
{memcpy((void *) arg1, (const void *) arg2, (size_t) arg3);
	
}
/* {POINTER_REF}.c_memmove */
RT_IL void __stdcall F672_5904 (EIF_POINTER arg1, EIF_POINTER arg2, EIF_INTEGER_32 arg3)
{memmove((void *) arg1, (const void *) arg2, (size_t) arg3);
	
}
/* {POINTER_REF}.c_free */
RT_IL void __stdcall F672_5910 (EIF_POINTER arg1)
{free((void *) arg1);
	
}
/* {POINTER_REF}.c_realloc */
RT_IL EIF_POINTER __stdcall F672_5909 (EIF_POINTER arg1, EIF_INTEGER_32 arg2)
{
	EIF_POINTER Result;Result = (EIF_POINTER) realloc((void *) arg1, (size_t) arg2);
	
	return Result;
}
/* {POINTER_REF}.c_memcmp */
RT_IL EIF_INTEGER_32 __stdcall F672_5906 (EIF_POINTER arg1, EIF_POINTER arg2, EIF_INTEGER_32 arg3)
{
	EIF_INTEGER_32 Result;Result = (EIF_INTEGER_32) memcmp((void *) arg1, (void *) arg2, (size_t) arg3);
	
	return Result;
}

/* {COM_FAILURE}.c_strlen */
RT_IL EIF_INTEGER_32 __stdcall F697_6544 (EIF_POINTER arg1)
{
	EIF_INTEGER_32 Result;
	Result = inline_F697_6544 ((EIF_POINTER) arg1);
	return Result;
}
/* {COM_FAILURE}.ccom_hresult_code */
RT_IL EIF_INTEGER_32 __stdcall F697_6541 (EIF_INTEGER_32 arg1)
{
	EIF_INTEGER_32 Result;
	Result = inline_F697_6541 ((EIF_INTEGER_32) arg1);
	return Result;
}
/* {COM_FAILURE}.cwin_local_free */
RT_IL void __stdcall F697_6546 (EIF_POINTER arg1)
{
	inline_F697_6546 ((EIF_POINTER) arg1);
}
/* {COM_FAILURE}.cwin_error_text */
RT_IL EIF_POINTER __stdcall F697_6543 (EIF_INTEGER_32 arg1)
{
	EIF_POINTER Result;
	Result = inline_F697_6543 ((EIF_INTEGER_32) arg1);
	return Result;
}
/* {COM_FAILURE}.ccom_hresult */
RT_IL EIF_INTEGER_32 __stdcall F697_6540 (EIF_POINTER arg1)
{
	EIF_INTEGER_32 Result;
	Result = inline_F697_6540 ((EIF_POINTER) arg1);
	return Result;
}
/* {COM_FAILURE}.ccom_hresult_facility */
RT_IL EIF_INTEGER_32 __stdcall F697_6542 (EIF_INTEGER_32 arg1)
{
	EIF_INTEGER_32 Result;
	Result = inline_F697_6542 ((EIF_INTEGER_32) arg1);
	return Result;
}
/* {COM_FAILURE}.character_size */
RT_IL EIF_INTEGER_32 __stdcall F697_6545 (void)
{
	EIF_INTEGER_32 Result;
	Result = inline_F697_6545 ();
	return Result;
}


#ifdef __cplusplus
}
#endif
