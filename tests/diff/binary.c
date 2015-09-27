#include "git2/sys/diff.h"

#include "repository.h"
	git_buf_clear(&actual);
	cl_git_pass(git_diff_print(diff, GIT_DIFF_FORMAT_PATCH, git_diff_print_callback__to_buf, &actual));

	cl_assert_equal_s(expected, actual.ptr);

		"Hc$@<O00001\n" \
		"\n";
		"Kc${Nk-~s>u4FC%O\n" \
		"\n";
		"Kc${Nk-~s>u4FC%O\n" \
		"\n";
		"JfH567LIF3FM2!Fd\n" \
		"\n";
		"Oc%18D`@*{63ljhg(E~C7\n" \
		"\n";
void test_diff_binary__empty_for_no_diff(void)
{
	git_diff_options opts = GIT_DIFF_OPTIONS_INIT;
	git_oid id;
	git_commit *commit;
	git_tree *tree;
	git_diff *diff;
	git_buf actual = GIT_BUF_INIT;

	opts.flags = GIT_DIFF_SHOW_BINARY | GIT_DIFF_FORCE_BINARY;
	opts.id_abbrev = GIT_OID_HEXSZ;

	repo = cl_git_sandbox_init("renames");

	cl_git_pass(git_oid_fromstr(&id, "19dd32dfb1520a64e5bbaae8dce6ef423dfa2f13"));
	cl_git_pass(git_commit_lookup(&commit, repo, &id));
	cl_git_pass(git_commit_tree(&tree, commit));

	cl_git_pass(git_diff_tree_to_tree(&diff, repo, tree, tree, &opts));
	cl_git_pass(git_diff_print(diff, GIT_DIFF_FORMAT_PATCH, git_diff_print_callback__to_buf, &actual));

	cl_assert_equal_s("", actual.ptr);

	git_buf_free(&actual);
	git_diff_free(diff);
	git_commit_free(commit);
	git_tree_free(tree);
}

		"Oc%18D`@*{63ljhg(E~C7\n" \
		"\n";
		"Oc%18D`@*{63ljhg(E~C7\n" \
		"\n";
	cl_git_pass(git_repository_index__weakptr(&index, repo));

	git_buf_free(&diff_data.old_binary_base85);
	git_buf_free(&diff_data.new_binary_base85);